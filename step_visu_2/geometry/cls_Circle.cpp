#include "cls_Circle.h"

#include <iostream>

nspGeometry::cls_Circle::cls_Circle() :
   cls_GeometryEntity(etnCIRCLE),
   mPlacement(nullptr),
   mRadius(0.)
{
}

nspGeometry::cls_Circle::cls_Circle(double p_radius) :
   cls_GeometryEntity(etnCIRCLE),
   mPlacement(nullptr),
   mRadius(p_radius)
{
}

nspGeometry::cls_Circle::cls_Circle(cls_Axis2_placement_3d* p_placement, double p_radius) :
   cls_GeometryEntity(etnCIRCLE),
   mPlacement(p_placement),
   mRadius(p_radius)
{
}

nspGeometry::cls_Circle::~cls_Circle()
{
}

void nspGeometry::cls_Circle::Dump() const
{
   std::cout << "[CIRCLE] " << std::endl;
}
