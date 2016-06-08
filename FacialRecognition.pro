#-------------------------------------------------
#
# Project created by QtCreator 2016-06-08T09:03:57
#
#-------------------------------------------------

QT       += core gui

TARGET = FacialRecognition
TEMPLATE = app

PROJECT_BASE_DIRECTORY = /home/standby/doorentry

#
# Setup paths according to target spec.
#
linux-mxc-g++ {

    # extract the boardtype from the toolchain.make file replaced the need for the project to have this.
    BOARDTYPE=$$system("grep '^BUILD_PROFILE' $$PROJECT_BASE_DIRECTORY/toolchain.make | awk -F'=' '{print $2}'")
    DEFINES += $$BOARDTYPE
    message("Arm Build: $$BOARDTYPE")

    # Allow application source code to conditionally compile for target or development host PC
    DEFINES += $$BOARDTYPE

    contains ( DEFINES, IMX6 ) {
        # add cflag
        QMAKE_CXXFLAGS+=-Wno-psabi
    }

    MYPREFIX = $$PROJECT_BASE_DIRECTORY/ltib/rootfs

    INCLUDEPATH += /home/standby/doorentry/apps/opencv/install

    LIBS +=  -L/home/standby/doorentry/apps/opencv/install/lib -lopencv_core -lopencv_imgproc -lopencv_video -lopencv_highgui -lopencv_objdetect -lopencv_contrib
}


linux-g++-|linux-g++-64 {
    DEFINES += PCBUILD
    message("x86 Build")

    INCLUDEPATH += /home/standby/opencv/opencv-2.4.10/build

    #LIBS += -L/usr/local/lib/ -lopencv_core -lopencv_imgproc -lopencv_video -lopencv_highgui -lopencv_objdetect -lopencv_contrib
    LIBS += -L/home/standby/opencv/opencv-2.4.10/build/lib -lopencv_core -lopencv_imgproc -lopencv_video -lopencv_highgui -lopencv_objdetect -lopencv_contrib

}

SOURCES += main.cpp\
    captureimages.cpp \
    detectobject.cpp \
    recognition.cpp

HEADERS  += \
    captureimages.h \
    detectobject.h \
    recognition.h

FORMS    += mainwindow.ui
