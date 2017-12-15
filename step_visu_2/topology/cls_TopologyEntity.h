/**
 * ISO 10303-42-2000
 * 5.4 Topology entity definitions.
 */

#pragma once

namespace nspTopology
{

   //TODO develop further
   enum enu_TopologyEntityType {
      etnUNSET,
      etnTOPOLOGICAL_REPRESENTATION_ITEM,
      etnVERTEX,
      etnVERTEX_POINT,
      etnEDGE,
      etnEDGE_CURVE,
      etnORIENTED_EDGE,
      etnSEAM_EDGE,
      etnSUBEDGE,
      etnPATH,
      etnORIENTED_PATH,
      etnOPEN_PATH,
      etnLOOP,
      etnVERTEX_LOOP,
      etnEDGE_LOOP,
      etnPOLY_LOOP,
      etnFACE_BOUND,
      etnFACE_OUTER_BOUND,
      etnFACE,
      etnFACE_SURFACE,
      etnORIENTED_FACE,
      etnSUBFACE
      //TODO go on
   };

   class cls_TopologyEntity
   {
   public:
      cls_TopologyEntity();
      explicit cls_TopologyEntity(enu_TopologyEntityType p_type);
      ~cls_TopologyEntity();

      virtual void Dump() const = 0;

   private:
      enu_TopologyEntityType mType;

   };

}
