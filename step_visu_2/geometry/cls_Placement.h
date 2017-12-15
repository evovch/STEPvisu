/**
 * ISO 10303-42-2000
 * 4.4.16 placement
 */

#ifndef CLS_PLACEMENT_H
#define CLS_PLACEMENT_H

#include "cls_GeometryEntity.h"
#include "cls_Cartesian_point.h"

namespace nspGeometry
{
   class cls_Placement : public cls_GeometryEntity
   {
   public:
      cls_Placement();
      explicit cls_Placement(cls_Cartesian_point* p_point);
      ~cls_Placement();

      /**
      * Метод для выброса информации в командную строку. Полезно для debug'а.
      */
      void Dump() const;

      void SetPoint(cls_Cartesian_point* p_point);

      cls_Cartesian_point* GetPoint() { return mPoint; }

   private:
      cls_Cartesian_point* mPoint;

   };
}

#endif // CLS_PLACEMENT_H
