#include "nbodyparticles.h"
#include <QOpenGLExtraFunctions>
#include <algorithm>
#include <iostream>
NBodyParticles::NBodyParticles()
{

}

void NBodyParticles::IntializeGL()
{
    initializeOpenGLFunctions();

	//shader and resource managment
    particle_texture_.reset( new QOpenGLTexture(
       QImage( "C:/Users/Jack/Desktop/NBodySim/Textures/glow_grad.png") ) );

    prog_.addShaderFromSourceFile(QOpenGLShader::Vertex ,
        "C:/Users/Jack/Desktop/NBodySim/Shaders/particle.vert" ) ;
    prog_.addShaderFromSourceFile(QOpenGLShader::Geometry ,
        "C:/Users/Jack/Desktop/NBodySim/Shaders/particle.geom" ) ;
    prog_.addShaderFromSourceFile(QOpenGLShader::Fragment ,
        "C:/Users/Jack/Desktop/NBodySim/Shaders/particle.frag" ) ;
    prog_.link();

    glGenVertexArrays( 1, &particle_vao_ );
    glGenBuffers( 1, &particle_vbo_ );

	// initialize buffer and vbo objects
	glBindBuffer(GL_ARRAY_BUFFER, particle_vbo_);
	glBufferData(GL_ARRAY_BUFFER, num_particles_ * sizeof(Particle),
		0, GL_STREAM_DRAW);

	glBindVertexArray(particle_vao_);

    //Position
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), (GLvoid*)0);
  
	//weight
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, sizeof(Particle)
                             , (GLvoid*)offsetof( Particle, weight ) );
	//velocity
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), (GLvoid*)offsetof(Particle, velocity) );
	
    glBindVertexArray(0);
}

void NBodyParticles::InitParticles(unsigned condition)
{
	cuda_helper_.InitParticles(particle_vbo_, num_particles_, condition);
}

void NBodyParticles::DrawParticles(const QMatrix4x4 &view, const QMatrix4x4 &projection ,
     const QVector3D& bloom_color_threshold,  float particle_size )
{
	prog_.bind();

    int viewLoc =  glGetUniformLocation( prog_.programId(), "view" );
    int projLoc =  glGetUniformLocation( prog_.programId(), "projection" );
    int sizeLoc =  glGetUniformLocation( prog_.programId(), "size" );
    int texLoc = glGetUniformLocation(prog_.programId(), "tex0" );
    int bloom_exposure_loc = glGetUniformLocation(prog_.programId(), "tex0" );
	int color_loc = glGetUniformLocation(prog_.programId(), "particle_color");
   
	glUniformMatrix4fv( viewLoc, 1, GL_FALSE, view.data() );
    glUniformMatrix4fv( projLoc, 1, GL_FALSE, projection.data() );
    glUniform3f(bloom_exposure_loc , bloom_color_threshold.x() , bloom_color_threshold.y(),
        bloom_color_threshold.z() );
	glUniform3f(color_loc, 1.0f, 1.0f, 1.0f);
    glUniform1f( sizeLoc , particle_size );
    glUniform1i( texLoc, 0 );
    particle_texture_->bind( 0 );

    glBindVertexArray(particle_vao_);
    glDrawArrays(GL_POINTS, 0 , num_particles_ );
    glBindVertexArray(0);
    prog_.release();
}

void NBodyParticles::UpdateParticles( const QVector3D& camera_pos, float gravity_constant, float softening_factor  )
{
	cuda_helper_.UpdateParticles(particle_vbo_, num_particles_, 1.0f / 16.66f , gravity_constant, softening_factor );

}
