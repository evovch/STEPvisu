#include "cls_SEI.h"

#include "cls_ParameterTreeElement.h"
#include "cls_Parameter.h"

#include <iostream>

#include "geometry/cls_Cartesian_point.h"
#include "geometry/cls_Direction.h"
#include "geometry/cls_Vector.h"
#include "geometry/cls_Line.h"
#include "geometry/cls_Circle.h"
#include "geometry/cls_Axis2_placement_3d.h"

cls_SEI::cls_SEI(const char* p_name) :
   cls_EI(etnSIMPLE),
	mParamList(nullptr),
   mBREPentity(nullptr)
{
	std::string v_cppstring(p_name);
	mName = v_cppstring;
}

cls_SEI::cls_SEI(unsigned int p_n, const char* p_name) :
   cls_EI(etnSIMPLE, p_n),
   mParamList(nullptr),
   mBREPentity(nullptr)
{
	std::string v_cppstring(p_name);
	mName = v_cppstring;
}

cls_SEI::~cls_SEI()
{
}

void cls_SEI::SetN(const char* p_ninstr)
{
	mN = atoi(&p_ninstr[1]);
}

std::string cls_SEI::GetName() const
{
   return mName;
}

std::string cls_SEI::GetFirstArgAsString() const
{
   cls_Parameter* v_firstParam;
   v_firstParam = mParamList->GetLast();
   return v_firstParam->GetValAsString();
}

void cls_SEI::SetParamList(cls_ParameterTreeElement* p_paramlist)
{
	mParamList = p_paramlist;
}

void cls_SEI::Dump() const
{
   std::cout << "[SIMPLE_EI ] " << mN << "=" << mName << std::endl;
   if (mParamList) {
      mParamList->Dump();
   }
}

void cls_SEI::Print() const
{
   std::cout << "[SIMPLE_EI ] " << mN << "=" << mName << std::endl;
}

void cls_SEI::Link(const cls_EIlist* p_section)
{
   if (mParamList) {
      mParamList->Link(p_section);
   }
}

void cls_SEI::GenerateBrepLinks(const cls_EIlist* /*p_section*/)
{
   if (mName == "AXIS2_PLACEMENT_3D") {
      // Только создать
      mBREPentity = new nspGeometry::cls_Axis2_placement_3d();
   }  else if (mName == "CARTESIAN_POINT") {
      // Создать и сразу полностью заполнить
      double v_x, v_y, v_z;
      cls_ParameterTreeElement* v_subTreeWithCoords = mParamList->GetChildren()->GetChildren();
      // Ну не говно ли?
      cls_Parameter* v_curParam = v_subTreeWithCoords->GetCurrent();
      v_z = v_curParam->GetValAsDouble();
      v_curParam = v_subTreeWithCoords->GetNext()->GetCurrent();
      v_y = v_curParam->GetValAsDouble();
      v_curParam = v_subTreeWithCoords->GetNext()->GetNext()->GetCurrent();
      v_x = v_curParam->GetValAsDouble();
      mBREPentity = new nspGeometry::cls_Cartesian_point(v_x, v_y, v_z);
   } else if (mName == "CIRCLE") {
      // Cоздать и частично заполнить
      cls_Parameter* v_curParam = mParamList->GetCurrent();
      double v_radius = v_curParam->GetValAsDouble();
      mBREPentity = new nspGeometry::cls_Circle(v_radius);
   } else if (mName == "DIRECTION") {
      // Создать и сразу полностью заполнить
      double v_x, v_y, v_z;
      cls_ParameterTreeElement* v_subTreeWithCoords = mParamList->GetChildren()->GetChildren();
      // Ну не говно ли?
      cls_Parameter* v_curParam = v_subTreeWithCoords->GetCurrent();
      v_z = v_curParam->GetValAsDouble();
      v_curParam = v_subTreeWithCoords->GetNext()->GetCurrent();
      v_y = v_curParam->GetValAsDouble();
      v_curParam = v_subTreeWithCoords->GetNext()->GetNext()->GetCurrent();
      v_x = v_curParam->GetValAsDouble();
      mBREPentity = new nspGeometry::cls_Direction(v_x, v_y, v_z);
   } else if (mName == "LINE") {
      // Только создать
      mBREPentity = new nspGeometry::cls_Line();
   } else if (mName == "VECTOR") {
      // Только создать
      mBREPentity = new nspGeometry::cls_Vector();
   } else {

   }

}

void cls_SEI::FillBrepLinks(const cls_EIlist* /*p_section*/)
{
   if (mName == "AXIS2_PLACEMENT_3D") {
      // Заполнить
      //TODO implement
   } else if (mName == "CARTESIAN_POINT") {
      // Ничего не требуется делать
   } else if (mName == "CIRCLE") {

      // Дозаполнить
      cls_Parameter* v_placementNode = mParamList->GetNext()->GetCurrent();
      cls_SEI* v_placementEI = static_cast<cls_SEI*>(v_placementNode->GetPointer());
      nspGeometry::cls_Axis2_placement_3d* v_placementRef
         = static_cast<nspGeometry::cls_Axis2_placement_3d*>(v_placementEI->GetBREPentitiy());
      
      dynamic_cast<nspGeometry::cls_Circle*>(mBREPentity)->SetPlacement(v_placementRef);

   } else if (mName == "DIRECTION") {
      // Ничего не требуется делать
   } else if (mName == "LINE") {

      // Заполнить
      cls_Parameter* v_pointNode = mParamList->GetNext()->GetCurrent();
      //FIXME type - avoid cast - ?
      cls_SEI* v_pointEI = static_cast<cls_SEI*>(v_pointNode->GetPointer());
      nspGeometry::cls_Cartesian_point* v_pointRef
         = static_cast<nspGeometry::cls_Cartesian_point*>(v_pointEI->GetBREPentitiy());

      cls_Parameter* v_vectorNode = mParamList->GetCurrent();
      //FIXME type - avoid cast - ?
      cls_SEI* v_vectorEI = static_cast<cls_SEI*>(v_vectorNode->GetPointer());
      nspGeometry::cls_Direction* v_vectorRef
         = static_cast<nspGeometry::cls_Direction*>(v_vectorEI->GetBREPentitiy());

      dynamic_cast<nspGeometry::cls_Line*>(mBREPentity)->SetPoint(v_pointRef);
      dynamic_cast<nspGeometry::cls_Line*>(mBREPentity)->SetDirection(v_vectorRef);

   } else if (mName == "VECTOR") {
      // Заполнить
      cls_Parameter* v_directionNode = mParamList->GetNext()->GetCurrent();
      //FIXME type - avoid cast - ?
      cls_SEI* v_directionEI = static_cast<cls_SEI*>(v_directionNode->GetPointer());

      nspGeometry::cls_Direction* v_dirRef
         = static_cast<nspGeometry::cls_Direction*>(v_directionEI->GetBREPentitiy());

      double v_magn = mParamList->GetCurrent()->GetValAsDouble();

      dynamic_cast<nspGeometry::cls_Vector*>(mBREPentity)->SetDirection(v_dirRef);
      dynamic_cast<nspGeometry::cls_Vector*>(mBREPentity)->SetMagnitude(v_magn);

   } else {
      ;
   }
}

std::map<unsigned int, cls_EI*> cls_SEI::GetNodesByName(std::string p_filter) const
{
   return mParamList->GetNodesByName(p_filter);
}

std::map<unsigned int, cls_EI*> cls_SEI::GetNodesByName(const char* p_filter) const
{
   std::string v_filtercpp(p_filter);
   return this->GetNodesByName(v_filtercpp);
}

nspGeometry::cls_GeometryEntity* cls_SEI::GetBREPentitiy()
{
   return mBREPentity;
}
