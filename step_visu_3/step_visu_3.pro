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

SOURCES += main.cpp \
           cls_mainwindow.cpp \
           cls_displaymodel.cpp \
           cls_mycamera.cpp \
           cls_myglwidget.cpp \
           support.cpp \
           stepentities/cls_CEI.cpp \
           stepentities/cls_EI.cpp \
           stepentities/cls_EIlist.cpp \
           stepentities/cls_Parameter.cpp \
           stepentities/cls_ParameterTreeElement.cpp \
           stepentities/cls_SEI.cpp \
           stepentities/cls_STEPfile.cpp \
           geometry/cls_Axis2_placement_3d.cpp \
           geometry/cls_Cartesian_point.cpp \
           geometry/cls_Circle.cpp \
           geometry/cls_Direction.cpp \
           geometry/cls_GeometryEntity.cpp \
           geometry/cls_Line.cpp \
           geometry/cls_Placement.cpp \
           geometry/cls_Point.cpp \
           geometry/cls_Vector.cpp \
           representations/cls_SolidRepresentation.cpp \
           representations/cls_SolidRepresentation_point.cpp \
           representations/cls_SolidRepresentation_wire.cpp \
    geometry/cls_Geometric_representation_item.cpp

HEADERS += cls_mainwindow.h \
           cls_displaymodel.h \
           cls_mycamera.h \
           cls_myglwidget.h \
           support.h \
           stepentities/cls_CEI.h \
           stepentities/cls_EI.h \
           stepentities/cls_EIlist.h \
           stepentities/cls_Parameter.h \
           stepentities/cls_ParameterTreeElement.h \
           stepentities/cls_SEI.h \
           stepentities/cls_STEPfile.h \
           geometry/cls_Axis2_placement_3d.h \
           geometry/cls_Cartesian_point.h \
           geometry/cls_Circle.h \
           geometry/cls_Direction.h \
           geometry/cls_GeometryEntity.h \
           geometry/cls_Line.h \
           geometry/cls_Placement.h \
           geometry/cls_Point.h \
           geometry/cls_Vector.h \
           representations/cls_SolidRepresentation.h \
           representations/cls_SolidRepresentation_point.h \
           representations/cls_SolidRepresentation_wire.h \
    geometry/cls_Geometric_representation_item.h

FORMS   += cls_mainwindow.ui

#DISTFILES += parsing.pri
