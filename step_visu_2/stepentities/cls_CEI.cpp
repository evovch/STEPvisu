#include "cls_CEI.h"

#include <iostream>

#include "cls_SEI.h"

cls_CEI::cls_CEI() :
   cls_EI(etnCOMPLEX)
{
}

cls_CEI::~cls_CEI()
{
}

void cls_CEI::SetN(const char* p_ninstr)
{
   mN = atoi(&p_ninstr[1]);
}

void cls_CEI::AddSEI(cls_SEI* p_sei)
{
   mSEIs.push_back(p_sei);
}

void cls_CEI::Dump() const
{
   std::cout << "[COMPLEX_EI] " << mN << std::endl;

   std::vector<cls_SEI*>::const_iterator v_iter;

   for (v_iter = mSEIs.begin(); v_iter != mSEIs.end(); ++v_iter)
   {
      (*v_iter)->Dump();
   }
}

void cls_CEI::Print() const
{
   std::cout << "[COMPLEX_EI] " << mN << std::endl;
}

void cls_CEI::Link(const cls_EIlist* p_section)
{
   std::vector<cls_SEI*>::const_iterator iter;

   for (iter = mSEIs.begin(); iter != mSEIs.end(); ++iter)
   {
      (*iter)->Link(p_section);
   }
}

void cls_CEI::GenerateBrepLinks(const cls_EIlist* /*p_section*/)
{
}

void cls_CEI::FillBrepLinks(const cls_EIlist* /*p_section*/)
{
}
