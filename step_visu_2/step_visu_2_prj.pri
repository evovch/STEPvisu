HEADERS += ./brepentities/cls_BREPentity.h \
           ./brepentities/cls_Point.h \
           ./graphics/cls_Camera.h \
           ./graphics/cls_GraphicsWidget.h \
           ./representations/cls_SolidRepresentation.h \
           ./representations/cls_SolidRepresentation_point.h \
           ./representations/cls_SolidRepresentation_wire.h \
           ./stepentities/cls_CEI.h \
           ./stepentities/cls_EI.h \
           ./stepentities/cls_EIlist.h \
           ./stepentities/cls_Parameter.h \
           ./stepentities/cls_ParameterTreeElement.h \
           ./stepentities/cls_SEI.h \
           ./stepentities/cls_STEPfile.h \
           ./step_visu_2_prj.h
SOURCES += ./brepentities/cls_BREPentity.cpp \
           ./brepentities/cls_Point.cpp \
           ./graphics/cls_Camera.cpp \
           ./graphics/cls_GraphicsWidget.cpp \
           ./main.cpp \
           ./parsing/wrapper-bison.cpp \
           ./parsing/wrapper-flex.cpp \
           ./representations/cls_SolidRepresentation.cpp \
           ./representations/cls_SolidRepresentation_point.cpp \
           ./representations/cls_SolidRepresentation_wire.cpp \
           ./stepentities/cls_CEI.cpp \
           ./stepentities/cls_EI.cpp \
           ./stepentities/cls_EIlist.cpp \
           ./stepentities/cls_Parameter.cpp \
           ./stepentities/cls_ParameterTreeElement.cpp \
           ./stepentities/cls_SEI.cpp \
           ./stepentities/cls_STEPfile.cpp \
           ./step_visu_2_prj.cpp
FORMS += ./step_visu_2_prj.ui
RESOURCES += step_visu_2_prj.qrc
