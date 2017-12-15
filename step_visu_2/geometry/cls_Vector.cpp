#include "cls_Vector.h"

#include <iostream>

nspGeometry::cls_Vector::cls_Vector() :
   cls_GeometryEntity(etnVECTOR),
   mDirection(nullptr),
   mMagnitude(0.)
{
}

nspGeometry::cls_Vector::cls_Vector(cls_Direction* p_direction, double p_magnitude) :
   cls_GeometryEntity(etnVECTOR),
   mDirection(p_direction),
   mMagnitude(p_magnitude)
{
}

nspGeometry::cls_Vector::~cls_Vector()
{
}

void nspGeometry::cls_Vector::Dump() const
{
   std::cout << "[VECTOR] " << std::endl;
}

void nspGeometry::cls_Vector::SetDirection(cls_Direction* p_direction)
{
   mDirection = p_direction;
}

void nspGeometry::cls_Vector::SetMagnitude(double p_magnitude)
{
   mMagnitude = p_magnitude;
}
