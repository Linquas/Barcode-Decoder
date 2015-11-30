#-------------------------------------------------
#
# Project created by QtCreator 2015-09-16T21:51:20
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    barcode_locator.cpp \
    camera.cpp \
    decode.cpp \
    process.cpp \
    mattoqimage.cpp \
    display.cpp

HEADERS  += mainwindow.h \
    barcode_locator.h \
    camera.h \
    decode.h \
    process.h \
    mattoqimage.h \
    display.h

FORMS    += mainwindow.ui \
    display.ui

DISTFILES += \
    GUI4.pro.user

QMAKE_LFLAGS += -fopenmp
QMAKE_CXXFLAGS += -fopenmp
LIBS += -fopenmp

QMAKE_CXXFLAGS_RELEASE -= -O
QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE *= -O3

linux-g++-32 {
    message(Linux)
    LIBS += `pkg-config opencv --libs`
}

!linux-g++-32 {
    message(ARM-Linux)
    #CONFIG += release

    INCLUDEPATH += /usr/include
    LIBS += -L/usr/lib
    LIBS += -lopencv_core
    LIBS += -lopencv_imgproc
    LIBS += -lopencv_highgui
#    LIBS += -lopencv_ml
#    LIBS += -lopencv_video
#    LIBS += -lopencv_features2d
#    LIBS += -lopencv_calib3d
#    LIBS += -lopencv_objdetect
#    LIBS += -lopencv_contrib
#    LIBS += -lopencv_legacy
#    LIBS += -lopencv_flann
#    LIBS += -lpthread
#    LIBS += -lcrypto
#    LIBS += -lEGL
#    LIBS += -lGLESv2
}
