#include <QApplication>
#include <QDesktopWidget>
#include <QSurfaceFormat>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QSurfaceFormat format;
	format.setDepthBufferSize(24);
	format.setStencilBufferSize(8);
	format.setSwapInterval(1);
	format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
	QSurfaceFormat::setDefaultFormat(format);

    QApplication app(argc, argv);

    MainWindow window;
    window.show();
    return app.exec();
}
