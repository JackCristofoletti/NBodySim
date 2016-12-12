#ifndef CAMERARIG_H
#define CAMERARIG_H

#include <QCamera>
#include <QVector2D>

enum CAMERA_MOVE
{
	LEFT, RIGHT, FORWARD, BACK
};

class CameraRig
{
public:
    CameraRig() = default;
    CameraRig( Qt3DRender::QCamera *camera , double mouse_sensitvity = .05 );

    //Setters
    void SetCamera(  Qt3DRender::QCamera *camera ) { camera_ = camera; }
    void SetMouseSensitvity( double mouse_sensitvity ) { mouse_sensitvity_ = mouse_sensitvity; }

    // Pan and tilt the camera by incoming mouse delta
    void PanTilt( const QVector2D& delta);
    void PanTiltAboutViewCenter( const QVector2D& delta);

	//Moving forward/back left right
	void MoveCamera( CAMERA_MOVE move_dir );

private:
    double mouse_sensitvity_ = .05;
    double strife_sensitivty_ = 5;
    Qt3DRender::QCamera  *camera_ = nullptr;
};

#endif // CAMERARIG_H
