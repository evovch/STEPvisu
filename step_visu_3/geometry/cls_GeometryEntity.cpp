#include "cls_GeometryEntity.h"

namespace nspGeometry {

cls_GeometryEntity::cls_GeometryEntity() :
    mType(etnUNSET)
{
}

cls_GeometryEntity::cls_GeometryEntity(enu_GeometryEntityType p_type) :
    mType(p_type)
{
}

cls_GeometryEntity::~cls_GeometryEntity(void)
{
}

} // End of namespace nspGeometry
