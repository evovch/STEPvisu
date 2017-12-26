/**
 * ISO 10303-42-2000
 * 4.4.14 direction
 */

#pragma once

#include "cls_GeometryEntity.h" // mother class

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
      void Dump(void) const;

      double GetX(void) const { return mX; }
      double GetY(void) const { return mY; }
      double GetZ(void) const { return mZ; }

   private:
      double mX;
      double mY;
      double mZ;

   };
} // End of namespace nspGeometry
