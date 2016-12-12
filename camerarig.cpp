#include "camerarig.h"
#include "iostream"


CameraRig::CameraRig(Qt3DRender::QCamera *camera, double mouse_sensitvity)
    : camera_ ( camera )
    , mouse_sensitvity_ ( mouse_sensitvity )
{

}

void CameraRig::PanTilt(const QVector2D &delta)
{
    if( !camera_ )
    {
        std::cout << " No camera objet set" <<std::endl;
        return;
    }

    camera_->pan( delta.x() * mouse_sensitvity_ );
    camera_->tilt( delta.y() * mouse_sensitvity_ );
}

void CameraRig::PanTiltAboutViewCenter(const QVector2D &delta)
{
    camera_->panAboutViewCenter( delta.x() * mouse_sensitvity_ );
    camera_->tiltAboutViewCenter( delta.y() * mouse_sensitvity_ );
}

void CameraRig::MoveCamera(CAMERA_MOVE move_dir)
{
	switch (move_dir)
	{
		case LEFT:
		{
			camera_->translate(QVector3D(-1, 0, 0), Qt3DRender::QCamera::DontTranslateViewCenter);
			break;
		}
		case RIGHT:
		{
			camera_->translate(QVector3D(1, 0, 0) , Qt3DRender::QCamera::DontTranslateViewCenter);
			break;
		}

		case FORWARD:
		{
			camera_->translate(QVector3D(0, 0, 1) , Qt3DRender::QCamera::DontTranslateViewCenter);
			break;
		}

		case BACK:
		{
			camera_->translate(QVector3D(0, 0, -1) , Qt3DRender::QCamera::DontTranslateViewCenter);
			break;
		}
	}
}
