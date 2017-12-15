#include "cls_SolidRepresentation_point.h"

#include "stepentities/cls_SEI.h"
#include "Support.h"

#include <iostream>

cls_SolidRepresentation_point::cls_SolidRepresentation_point()
{
}

cls_SolidRepresentation_point::~cls_SolidRepresentation_point()
{
}

void cls_SolidRepresentation_point::AddPoint(nspGeometry::cls_Cartesian_point p_point)
{
   mPoints.push_back(p_point);
}

void cls_SolidRepresentation_point::AddPoint(double p_x, double p_y, double p_z)
{
   nspGeometry::cls_Cartesian_point v_point(p_x, p_y, p_z);
   this->AddPoint(v_point);
}

//TODO Check the case when current point_representation object is empty
void cls_SolidRepresentation_point::Append(cls_SolidRepresentation_point* v_addend)
{
   if (!v_addend->GetPoints().empty()) {
      mPoints.insert(mPoints.end(), v_addend->GetPoints().begin(), v_addend->GetPoints().end());
   }
}

std::vector<nspGeometry::cls_Cartesian_point>& cls_SolidRepresentation_point::GetPoints()
{
   return mPoints;
}

void cls_SolidRepresentation_point::Dump() const
{
   std::vector<nspGeometry::cls_Cartesian_point>::const_iterator v_iter;

   for (v_iter = mPoints.begin(); v_iter != mPoints.end(); ++v_iter) {
      v_iter->Dump();
   }
}

void cls_SolidRepresentation_point::DumpToObj(QTextStream& p_stream)
{
   std::vector<nspGeometry::cls_Cartesian_point>::iterator v_iter;

   for (v_iter = mPoints.begin(); v_iter != mPoints.end(); ++v_iter) {
      p_stream << "v " << v_iter->GetX() << " " << v_iter->GetY() << " " << v_iter->GetZ() << "\n";
   }
}

void cls_SolidRepresentation_point::SendToGPU(GLuint p_VAO, GLuint p_VBO) const
{
   //TODO develop further and test

   unsigned int v_numOfPoints = mPoints.size();

   stc_VandC* v_VandCdataPointer;
   v_VandCdataPointer = new stc_VandC[v_numOfPoints];

   std::vector<nspGeometry::cls_Cartesian_point>::const_iterator v_iter;

   unsigned int i = 0;
   for (v_iter = mPoints.begin(); v_iter != mPoints.end(); ++v_iter) {
      v_VandCdataPointer[i].v[0] = v_iter->GetX();
      v_VandCdataPointer[i].v[1] = v_iter->GetY();
      v_VandCdataPointer[i].v[2] = v_iter->GetZ();
      v_VandCdataPointer[i].c[0] = 0.5;
      v_VandCdataPointer[i].c[1] = 0.5;
      v_VandCdataPointer[i].c[2] = 0.5;
      i++;
   }

   glBindVertexArray(p_VAO);
   {
      glBindBuffer(GL_ARRAY_BUFFER, p_VBO);
      glBufferData(GL_ARRAY_BUFFER, v_numOfPoints*sizeof(stc_VandC), v_VandCdataPointer, GL_STATIC_DRAW);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(stc_VandC), (void*)offsetof(stc_VandC, v));
      glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(stc_VandC), (void*)offsetof(stc_VandC, c));
      glEnableVertexAttribArray(0);
      glEnableVertexAttribArray(1);
   }
   glBindVertexArray(0);

   if (v_VandCdataPointer) delete [] v_VandCdataPointer;
}

void cls_SolidRepresentation_point::Draw(GLuint p_program, GLuint p_VAO) const
{
   unsigned int v_numOfPoints = mPoints.size();

   glUseProgram(p_program);
   glBindVertexArray(p_VAO);
   glDrawElements(GL_POINTS, v_numOfPoints/* * 3 */, GL_UNSIGNED_INT, NULL);
   glBindVertexArray(0);
   glUseProgram(0);
}