#include "cls_Axis2_placement_3d.h"

//TODO fix type of the entity

namespace nspGeometry {

cls_Axis2_placement_3d::cls_Axis2_placement_3d() :
    mAxis(nullptr),
    mRefDir(nullptr)
{
    mType = etnAXIS2_PLACEMENT_3D;
}

cls_Axis2_placement_3d::cls_Axis2_placement_3d(cls_Direction* p_axis, cls_Direction* p_dir)
{
    mType = etnAXIS2_PLACEMENT_3D;
    mAxis = p_axis;
    mRefDir = p_dir;
}

cls_Axis2_placement_3d::~cls_Axis2_placement_3d()
{
}

void cls_Axis2_placement_3d::SetAxis(cls_Direction* /*p_axis*/)
{
}

void cls_Axis2_placement_3d::SetDirection(cls_Direction* /*p_dir*/)
{
}

} // End of namespace nspGeometry
