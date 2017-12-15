/**
 * ISO 10303-42-2000
 * 4.4.24 line
 */

#ifndef CLS_LINE_H
#define CLS_LINE_H

#include "cls_GeometryEntity.h"
#include "cls_Cartesian_point.h"
#include "cls_Direction.h"

namespace nspGeometry
{
   class cls_Line : public cls_GeometryEntity
   {
   public:
      cls_Line();
      cls_Line(cls_Cartesian_point* p_point, cls_Direction* p_direction);
      ~cls_Line();

      /**
       * Метод для выброса информации в командную строку. Полезно для debug'а.
       */
      void Dump() const;

      void SetPoint(cls_Cartesian_point* p_point) { mPoint = p_point; }
      void SetDirection(cls_Direction* p_direction) { mDirection = p_direction; }

      cls_Cartesian_point* GetPoint() { return mPoint; }
      cls_Direction* GetDirection() { return mDirection; }

   private:
      cls_Cartesian_point* mPoint;
      cls_Direction* mDirection;

   };
}

#endif // CLS_LINE_H
