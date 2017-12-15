/**
 * Complex_entity_instance class. Does not have a name. CEI is a list of SEI in fact.
 */

#pragma once

#include <vector>

#include "cls_EI.h" // Нужно инклюдить, т.к. это материнский класс

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
   void Dump() const;

   void Print() const;

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
