#include "cls_GeometryEntity.h"

nspGeometry::cls_GeometryEntity::cls_GeometryEntity() :
   mType(etnUNSET)
{
}

nspGeometry::cls_GeometryEntity::cls_GeometryEntity(enu_GeometryEntityType p_type) :
   mType(p_type)
{
}

nspGeometry::cls_GeometryEntity::~cls_GeometryEntity()
{
}
