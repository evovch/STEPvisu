/**
 * ISO 10303-42-2000
 * 4.4.19 axis2_placement_3d
 */

#pragma once

#include "cls_Placement.h" // mother class

namespace nspGeometry
{
    class cls_Direction;

    class cls_Axis2_placement_3d : public cls_Placement
    {
        public:
            cls_Axis2_placement_3d();
            cls_Axis2_placement_3d(cls_Direction* p_axis, cls_Direction* p_dir);
            ~cls_Axis2_placement_3d();

            void SetAxis(cls_Direction* p_axis);
            void SetDirection(cls_Direction* p_dir);

        private:
            cls_Direction* mAxis;
            cls_Direction* mRefDir;
    };
} // End of namespace nspGeometry
