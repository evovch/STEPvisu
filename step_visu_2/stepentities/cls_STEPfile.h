/**
 * STEP файл. Содержит одну header секцию и список data секций.
 * Для секций отдельных классов нет.
 * Header секция содержит три или более header сущностей.
 * Соответственно в этом классе сразу приведён список объёектов типа header сущность. //TODO implement
 * Здесь же приведён объект типа список сущностей - entity instance list.
 */

#pragma once

#include <vector>
#include <string>

class cls_EIlist;
class cls_SolidRepresentation_point;

class cls_STEPfile
{
public: // methods
   cls_STEPfile();
   ~cls_STEPfile();

   void SetEIlist(cls_EIlist* p_eilist);

   void Dump() const;

   void Link();

   void GenerateAndFillBrepLinks();

   std::vector<std::string> ListByFilter(const char* p_filter);
   std::vector<std::string> ListByFilter(std::string p_filter);

   /**
    * ListByFilter("MANIFOLD_SOLID_BREP")
    */
   std::vector<std::string> ListSolids();

   /**
   * ListByFilter("PRODUCT")
   */
   std::vector<std::string> ListProducts();

   std::vector<cls_SolidRepresentation_point*> ExtractPoints();

private: // data members
   /**
    * Список сущностей из data секции.
    */
   cls_EIlist* mEntityInstanceList;

   /**
   * Данные из заголовка
   */
   //TODO implement

   /**
    * Флаг, который показывает, была ли проведена линковка.
    * Линковка - обязательный шаг, который необходимо выполнить,
    * прежде чем пытаться что-то распознавать в файле.
    */
   bool mLinked;

   bool mBREPfilled;
};

//TODO Нужно сделать одну хеадер секцию и вектор дата секций и для каждой секции ввести свой список.
// Пока предполагаем, что дата секция одна.
