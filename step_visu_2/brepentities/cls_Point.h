/**
 * Класс геометрическая точка в декартовом пространстве.
 */

#ifndef CLS_POINT_H
#define CLS_POINT_H

#include "brepentities/cls_BREPentity.h"

namespace nspBREP 
{
   class cls_Point : public cls_BREPentity
   {
   public:
      cls_Point(double p_x, double p_y, double p_z);
      ~cls_Point();

      /**
       * Метод для выброса информации в командную строку. Полезно для debug'а.
       */
      void Dump() const;

   private:
      double mX;
      double mY;
      double mZ;

   };
}

#endif // CLS_POINT_H
