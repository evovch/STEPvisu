/**
 * ISO 10303-42-2000
 * 4.4.15 vector
 */

#pragma once

#include "cls_GeometryEntity.h"
#include "cls_Direction.h"

namespace nspGeometry
{
   class cls_Vector : public cls_GeometryEntity
   {
   public:
      cls_Vector();
      cls_Vector(cls_Direction* p_direction, double p_magnitude);
      ~cls_Vector();

      /**
       * Метод для выброса информации в командную строку. Полезно для debug'а.
       */
      void Dump() const;

      void SetDirection(cls_Direction* p_direction);
      void SetMagnitude(double p_magnitude);

      cls_Direction* GetDirection() const { return mDirection;  }
      double GetMagnitude() const { return mMagnitude; }

   private:

      cls_Direction* mDirection;

      double mMagnitude;

   };
}
