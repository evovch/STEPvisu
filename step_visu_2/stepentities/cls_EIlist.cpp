#include "cls_EIlist.h"

// Project
#include "cls_SEI.h"
#include "cls_CEI.h"

cls_EIlist::cls_EIlist()
{
}

cls_EIlist::~cls_EIlist(void)
{
}

void cls_EIlist::AddEI(unsigned int p_n, cls_EI* p_ei)
{
   mEIs.insert( std::pair<unsigned int, cls_EI*> (p_n, p_ei) );
}

void cls_EIlist::Dump(void) const
{
   std::map<unsigned int, cls_EI*>::const_iterator iter;

   for (iter = mEIs.begin(); iter != mEIs.end(); ++iter)
   {
      (iter->second)->Dump();
   }

}

void cls_EIlist::Link(void)
{
   std::map<unsigned int, cls_EI*>::const_iterator iter;

   for (iter = mEIs.begin(); iter != mEIs.end(); ++iter)
   {
      (iter->second)->Link(this);
   }
}

void cls_EIlist::GenerateAndFillBrepLinks(void)
{
   //TODO check
   // Do it reversed - more efficiently ?
   std::map<unsigned int, cls_EI*>::const_reverse_iterator iter;

   for (iter = mEIs.rbegin(); iter != mEIs.rend(); ++iter)
   {
      (iter->second)->GenerateBrepLinks(this);
   }

   for (iter = mEIs.rbegin(); iter != mEIs.rend(); ++iter)
   {
      (iter->second)->FillBrepLinks(this);
   }
}

cls_EI* cls_EIlist::GetEIbyN(unsigned int p_n) const
{
   return mEIs.find(p_n)->second;
}

std::map<unsigned int, cls_EI*> cls_EIlist::Find(std::string p_filter) const
{
   std::map<unsigned int, cls_EI*> v_returnList;

   cls_SEI* v_curSEI;
   //cls_CEI* v_curCEI;

   std::map<unsigned int, cls_EI*>::const_iterator v_iter;

   for (v_iter = mEIs.begin(); v_iter != mEIs.end(); ++v_iter)
   {
      switch ((v_iter->second)->GetType())
      {
      case etnSIMPLE:
         v_curSEI = static_cast<cls_SEI*> (v_iter->second);

         // Здесь у нас уже есть SEI. Нужно посмотреть его имя и если оно подходит по фильтру,
         // записать объект в выходной список.
         if (v_curSEI->GetName() == p_filter) {
            //qDebug().nospace() << "Found " << p_filter << ". N=" << v_curSEI->GetN();
            v_returnList.insert(std::pair<unsigned int, cls_EI*>(v_curSEI->GetN(), (v_iter->second)));
         }

         break;
      case etnCOMPLEX:
         //v_curCEI = static_cast<cls_CEI*> (v_iter->second);
         //TODO implement
         break;
      }
   }

   return v_returnList;
}

std::map<unsigned int, cls_EI*> cls_EIlist::Find(const char* p_filter) const
{
   std::string v_filtercpp(p_filter);
   return this->Find(v_filtercpp);
}
