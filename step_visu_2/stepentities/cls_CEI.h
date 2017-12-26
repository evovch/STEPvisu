/**
 * Complex_entity_instance class. Does not have a name. CEI is a list of SEI in fact.
 */

#pragma once

#include "cls_EI.h" // mother class

// STL
#include <vector>

class cls_SEI;
class cls_EIlist;

class cls_CEI : public cls_EI
{
public:
   cls_CEI();
   ~cls_CEI();

   void SetN(const char* p_ninstr);

   void AddSEI(cls_SEI* p_sei);

   /**
    * Метод для выброса информации в командную строку. Полезно для debug'а.
    */
   void Dump(void) const;

   void Print(void) const;

   /**
    * Этот метод проходит по всем параметрам сущности и подцепляет указатели на другие сущности из
    * списка, заданного аргументом метода.
    */
   void Link(const cls_EIlist* p_section);

   void GenerateBrepLinks(const cls_EIlist* p_section);
   void FillBrepLinks(const cls_EIlist* p_section);

private:
   std::vector<cls_SEI*> mSEIs;

};
