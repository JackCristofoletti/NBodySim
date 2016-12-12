#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "nbodyparticles.h"
#include "camerarig.h"

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFramebufferObject>
#include <QtGui/QKeyEvent>
#include <QOpenGLFunctions_4_5_Compatibility>
#include <Qt3DRender/QCamera>
#include <QMouseEvent>

class GLWidget : public QOpenGLWidget, public QOpenGLFunctions_4_5_Compatibility
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

	// Bloom/Blur control
	void SetUseBloom(bool bloom);
	void SetBloomExposure(float exposure);
	void SetBloomRedThreshold(float threshold);
	void SetBloomBlueThreshold(float threshold);
	void SetBloomGreenThreshold(float threshold);
	
	//Sim Contol
	void SetGravitationalConstant(float grav);
	void SetSofteningFactor(float soft);
	void SetParticleSize(float size);
	void StartAnimation();
	void PauseAnimation();
	void InitParticles(unsigned condition);

	void MoveCamera( CAMERA_MOVE move);

public slots:
    void cleanup() {}

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent ( QMouseEvent * event ) override;
    void mouseMoveEvent( QMouseEvent *event) override;
    void mouseReleaseEvent( QMouseEvent *event ) override;

private:
    void RenderQuad_();
    void BlurPostProcess_();
    void BloomPostProcess_();
	
private:
	//camera control
    Qt3DRender::QCamera camera_;
    CameraRig camera_rig_;

	//simulator 
    NBodyParticles particle_sim_;
	float gravitational_constant_ = .005f;
	float softening_factor_ = .01;
	float particle_size_ = .01;

    //Blur post process shaders and rerources
    std::unique_ptr<QOpenGLFramebufferObject> hdr_fbo_,msaa_fbo_;
    QOpenGLShaderProgram blur_prog_, bloom_prog_;
    std::vector< std::unique_ptr<QOpenGLFramebufferObject> >  blur_ping_pong_;
    unsigned quad_vao_ = 0;
    unsigned quad_vbo_ = 0;

    bool bloom_ = true;  
    float exposure_ = 3.0;
    QVector3D bloom_color_threshold_ = { 0.2126, 0.7152, 0.0722 } ;

    //Gui Control
    bool left_mouse_pressed_ = false;
    bool right_mouse_pressed_ = false;
    QVector2D mouse_pos_ = { 0 , 0 } ;
    QVector2D mouse_delta_ = { 0 , 0 };
	bool running_ = false;
	unsigned initial_condition_ = 0;
};

#endif
