#include "cls_Vector.h"

// Qt
#include <QDebug>

// Project
#include "cls_Direction.h"

namespace nspGeometry
{

cls_Vector::cls_Vector() :
   cls_GeometryEntity(etnVECTOR),
   mDirection(nullptr),
   mMagnitude(0.)
{
}

cls_Vector::cls_Vector(cls_Direction* p_direction, double p_magnitude) :
   cls_GeometryEntity(etnVECTOR),
   mDirection(p_direction),
   mMagnitude(p_magnitude)
{
}

cls_Vector::~cls_Vector()
{
}

void cls_Vector::Dump(void) const
{
   qDebug().nospace() << "[VECTOR] ";
}

void cls_Vector::SetDirection(cls_Direction* p_direction)
{
   mDirection = p_direction;
}

void cls_Vector::SetMagnitude(double p_magnitude)
{
   mMagnitude = p_magnitude;
}

} // End of namespace nspGeometry
