#include "cls_Direction.h"

#include <iostream>

nspGeometry::cls_Direction::cls_Direction() :
   cls_GeometryEntity(etnDIRECTION),
   mX(0.),
   mY(0.),
   mZ(0.)
{
}

nspGeometry::cls_Direction::cls_Direction(double p_x, double p_y, double p_z) :
   cls_GeometryEntity(etnDIRECTION),
   mX(p_x),
   mY(p_y),
   mZ(p_z)
{
}

nspGeometry::cls_Direction::~cls_Direction()
{
}

void nspGeometry::cls_Direction::Dump() const
{
   std::cout << "[DIRECTION] " << mX << "\t" << mY << "\t" << mZ << std::endl;
}
