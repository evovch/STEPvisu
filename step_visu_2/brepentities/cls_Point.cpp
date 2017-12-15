#include "cls_Point.h"

#include <iostream>

nspBREP::cls_Point::cls_Point(double p_x, double p_y, double p_z) :
   mX(p_x),
   mY(p_y),
   mZ(p_z)
{
}

nspBREP::cls_Point::~cls_Point()
{
}

void nspBREP::cls_Point::Dump() const
{
   std::cout << "[POINT] " << mX << "\t" << mY << "\t" << mZ << std::endl;
}