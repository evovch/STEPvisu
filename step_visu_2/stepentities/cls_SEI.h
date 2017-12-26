/**
 * Класс, описывающий "простую" data сущность - simple entity instance.
 * У простой сущности помимо номера обязательно есть имя, после которого в STEP файле обязательно идёт выражение (м.б. пустое) в скобках.
 * Выражение в скобках - parameter_list, описывается классом cls_ParameterTreeElement.
 * 
 */

#pragma once

#include "cls_EI.h" // mother class

// STL
#include <string>
#include <map>

// Project
#include "geometry/cls_GeometryEntity.h"

class cls_ParameterTreeElement;
class cls_EIlist;

class cls_SEI : public cls_EI
{
public:
   /**
    * Конструктор с именем в качестве аргумента.
    */
   explicit cls_SEI(const char* p_name);

   /**
    * Конструктор с номером и именем в качестве аргументов.
    */
   cls_SEI(unsigned int p_n, const char* p_name);

   /**
    * Стандартный деструктор.
    */
   ~cls_SEI();

   /**
    * Устанавливает номер сущности.
    * Подход, где сначала создаётся объект без номера, но с именем, а затем вызывается этот метод,
    * чтобы установить номер не самый красивый, но актуален при синтаксическом разборе, где анализ идёт
    * изнутри и сначала распарсивается имя, а на уровень выше - номер.
    */
   void SetN(const char* p_ninstr);

   /**
    * Возвращает имя STEP сущности. Не путать с именем объекта, который представлен данной сущсностью.
    * Имя объекта является параметром сущности и вытаскивается методом GetFirstArgAsString.
    */
   std::string GetName() const;

   /**
   * Возвращает первый параметр сущности как строку. Во многих случаях эта строка =
   * имя объекта, который представлен данной STEP сущностью.
   */
   //TODO защиту от дурака.
   std::string GetFirstArgAsString() const;

   /**
    * Возвращает указатель на BREP сущность, соответствующую данной STEP сущности.
    */
   nspGeometry::cls_GeometryEntity* GetBREPentitiy();

   /**
    *
    */
   void SetParamList(cls_ParameterTreeElement* p_paramlist);

   void Dump() const;

   /**
    * Упрощённый метод для вывода сущности в одну строку
    */
   void Print() const;

   /**
    * Этот метод проходит по всем параметрам сущности и подцепляет указатели на другие сущности из
    * списка, заданного аргументом метода.
    */
   void Link(const cls_EIlist* p_section);

   void GenerateBrepLinks(const cls_EIlist* p_section);
   void FillBrepLinks(const cls_EIlist* p_section);

   /**
    * Проходит все дочерние сущности данной сущности и выбирает из них по имени.
    */
   std::map<unsigned int, cls_EI*> GetNodesByName(std::string p_filter) const;

   /**
   * Лишь обёртка над таким же методом с аргументов типа строка C++
   */
   std::map<unsigned int, cls_EI*> GetNodesByName(const char* p_filter) const;

private:
   /**
    * Имя сущности. Обязательный аттрибут объекта.
    */
   std::string mName;

   /**
    * Указатель на первый элемент в структуре типа "дерево", описывающей список параметров в скобках.
    */
   cls_ParameterTreeElement* mParamList;

   /**
    * Указатель на соответствующую BREP сущность,
    * может быть как geometry, так и topology, (а может быть и что-то ещё - ?)
    * Пока в процессе разработки.
    */
   nspGeometry::cls_GeometryEntity* mBREPentity;

};
