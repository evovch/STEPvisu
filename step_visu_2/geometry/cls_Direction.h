/**
 * ISO 10303-42-2000
 * 4.4.14 direction
 */

#ifndef CLS_DIRECTION_H
#define CLS_DIRECTION_H

#include "cls_GeometryEntity.h"

namespace nspGeometry
{
   class cls_Direction : public cls_GeometryEntity
   {
   public:
      cls_Direction();
      cls_Direction(double p_x, double p_y, double p_z);
      ~cls_Direction();

      /**
       * Метод для выброса информации в командную строку. Полезно для debug'а.
       */
      void Dump() const;

      double GetX() const { return mX; }
      double GetY() const { return mY; }
      double GetZ() const { return mZ; }

   private:
      double mX;
      double mY;
      double mZ;

   };
}

#endif // CLS_DIRECTION_H
