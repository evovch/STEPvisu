#include "cls_TopologyEntity.h"

nspTopology::cls_TopologyEntity::cls_TopologyEntity() :
   mType(etnUNSET)
{
}

nspTopology::cls_TopologyEntity::cls_TopologyEntity(enu_TopologyEntityType p_type) :
   mType(p_type)
{
}

nspTopology::cls_TopologyEntity::~cls_TopologyEntity()
{
}
