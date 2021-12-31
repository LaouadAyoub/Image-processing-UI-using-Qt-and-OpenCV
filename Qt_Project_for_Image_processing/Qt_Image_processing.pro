#-------------------------------------------------
#
# Project created by QtCreator 2017-08-27T11:21:12
#
#-------------------------------------------------

QT       += core gui

CONFIG     += debug

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hello_Qt_OpenCV
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH += C:\Users\ayoub\Documents\OpenCV\opencv\build\include

LIBS += C:/Users/ayoub/Documents/OpenCV/opencv/release/bin/libopencv_core454.dll
LIBS += C:/Users/ayoub/Documents/OpenCV/opencv/release/bin/libopencv_highgui454.dll
LIBS += C:/Users/ayoub/Documents/OpenCV/opencv/release/bin/libopencv_imgproc454.dll
LIBS += C:/Users/ayoub/Documents/OpenCV/opencv/release/bin/libopencv_imgcodecs454.dll
LIBS += C:/Users/ayoub/Documents/OpenCV/opencv/release/bin/libopencv_calib3d454.dll

LIBS += C:\Users\ayoub\Documents\OpenCV\opencv\build\x64\vc15\bin\opencv_world454.dll

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

win32: {
include("c:/Users/ayoub/Documents/OpenCV/opencv/build/opencv.pri.txt")
}
