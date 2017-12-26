/**
 * Данный класс описывает абстрактную data сущноть без указания её типа - simple или complex.
 * Здесь хранится только номер сущности.
 * Соответственно SEI и CEI наследуются от EI.
 */

#pragma once

enum enu_EItype { etnSIMPLE=0, etnCOMPLEX=1 };

class cls_EIlist;

class cls_EI
{
public:
   /**
    * Конструктор c типом в качестве аргумента.
    */
   explicit cls_EI(enu_EItype p_type);

   /**
    * Конструктор с номером и типом в качестве аргументов.
    */
   cls_EI(enu_EItype p_type, unsigned int p_n);

   /**
    * Стандартный деструктор.
    */
   ~cls_EI(void);

   /**
    * Возвращает тип сущности.
    */
   enu_EItype GetType(void) const { return mType; }

   /**
    * Возвращает номер сущности.
    */
   unsigned int GetN(void) const { return mN; }

   /**
    * Метод для выброса информации в командную строку. Полезно для debug'а.
    */
   virtual void Dump(void) const = 0;

   virtual void Print(void) const = 0;

   virtual void Link(const cls_EIlist* p_section) = 0;

   virtual void GenerateBrepLinks(const cls_EIlist* p_section) = 0;
   virtual void FillBrepLinks(const cls_EIlist* p_section) = 0;

protected:
   /**
    * Флаг, обозначающий дочерний тип объекта.
    */
   enu_EItype mType;

   /**
    * Номер сущности. Обязательный аттрибут объекта.
    */
   unsigned int mN;

};
