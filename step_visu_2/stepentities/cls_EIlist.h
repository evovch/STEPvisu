/**
 * Данный класс хранит в себе список data сущностей - entity instance'ов.
 */

#pragma once

#include <map>
#include <string>

class cls_EI;

class cls_EIlist
{
public:
   cls_EIlist();
   ~cls_EIlist();

   /**
    * Добавить в список новую сущность.
    */
   void AddEI(unsigned int p_n, cls_EI* p_ei);

   /**
    * Метод для выброса информации в командную строку. Полезно для debug'а.
    */
   void Dump() const;

   void Link();

   void GenerateAndFillBrepLinks();

   cls_EI* GetEIbyN(unsigned int p_n) const;

   /**
    * Нати все сущности с заданным именем и вернуть нумерованным списком.
    */
   std::map<unsigned int, cls_EI*> Find(std::string p_filter) const;

   /**
    * Лишь обёртка над таким же методом с аргументов типа строка C++
    */
   std::map<unsigned int, cls_EI*> Find(const char* p_filter) const;

private:
   std::map<unsigned int, cls_EI*> mEIs;

};
