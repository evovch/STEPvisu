/**
 * (Абстрактный) класс для описания некой BREP сущности.
*/

#pragma once

namespace nspBREP
{

   //TODO develop further
   enum enu_BREPentityType {
      etnUNSET,
      etnPOINT
   };

   class cls_BREPentity
   {
   public:
      cls_BREPentity();
      cls_BREPentity(enu_BREPentityType p_type);
      ~cls_BREPentity();

      virtual void Dump() const = 0;

   private:
      enu_BREPentityType mType;

   };
}
