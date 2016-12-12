#include "ParticleMethodsCuda.cuh"
#include <random>
#include <curand.h>
#include <curand_kernel.h>
#include "qt_windows.h"
#include <cuda_gl_interop.h>
#include <stdio.h>
#include <time.h>

//Computes the gravitational force on body 1 (my_particle) by part 2 (force_particle)
__device__ glm::vec3 BodyBodyInteraction(Particle* my_particle, Particle* force_particle,
	float gravitational_constant, float softening_factor)
{
	glm::vec3 r( force_particle->position - my_particle->position);
	// distSqr = dot(r_ij, r_ij) + EPS^2  [6 FLOPS]
	float distSqr = glm::dot(r, r) + softening_factor;
	// invDistCube =1/distSqr^(3/2) 
	float distSixth = distSqr * distSqr * distSqr;
	float invDistCube = 1.0f / sqrtf(distSixth);
	// s = m_j * invDistCube [1 FLOP]
	float s = force_particle->weight * invDistCube;
	return r * (gravitational_constant * s );
}

__device__ glm::vec3 tile_calculation( Particle* my_particle, float gravitational_constant, float softening_factor)
{
	extern __shared__ Particle shared_particles[];

	if(!my_particle)
		return glm::vec3(0);
	glm::vec3 accel(0);

	for (int i = 0; i < blockDim.x; i++)
		accel += BodyBodyInteraction(my_particle, &shared_particles[i], gravitational_constant, softening_factor);
	return accel;
}

//creates 2 clusters of particles
__global__ void InitParticlesValuesDualGalaxy(Particle* particles, unsigned num_particles)
{
	int tid = threadIdx.x + blockIdx.x * blockDim.x; // handle the data at this index
	curandState state;
	curand_init(1234, tid, 0, &state);
	while (tid < num_particles)
	{
		float random_x_pos = curand_normal(&state);
		float random_y_pos = curand_normal(&state);
		float random_z_pos = curand_normal(&state);

		float weight =  abs( curand_normal(&state) * 10.0f );

		glm::vec3 position_base = tid % 2 == 0 ? glm::vec3(7.5, 2, 0.0) : glm::vec3(-7.5, -2, 0.0);

		particles[tid].position.x = position_base.x + (random_x_pos * 1.6f - .8f);
		particles[tid].position.y = position_base.y + (random_y_pos * 1.6f - .8f);
		particles[tid].position.z = position_base.z + ( (random_z_pos * 1.6f - .8f) + .2f ) * .1;
		particles[tid].weight = ( weight ) ;
		particles[tid].velocity = glm::vec3(0); 
		tid += blockDim.x*gridDim.x;
	}
}

//creates 1 clusters of particles
__global__ void InitParticlesValuesGalaxy(Particle* particles, unsigned num_particles)
{
	int tid = threadIdx.x + blockIdx.x * blockDim.x; // handle the data at this index
	curandState state;
	curand_init(1234, tid, 0, &state);
	while (tid < num_particles)
	{
		float random_x_pos = curand_normal(&state);
		float random_y_pos = curand_normal(&state);
		float random_z_pos = curand_normal(&state);

		float weight = abs(curand_normal(&state) * 10.0f);

		glm::vec3 position_base  = glm::vec3(0, 0, 0.0);

		particles[tid].position.x = position_base.x + (random_x_pos * 3.2f - 1.6f);
		particles[tid].position.y = position_base.y + (random_y_pos * 3.2f - 1.6f);
		particles[tid].position.z = position_base.z + ((random_z_pos * 1.6f - .8f) + .2f) * .1;
		particles[tid].weight = (weight);
		particles[tid].velocity = glm::vec3(0);
		tid += blockDim.x*gridDim.x;
	}
}

//creates cluster of particles randomly scattered in sphere
__global__ void InitParticlesValuesSphere(Particle* particles, unsigned num_particles)
{
	int tid = threadIdx.x + blockIdx.x * blockDim.x; // handle the data at this index
	curandState state;
	curand_init(1234, tid, 0, &state);
	float pi = 3.1415926535897f;
	while ( tid < num_particles )
	{
		//spherical coordinates
		float random_phi =  abs( curand_normal(&state) ) * 2 * pi;
		float random_theta = abs(curand_normal(&state)) * pi;
		const float r = 15.0f;
		float weight = abs(curand_normal(&state) * 10.0f);

		particles[tid].position.x = r * sin(random_theta) *cos(random_phi);
		particles[tid].position.y = r * sin(random_theta) *sin(random_phi);
		particles[tid].position.z = r * cos(random_theta);
		particles[tid].weight = (weight);
		//have velocity point towards the sphere center (0,0,0)
		particles[tid].velocity = glm::normalize(-particles[tid].position) * glm::vec3(3.0f);
		tid += blockDim.x*gridDim.x;
	}
}

__global__ void UpdateVelocity(Particle* particles, unsigned num_particles, float delta_time,
	float gravitational_constant, float softening_factor)
{
	//shared memory for faster read and writes
	extern __shared__ Particle shared_particles[];
	glm::vec3 acceleration(0.0f);
	int tid = threadIdx.x + blockIdx.x * blockDim.x; // handle the data at this index
	Particle *my_particle = 0;
	if ( tid < num_particles )
		 my_particle= &particles[tid];
		
	int i, tile;
	//calculate body forces over  num_particles/ tile_size tiles
	for( i = 0, tile = 0; i < num_particles; i += 256, tile++ )
	{
		int idx = tile * blockDim.x + threadIdx.x;
		
		if (idx < num_particles)
			shared_particles[threadIdx.x] = particles[idx];
		else
			shared_particles[threadIdx.x].weight = 0;
		__syncthreads();
		
		acceleration += tile_calculation( my_particle , gravitational_constant, softening_factor);
		__syncthreads();

	}
	if (tid < num_particles)
		particles[tid].velocity += acceleration * delta_time;
	
}

__global__ void UpdatePosition(Particle* particles, unsigned num_particles, float delta_time )
{
	int tid = threadIdx.x + blockIdx.x * blockDim.x; // handle the data at this index
	// update position based on computed velocity
	while (tid < num_particles)
	{
		particles[tid].position.x += particles[tid].velocity.x * delta_time;
		particles[tid].position.y += particles[tid].velocity.y * delta_time;
		particles[tid].position.z += particles[tid].velocity.z * delta_time;
		tid += blockDim.x*gridDim.x;
	}
}

ParticleCudaOperations::~ParticleCudaOperations() = default;

void ParticleCudaOperations::InitParticles( unsigned part_vbo, unsigned num_particles, unsigned initalization_condition )
{
	void* part_pointer;
	// Map the buffer to CUDA
	cudaGraphicsResource_t resource;
	cudaGraphicsGLRegisterBuffer(&resource, part_vbo, cudaGraphicsRegisterFlagsNone);
	cudaGraphicsMapResources(1, &resource, 0);
	cudaGraphicsResourceGetMappedPointer(&part_pointer, 0, resource);

	switch ( initalization_condition )
	{
		case 0:
		{
			InitParticlesValuesGalaxy << < 256, 256 >> > ((Particle*)part_pointer, num_particles);
			break;
		}
		case 1:
		{
			InitParticlesValuesDualGalaxy << < 256, 256 >> > ((Particle*)part_pointer, num_particles);
			break;
		}

		case 2:
		{
			InitParticlesValuesSphere << < 256, 256 >> > ((Particle*)part_pointer, num_particles);
			break;
		}
		default:
			break;
	}


	cudaDeviceSynchronize();
	cudaGraphicsUnmapResources(1, &resource);
}

void ParticleCudaOperations::UpdateParticles( unsigned part_vbo, unsigned num_particles, float delta_time,
	float gravitational_constant, float softening_factor)
{
	void * part_pointer;
	// Map the buffer to CUDA
	cudaGraphicsResource_t resource;
	cudaGraphicsGLRegisterBuffer(&resource, part_vbo, cudaGraphicsRegisterFlagsNone );
	cudaGraphicsMapResources(1, &resource, 0);
	cudaGraphicsResourceGetMappedPointer(&part_pointer, 0, resource);

	UpdateVelocity << < 256, 256, 256 * sizeof( Particle ) >> > ( (Particle*)part_pointer, num_particles, delta_time , gravitational_constant, softening_factor);
	cudaDeviceSynchronize();
	UpdatePosition << < 256, 256 >> > ( (Particle*)part_pointer, num_particles, .0167);
	cudaDeviceSynchronize();

	cudaGraphicsUnmapResources(1, &resource);
}
