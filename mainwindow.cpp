#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //defaults
    ui->exposure_spin->setValue(3.0);
    ui->red_threshold_spin->setValue(0.2126);
    ui->green_threshold_spin->setValue(0.7152);
    ui->blue_threshold_spin->setValue(0.0722); 
	ui->softening_factor_spin->setValue(.01);

    //init conditions combo box
    ui->initial_conditions_box->addItem("Galaxy" , 0);
    ui->initial_conditions_box->addItem("Dual Galaxy" , 1 );
    ui->initial_conditions_box->addItem("Sphere" , 2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_apply_bloom_check_clicked(bool checked)
{
    ui->gl_widget->SetUseBloom( checked );
}

void MainWindow::on_start_button_clicked()
{
	ui->gl_widget->StartAnimation();
}

void MainWindow::on_pause_button_clicked()
{
	ui->gl_widget->PauseAnimation();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

	switch (event->key())
	{
		case Qt::Key_S:
		{
			ui->gl_widget->MoveCamera(CAMERA_MOVE::BACK);
			break;
		}
		case Qt::Key_W:
		{
			ui->gl_widget->MoveCamera(CAMERA_MOVE::FORWARD);
			break;
		}
		case Qt::Key_A:
		{
			ui->gl_widget->MoveCamera(CAMERA_MOVE::LEFT);
			break;
		}
		case Qt::Key_D:
		{
			ui->gl_widget->MoveCamera(CAMERA_MOVE::RIGHT);
			break;
		}
		default:
		{
			QMainWindow::keyPressEvent(event);
			break;
		}
	}

}

void MainWindow::on_gravitational_constant_spin_valueChanged(const QString &arg1)
{
    float grav = arg1.toFloat();
    ui->gl_widget->SetGravitationalConstant( grav );
}

void MainWindow::on_gravitational_constant_spin_valueChanged(double arg1)
{
    float grav = static_cast<float> ( arg1 );
    ui->gl_widget->SetGravitationalConstant( grav );
}

void MainWindow::on_softening_factor_spin_valueChanged(double arg1)
{
    float soft = static_cast<float> ( arg1 );
	ui->gl_widget->SetSofteningFactor(soft);
}

void MainWindow::on_softening_factor_spin_valueChanged(const QString &arg1)
{
    float soft = arg1.toFloat();
	ui->gl_widget->SetSofteningFactor(soft);
}

void MainWindow::on_exposure_spin_valueChanged(double arg1)
{
	float exposure = static_cast<float>(arg1);
    ui->gl_widget->SetBloomExposure( exposure );
}

void MainWindow::on_exposure_spin_valueChanged(const QString & arg1)
{
	float exposure = arg1.toFloat();
	ui->gl_widget->SetBloomExposure( exposure );
}

void MainWindow::on_red_threshold_spin_valueChanged(const QString &arg1)
{
    float r_threshold = arg1.toFloat();
    ui->gl_widget->SetBloomRedThreshold( r_threshold );
}

void MainWindow::on_red_threshold_spin_valueChanged(double arg1)
{
   float r_threshold = static_cast<float>(arg1);
   ui->gl_widget->SetBloomRedThreshold( r_threshold );
}

void MainWindow::on_green_threshold_spin_valueChanged(const QString &arg1)
{
	float g_threshold = arg1.toFloat();
	ui->gl_widget->SetBloomRedThreshold(g_threshold);
}

void MainWindow::on_green_threshold_spin_valueChanged(double arg1)
{
	float g_threshold = static_cast<float>( arg1);
	ui->gl_widget->SetBloomRedThreshold(g_threshold);
}

void MainWindow::on_blue_threshold_spin_valueChanged(const QString &arg1)
{
	float b_threshold = arg1.toFloat();
	ui->gl_widget->SetBloomRedThreshold(b_threshold);
}

void MainWindow::on_blue_threshold_spin_valueChanged(double arg1)
{
	
	float b_threshold = static_cast<float>(arg1);
	ui->gl_widget->SetBloomRedThreshold(b_threshold);
}

void MainWindow::on_particle_size_spin_valueChanged(const QString &arg1)
{
	float size = arg1.toFloat();
	ui->gl_widget->SetParticleSize(size);
}

void MainWindow::on_particle_size_spin_valueChanged(double arg1)
{
	float size = static_cast<float>(arg1);
	ui->gl_widget->SetParticleSize(size);
}

void MainWindow::on_initial_conditions_box_activated(int index)
{
	unsigned condition = ui->initial_conditions_box->currentData().toUInt();
	ui->gl_widget->InitParticles(condition);
}


void MainWindow::on_stop_button_clicked()
{
    ui->gl_widget->PauseAnimation();
    unsigned condition = ui->initial_conditions_box->currentData().toUInt();
    ui->gl_widget->InitParticles(condition);
}
