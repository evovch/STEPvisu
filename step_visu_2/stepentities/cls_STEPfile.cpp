#include "cls_STEPfile.h"

#include "cls_EIlist.h"
#include "cls_SEI.h"

#include "cls_GLTimer.h"

#include <map>
#include <iostream>
#include "representations/cls_SolidRepresentation_point.h"

class cls_EI;

cls_STEPfile::cls_STEPfile() :
   mEntityInstanceList(nullptr),
   mLinked(false),
   mBREPfilled(false)
{
}

cls_STEPfile::~cls_STEPfile()
{
}

void cls_STEPfile::SetEIlist(cls_EIlist* p_eilist)
{
   mEntityInstanceList = p_eilist;
}

void cls_STEPfile::Dump() const
{
   mEntityInstanceList->Dump();
}

void cls_STEPfile::Link()
{
   std::cout << "Linking..." << std::endl;
   cls_GLTimer v_timer;
   v_timer.Start();
   mEntityInstanceList->Link();
   mLinked = true;
   std::cout << "Done linking. " << v_timer.Stop() << std::endl;
}

void cls_STEPfile::GenerateAndFillBrepLinks()
{
   std::cout << "Filling BREP links..." << std::endl;
   cls_GLTimer v_timer;
   v_timer.Start();
   mEntityInstanceList->GenerateAndFillBrepLinks();
   mBREPfilled = true;
   std::cout << "Done filling BREP links. " << v_timer.Stop() << std::endl;
}

std::vector<std::string> cls_STEPfile::ListByFilter(const char* p_filter)
{
   std::string v_filtercpp(p_filter);
   return this->ListByFilter(v_filtercpp);
}

//FIXME нужно придумать, как избегать преобразования типа. Сейчас будут ошибки, если пытаться строить для CEI
std::vector<std::string> cls_STEPfile::ListByFilter(std::string p_filter)
{
   std::cout << "Listing by filter " << p_filter << "..." << std::endl;
   cls_GLTimer v_timer;
   v_timer.Start();
   
   // Link if not yet linked
   if (!mLinked) this->Link();

   // Объявляем и заполняем список сущностей по фильтру.
   std::map<unsigned int, cls_EI*> foundList;
   foundList = mEntityInstanceList->Find(p_filter);

   // Объявляем список имён найденных сущностей. Этот список и вернёт данный метод.
   std::vector<std::string> v_NamesList;
   std::string v_formedString;

   // Цикл по всем найенным сущностям типа PRODUCT.
   std::map<unsigned int, cls_EI*>::iterator iterProducts;
   for (iterProducts = foundList.begin(); iterProducts != foundList.end(); ++iterProducts) {

      // В этой сущности есть дерево всего солида, по которому можно пройтись,
      // чтобы достать геометрические объекты для формирования representation.
      cls_SEI* curFilteredSEI;

      curFilteredSEI = static_cast<cls_SEI*> (iterProducts->second);
      v_formedString = std::to_string(curFilteredSEI->GetN());
      v_formedString += ": ";
      v_formedString += curFilteredSEI->GetFirstArgAsString();
      v_NamesList.push_back(v_formedString);
      //std::cout << curFilteredSEI->GetN() << "=" << curFilteredSEI->GetName() << std::endl;
   }

   std::cout << "Done listing by filter " << p_filter << ". " << v_timer.Stop() << std::endl;

   return v_NamesList;
}

std::vector<std::string> cls_STEPfile::ListSolids()
{
   return this->ListByFilter("MANIFOLD_SOLID_BREP");
}

std::vector<std::string> cls_STEPfile::ListProducts()
{
   return this->ListByFilter("PRODUCT");
}

std::vector<cls_SolidRepresentation_point*> cls_STEPfile::ExtractPoints()
{
   std::cout << "Extracting points..." << std::endl;
   cls_GLTimer v_timer;
   v_timer.Start();

   // Link if not yet linked
   if (!mLinked) this->Link();

   if (!mBREPfilled) this->GenerateAndFillBrepLinks();

   // Объявляем и заполняем список сущностей типа MANIFOLD_SOLID_BREP.
   std::map<unsigned int, cls_EI*> foundList;
   foundList = mEntityInstanceList->Find("MANIFOLD_SOLID_BREP");

   // Сюда складываем точки для point representation.
   std::map<unsigned int, cls_EI*> foundPoints;

   // В этой сущности есть дерево всего солида, по которому можно пройтись,
   // чтобы достать геометрические объкты для формирования representation.
   cls_SEI* curSolidSEI;
   cls_SEI* curPointSEI;

   std::vector<cls_SolidRepresentation_point*> v_listOfRepres;

   std::map<unsigned int, cls_EI*>::iterator iterSolids;
   std::map<unsigned int, cls_EI*>::iterator iterPoints;

   // Цикл по всем найенным сущностям типа MANIFOLD_SOLID_BREP.
   for (iterSolids = foundList.begin(); iterSolids != foundList.end(); ++iterSolids) {
      curSolidSEI = static_cast<cls_SEI*> (iterSolids->second);
      ////std::cout << curSolidSEI->GetN() << "=" << curSolidSEI->GetName() << std::endl;

      cls_SolidRepresentation_point* v_curRepr = new cls_SolidRepresentation_point();

      // Достаём все точки, принадлежащие данному телу.
      // Не самый правильный подход.
      // По-хорошему нужно доставать только определённые точки - скажем, края рёбер.
      foundPoints = curSolidSEI->GetNodesByName("CARTESIAN_POINT");
      // Выводим найденный список.
      for (iterPoints = foundPoints.begin(); iterPoints != foundPoints.end(); ++iterPoints) {
         ////(iterPoints->second)->Print();
         curPointSEI = static_cast<cls_SEI*> (iterPoints->second);

         nspGeometry::cls_Cartesian_point* v_curCartPoint = static_cast<nspGeometry::cls_Cartesian_point*> (curPointSEI->GetBREPentitiy());
         v_curRepr->AddPoint(*v_curCartPoint);
      }

      v_listOfRepres.push_back(v_curRepr);

   }

   std::cout << "Done extracting points. " << v_timer.Stop() << std::endl;

   return v_listOfRepres;
}