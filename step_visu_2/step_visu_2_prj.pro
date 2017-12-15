TEMPLATE = app
TARGET = step_visu_2_prj
DESTDIR = ../Linux/Debug
QT += core opengl widgets gui
CONFIG += debug console
QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -Wpedantic
DEFINES += QT_DLL QT_WIDGETS_LIB QT_OPENGL_LIB
INCLUDEPATH += ./GeneratedFiles \
               . \
               ./graphics \
               ./GeneratedFiles/Debug \
               $(EXTSOFT)/glew-1.12.0/include/GL \
               $(EXTSOFT)/glm
LIBS += -lGL \
        -lGLU \
        -lGLEW
DEPENDPATH += .
OBJECTS_DIR += debug
MOC_DIR += ./GeneratedFiles/debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(step_visu_2_prj.pri)
