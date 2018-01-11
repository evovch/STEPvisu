#include "cls_Circle.h"

// Qt
#include <QDebug>

namespace nspGeometry {

cls_Circle::cls_Circle() :
   cls_GeometryEntity(etnCIRCLE),
   mPlacement(nullptr),
   mRadius(0.)
{
}

cls_Circle::cls_Circle(double p_radius) :
   cls_GeometryEntity(etnCIRCLE),
   mPlacement(nullptr),
   mRadius(p_radius)
{
}

cls_Circle::cls_Circle(cls_Axis2_placement_3d* p_placement, double p_radius) :
   cls_GeometryEntity(etnCIRCLE),
   mPlacement(p_placement),
   mRadius(p_radius)
{
}

cls_Circle::~cls_Circle()
{
}

void cls_Circle::Dump(void) const
{
   qDebug().nospace() << "[CIRCLE] ";
}

} // End of namespace nspGeometry
