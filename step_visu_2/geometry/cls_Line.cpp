#include "cls_Line.h"

#include <iostream>

nspGeometry::cls_Line::cls_Line() :
   cls_GeometryEntity(etnLINE),
   mPoint(nullptr),
   mDirection(nullptr)
{
}

nspGeometry::cls_Line::cls_Line(cls_Cartesian_point* p_point, cls_Direction* p_direction) :
   cls_GeometryEntity(etnLINE),
   mPoint(p_point),
   mDirection(p_direction)
{
}

nspGeometry::cls_Line::~cls_Line()
{
}

void nspGeometry::cls_Line::Dump() const
{
   std::cout << "[LINE] " << std::endl;
}
