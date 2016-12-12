#ifndef NBODYPARTICLES_H
#define NBODYPARTICLES_H

#include "ParticleDefinitions.h"
#include "ParticleMethodsCuda.cuh"

#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLFunctions_4_5_Compatibility>

#include <vector>
#include <memory>

class NBodyParticles : public QOpenGLFunctions_4_5_Compatibility
{
public:
    NBodyParticles();
    void IntializeGL();
	void InitParticles(unsigned condition);
	void DrawParticles(const QMatrix4x4& view, const QMatrix4x4& projection,
		const QVector3D& bloom_color_threshold, float particle_size);

	void UpdateParticles(const QVector3D& camera_pos, float gravity_constant, float softening_factor  );

private: 

private:
    unsigned particle_vao_;
    unsigned particle_vbo_;
	ParticleCudaOperations cuda_helper_; // cuda wrapper
    QOpenGLShaderProgram prog_;
    std::unique_ptr<QOpenGLTexture> particle_texture_;
	std::unique_ptr<QOpenGLTexture>	flare_texture_;
	QVector3D particle_color;
	unsigned num_particles_ = 10000;
	
};

#endif // NBODYPARTICLES_H
