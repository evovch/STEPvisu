#include "cls_ParameterTreeElement.h"

#include "cls_Parameter.h"
#include "cls_EI.h"
#include "cls_SEI.h"
#include "cls_CEI.h"

cls_ParameterTreeElement::cls_ParameterTreeElement(cls_Parameter* p_current,
                                                   cls_ParameterTreeElement* p_children,
                                                   cls_ParameterTreeElement* p_next) :
	mCurrent(p_current),
	mChildren(p_children),
	mNext(p_next)
{
}

cls_ParameterTreeElement::~cls_ParameterTreeElement()
{
}

cls_Parameter* cls_ParameterTreeElement::GetCurrent() const
{
	return mCurrent;
}

cls_ParameterTreeElement* cls_ParameterTreeElement::GetChildren() const
{
	return mChildren;
}

void cls_ParameterTreeElement::SetNext(cls_ParameterTreeElement* p_next)
{
	mNext = p_next;
}

cls_ParameterTreeElement* cls_ParameterTreeElement::GetNext() const
{
	return mNext;
}

cls_Parameter* cls_ParameterTreeElement::GetLast() const
{
   const cls_ParameterTreeElement* v_curPointer;
   v_curPointer = this;
   while (v_curPointer->GetNext() != nullptr)
   {
      v_curPointer = v_curPointer->GetNext();
   }
   return v_curPointer->GetCurrent();

}

void cls_ParameterTreeElement::Dump() const
{
	if (mCurrent) mCurrent->Dump();
	if (mChildren) mChildren->Dump();
	if (mNext) mNext->Dump();
}

void cls_ParameterTreeElement::Link(const cls_EIlist* p_section) const
{
	if (mCurrent) mCurrent->Link(p_section);
	if (mChildren) mChildren->Link(p_section);

   // Можно было бы реализовать рекурсивно в одну строку так:
   // mNext->Link(p_section);
   // но это приводит к ошибке переполнения стэка.
   if (mNext) {
      cls_ParameterTreeElement* v_next = mNext;
      while (v_next != nullptr) {
         if (v_next->GetCurrent()) v_next->GetCurrent()->Link(p_section);
         if (v_next->GetChildren()) v_next->GetChildren()->Link(p_section);
         v_next = v_next->GetNext();
      }
   }
}

//TODO const?
std::map<unsigned int, cls_EI*> cls_ParameterTreeElement::GetNodesByName(std::string p_filter)
{
   std::map<unsigned int, cls_EI*> v_returnList;

   std::map<unsigned int, cls_EI*> v_listFromSubscan;

   if (mCurrent)
   {
      cls_EI* v_childEI = mCurrent->GetPointer();
      if (v_childEI != nullptr)
      {
         cls_SEI* v_childSEI;
         //cls_CEI* v_childCEI;
         // Пройтись по v_childEI
         switch (v_childEI->GetType())
         {
         case etnSIMPLE:
            v_childSEI = static_cast<cls_SEI*> (v_childEI);
            if (v_childSEI->GetName() == p_filter) {
               v_returnList.insert(std::pair<unsigned int, cls_EI*> (v_childSEI->GetN(), v_childEI));
            }
            v_listFromSubscan = v_childSEI->GetNodesByName(p_filter);
            v_returnList.insert(v_listFromSubscan.begin(), v_listFromSubscan.end());

            break;
         case etnCOMPLEX:
            //v_childCEI = static_cast<cls_CEI*> (v_childEI);
            //TODO implement
            break;
         }

      }
   }

   if (mChildren)
   {
      v_listFromSubscan = mChildren->GetNodesByName(p_filter);
      v_returnList.insert(v_listFromSubscan.begin(), v_listFromSubscan.end());
   }

   if (mNext)
   {
      v_listFromSubscan = mNext->GetNodesByName(p_filter);
      v_returnList.insert(v_listFromSubscan.begin(), v_listFromSubscan.end());
   }

   return v_returnList;
}
