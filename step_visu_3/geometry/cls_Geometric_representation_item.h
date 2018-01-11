/**
 * ISO 10303-42-2000
 * 4.4.2 geometric_representation_item
 */

#pragma once

#include "geometry/cls_GeometryEntity.h" // mother class

namespace nspGeometry
{

class cls_Geometric_representation_item : public cls_GeometryEntity
{
public:
    cls_Geometric_representation_item();
    ~cls_Geometric_representation_item();
};
} // End of namespace nspGeometry
