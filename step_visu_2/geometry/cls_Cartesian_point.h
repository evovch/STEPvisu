/**
 * ISO 10303-42-2000
 * 4.4.4 cartesian_point
 */

#ifndef CLS_CARTESIAN_POINT_H
#define CLS_CARTESIAN_POINT_H

#include "cls_Point.h"

namespace nspGeometry
{
   class cls_Cartesian_point : public cls_Point
   {
   public:
      cls_Cartesian_point();
      cls_Cartesian_point(double p_x, double p_y, double p_z);
      ~cls_Cartesian_point();

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

#endif // CLS_CARTESIAN_POINT_H
