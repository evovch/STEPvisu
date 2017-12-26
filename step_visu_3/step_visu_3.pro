#-------------------------------------------------
#
# Project created by QtCreator 2017-12-26T13:55:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = step_visu_3
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

include(parsing.pri)

include(shaders.pri)

LIBS += -lGLEW

QMAKE_CXXFLAGS += -Wall -Wextra -Wpedantic

INCLUDEPATH += ../step_visu_2/

SOURCES += main.cpp \
           cls_mainwindow.cpp \
           cls_displaymodel.cpp \
           cls_mycamera.cpp \
           cls_myglwidget.cpp \
           support.cpp \
           ../step_visu_2/stepentities/cls_CEI.cpp \
           ../step_visu_2/stepentities/cls_EI.cpp \
           ../step_visu_2/stepentities/cls_EIlist.cpp \
           ../step_visu_2/stepentities/cls_Parameter.cpp \
           ../step_visu_2/stepentities/cls_ParameterTreeElement.cpp \
           ../step_visu_2/stepentities/cls_SEI.cpp \
           ../step_visu_2/stepentities/cls_STEPfile.cpp \
           ../step_visu_2/geometry/cls_Axis2_placement_3d.cpp \
           ../step_visu_2/geometry/cls_Cartesian_point.cpp \
           ../step_visu_2/geometry/cls_Circle.cpp \
           ../step_visu_2/geometry/cls_Direction.cpp \
           ../step_visu_2/geometry/cls_GeometryEntity.cpp \
           ../step_visu_2/geometry/cls_Line.cpp \
           ../step_visu_2/geometry/cls_Placement.cpp \
           ../step_visu_2/geometry/cls_Point.cpp \
           ../step_visu_2/geometry/cls_Vector.cpp \
           ../step_visu_2/cls_GLTimer.cpp \
           ../step_visu_2/representations/cls_SolidRepresentation.cpp \
           ../step_visu_2/representations/cls_SolidRepresentation_point.cpp \
           ../step_visu_2/representations/cls_SolidRepresentation_wire.cpp

HEADERS += cls_mainwindow.h \
           cls_displaymodel.h \
           cls_mycamera.h \
           cls_myglwidget.h \
           support.h \
           ../step_visu_2/stepentities/cls_CEI.h \
           ../step_visu_2/stepentities/cls_EI.h \
           ../step_visu_2/stepentities/cls_EIlist.h \
           ../step_visu_2/stepentities/cls_Parameter.h \
           ../step_visu_2/stepentities/cls_ParameterTreeElement.h \
           ../step_visu_2/stepentities/cls_SEI.h \
           ../step_visu_2/stepentities/cls_STEPfile.h \
           ../step_visu_2/geometry/cls_Axis2_placement_3d.h \
           ../step_visu_2/geometry/cls_Cartesian_point.h \
           ../step_visu_2/geometry/cls_Circle.h \
           ../step_visu_2/geometry/cls_Direction.h \
           ../step_visu_2/geometry/cls_GeometryEntity.h \
           ../step_visu_2/geometry/cls_Line.h \
           ../step_visu_2/geometry/cls_Placement.h \
           ../step_visu_2/geometry/cls_Point.h \
           ../step_visu_2/geometry/cls_Vector.h \
           ../step_visu_2/cls_GLTimer.h \
           ../step_visu_2/representations/cls_SolidRepresentation.h \
           ../step_visu_2/representations/cls_SolidRepresentation_point.h \
           ../step_visu_2/representations/cls_SolidRepresentation_wire.h

FORMS   += cls_mainwindow.ui

DISTFILES += \
    parsing.pri
