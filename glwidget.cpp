#include "glwidget.h"

#include <qtimer.h>
#include <iostream>

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{

}

GLWidget::~GLWidget()
{
	glDeleteBuffers(1, &quad_vbo_);
}

void GLWidget::SetUseBloom(bool bloom)
{
    bloom_ = bloom;
    update();
}

void GLWidget::SetBloomExposure(float exposure)
{
    exposure_ = exposure;
    update();
}

void GLWidget::SetBloomRedThreshold(float threshold)
{
    bloom_color_threshold_.setX(threshold);
    update();
}

void GLWidget::SetBloomBlueThreshold(float threshold)
{
    bloom_color_threshold_.setY(threshold);
    update();
}

void GLWidget::SetBloomGreenThreshold(float threshold)
{
    bloom_color_threshold_.setZ(threshold);
    update();
}

void GLWidget::SetGravitationalConstant(float grav)
{
	gravitational_constant_ = grav;
	update();
}

void GLWidget::SetSofteningFactor(float soft)
{
	softening_factor_ = soft;
	update();
}

void GLWidget::SetParticleSize(float size)
{
	particle_size_ = size;
	update();
}

void GLWidget::StartAnimation()
{
	running_ = true;
	update();
}

void GLWidget::PauseAnimation()
{
	running_ = false;
	update();
}

void GLWidget::InitParticles(unsigned condition)
{
	if (running_)
		running_ = false;
	particle_sim_.InitParticles(condition);
}

void GLWidget::MoveCamera(CAMERA_MOVE move)
{
	camera_rig_.MoveCamera(move);
	update();
}

void GLWidget::mousePressEvent ( QMouseEvent * event )
{
    if( event->button()==Qt::RightButton)
        right_mouse_pressed_ = true;
    else
        left_mouse_pressed_ = true;
    mouse_pos_ = QVector2D( event->pos() );
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    QVector2D new_pos( event->pos() );
    mouse_delta_ = new_pos- mouse_pos_ ;
    mouse_pos_ = new_pos;

    if( left_mouse_pressed_ )
        camera_rig_.PanTilt( mouse_delta_ );
    else if (right_mouse_pressed_ )
        camera_rig_.PanTiltAboutViewCenter( mouse_delta_ );

}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if( event->button()==Qt::RightButton)
        right_mouse_pressed_ = false;
    else
        left_mouse_pressed_ = false;
}

void GLWidget::BlurPostProcess_()
{
    //blur
    bool horizontal = true, first_iteration = true;
    unsigned amount = 10;
    blur_prog_.bind();

    for (unsigned i = 0; i < amount; i++)
    {
        blur_ping_pong_.at( static_cast<std::size_t> ( horizontal ) )->bind();
        glUniform1i(glGetUniformLocation( blur_prog_.programId(),
           "horizontal"), horizontal);
        glBindTexture(GL_TEXTURE_2D, first_iteration ? hdr_fbo_->textures().at(1) :
           blur_ping_pong_.at( static_cast<std::size_t> ( !horizontal ) )->texture() );  
        RenderQuad_();
        horizontal = !horizontal;
        if (first_iteration)
          first_iteration = false;
        blur_ping_pong_.at( static_cast<std::size_t> ( horizontal ) )->release();
    }
   
    blur_prog_.release();
}

void GLWidget::BloomPostProcess_()
{
    bloom_prog_.bind();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, hdr_fbo_->textures().at(0) );
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D,
    blur_ping_pong_.at(1)->texture() );
    glUniform1i(glGetUniformLocation(bloom_prog_.programId(), "bloom"), bloom_);
    glUniform1f(glGetUniformLocation(bloom_prog_.programId(), "exposure"), exposure_);
    RenderQuad_();
    bloom_prog_.release();
}

void GLWidget::RenderQuad_()
{
    glBindVertexArray( quad_vao_ );
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glBindVertexArray(0);
}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    camera_.setPosition( { 0 , 0 , 40 } );
    camera_.setViewCenter( { 0 , 0 , 0 } );
    camera_rig_.SetCamera( &camera_ );

    blur_prog_.addShaderFromSourceFile(QOpenGLShader::Vertex ,
        "C:/Users/Jack/Desktop/NBodySim/Shaders/blur.vert" );
    blur_prog_.addShaderFromSourceFile(QOpenGLShader::Fragment ,
        "C:/Users/Jack/Desktop/NBodySim/Shaders/blur.frag" );

    blur_prog_.link();

    bloom_prog_.addShaderFromSourceFile(QOpenGLShader::Vertex ,
        "C:/Users/Jack/Desktop/NBodySim/Shaders/bloom.vert" );
    bloom_prog_.addShaderFromSourceFile(QOpenGLShader::Fragment ,
        "C:/Users/Jack/Desktop/NBodySim/Shaders/bloom.frag" );

    bloom_prog_.link();

    particle_sim_.IntializeGL();

	particle_sim_.InitParticles(initial_condition_);

  //quads for post processing effects
  GLfloat quadVertices[] = {
          // Positions        // Texture Coords
          -1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
          -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
          1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
          1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
  };

  glGenVertexArrays( 1, &quad_vao_ );
  glGenBuffers( 1, &quad_vbo_ );
  glBindVertexArray( quad_vao_ );
  glBindBuffer(GL_ARRAY_BUFFER, quad_vbo_ );
  glBufferData(GL_ARRAY_BUFFER, sizeof( quadVertices ), &quadVertices, GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  //position
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
  glEnableVertexAttribArray(1);
  //tex coords
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
  glBindVertexArray( 0 );
}

void GLWidget::paintGL()
{
	if ( running_ )
		particle_sim_.UpdateParticles( camera_.position(), gravitational_constant_, softening_factor_ );

	//render into hdr fbo
	hdr_fbo_->bind();
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(false);
	glEnable(GL_BLEND);
	//  and set the blend function to result = 1*source + 1*destination for particle alpha blending
	glBlendFunc(GL_ONE, GL_ONE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
	GLenum bufs[] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1 };
    
	glDrawBuffers(2, bufs);
    particle_sim_.DrawParticles( camera_.viewMatrix() , camera_.projectionMatrix()
        , bloom_color_threshold_, particle_size_ );
    hdr_fbo_->release();

	glDisable(GL_BLEND);

	BlurPostProcess_();
    BloomPostProcess_();
    update();
}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
    camera_.lens()->setPerspectiveProjection( 45.0f, float( width ) / float( height )
               , .001, 100.0f );

    hdr_fbo_.reset( new QOpenGLFramebufferObject( width , height ) );
    hdr_fbo_->addColorAttachment(width, height );

	QOpenGLFramebufferObjectFormat format;
	format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
	format.setMipmap(true);
	format.setSamples(4);
	format.setTextureTarget(GL_TEXTURE_2D);
	format.setInternalTextureFormat(GL_RGBA32F_ARB);

	msaa_fbo_.reset(new QOpenGLFramebufferObject( width, height , format ) );

    blur_ping_pong_.clear();
    blur_ping_pong_.push_back( std::make_unique<QOpenGLFramebufferObject>( width , height ) );
    blur_ping_pong_.push_back( std::make_unique<QOpenGLFramebufferObject>( width , height )  );
}
