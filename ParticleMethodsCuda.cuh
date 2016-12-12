#ifndef PARTICLE_METHODS_CUDA_H
#define PARTICLE_METHODS_CUDA_H

#include "ParticleDefinitions.h"

#include <string>
#include <vector>

#include <cuda.h>
#define GLM_FORCE_CUDA
#include <glm/glm.hpp>

//Particle struct for simulation an graphics
struct Particle
{
	Particle()
		: position(0.0f, 0.0f, 0.0f)
		, velocity(0.0f, 0.0f, 0.0f)
		, weight(1.0f)
	{}
	glm::vec3 position;
	float weight;
	glm::vec3 velocity;
};


class ParticleCudaOperations
{
public:
	~ParticleCudaOperations();
	//asumming vbo allocation happened before this fnuction was called
	void InitParticles( unsigned part_vbo, unsigned num_particles, unsigned initialization_condition );

	 /*
	 * updates particle position bases on interactions with the n-1 other bodies
	 *  see http://http.developer.nvidia.com/GPUGems3/gpugems3_ch31.html for details
	 *
	 * We use a softening factor to prevent force reaching infinity when two bodys are in close proximity to each other
	 */
	void UpdateParticles( unsigned part_vbo, unsigned num_particles, float delta_time,
		float gravitational_constant, float softening_factor );
};

#endif

