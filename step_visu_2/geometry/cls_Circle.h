/**
 * ISO 10303-42-2000
 * 4.4.26 circle
 */

#pragma once

#include "cls_GeometryEntity.h" // mother class

#include "cls_Axis2_placement_3d.h"

namespace nspGeometry
{
   class cls_Circle : public cls_GeometryEntity
   {
   public:
      cls_Circle();
      explicit cls_Circle(double p_radius);
      cls_Circle(cls_Axis2_placement_3d* p_placement, double p_radius);
      ~cls_Circle();

      /**
      * Метод для выброса информации в командную строку. Полезно для debug'а.
      */
      void Dump(void) const;

      void SetPlacement(cls_Axis2_placement_3d* p_placement) { mPlacement = p_placement; }
      void SetRadius(double p_radius) { mRadius = p_radius; }

      cls_Axis2_placement_3d* GetPlacement(void) const { return mPlacement; }
      double GetRadius(void) const { return mRadius; }

   private:
      cls_Axis2_placement_3d* mPlacement;
      double mRadius;

   };
} // End of namespace nspGeometry
