/**
 * ISO 10303-42-2000
 * 5.4.3 vertex_point
 */

#pragma once

#include "cls_TopologyEntity.h"

namespace nspTopology
{
   class cls_Vertex_point : public cls_TopologyEntity
   {
   public:
      cls_Vertex_point();
      ~cls_Vertex_point();

      /**
       * Метод для выброса информации в командную строку. Полезно для debug'а.
       */
      void Dump() const;

   private:

   };
}
