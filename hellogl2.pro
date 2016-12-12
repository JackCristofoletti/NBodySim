QT           += widgets core gui opengl 3dcore 3drender 3dinput 3dextras

HEADERS       = glwidget.h \
                mainwindow.h \
                nbodyparticles.h \
    camerarig.h

SOURCES       = glwidget.cpp \
                main.cpp \
                mainwindow.cpp \
                nbodyparticles.cpp \
    camerarig.cpp

LIBS += opengl32.lib

TARGET = NBodySim
TEMPLATE = app

FORMS += \
    mainwindow.ui

DISTFILES += \
    Shaders/particle.frag \
    Shaders/particle.vert \
    Shaders/particle.geom \
    Shaders/blur.frag \
    Shaders/bloom.vert \
    Shaders/blur.vert \
    Shaders/bloom.frag



