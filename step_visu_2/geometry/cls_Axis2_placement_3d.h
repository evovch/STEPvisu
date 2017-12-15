/**
* ISO 10303-42-2000
* 4.4.19 axis2_placement_3d
*/

#ifndef CLS_AXIS2_PLACEMENT_3D_H
#define CLS_AXIS2_PLACEMENT_3D_H

#include "cls_Placement.h"
#include "cls_Direction.h"

namespace nspGeometry
{
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
}

#endif // CLS_AXIS2_PLACEMENT_3D_H