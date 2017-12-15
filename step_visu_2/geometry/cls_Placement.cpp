#include "cls_Placement.h"

#include <iostream>

nspGeometry::cls_Placement::cls_Placement() :
   cls_GeometryEntity(etnPLACEMENT),
   mPoint(nullptr)
{
}

nspGeometry::cls_Placement::cls_Placement(cls_Cartesian_point* p_point) :
   cls_GeometryEntity(etnPLACEMENT),
   mPoint(p_point)
{
}

nspGeometry::cls_Placement::~cls_Placement()
{
}

void nspGeometry::cls_Placement::Dump() const
{
   std::cout << "[PLACEMENT] " << std::endl;
}

void nspGeometry::cls_Placement::SetPoint(cls_Cartesian_point* p_point)
{
   mPoint = p_point;
}
