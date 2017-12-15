/**
 * Representation of an object using points.
 * Basically just an std::vector of cartesian points.
 */

#pragma once

#include <vector>

#include <QTextStream>

#include "cls_SolidRepresentation.h"
#include "geometry/cls_Cartesian_point.h"

class cls_SEI;

class cls_SolidRepresentation_point : public cls_SolidRepresentation
{
public:
   cls_SolidRepresentation_point();
   ~cls_SolidRepresentation_point();

   /*
    * Add a point into the repesentation.
    */
   void AddPoint(nspGeometry::cls_Cartesian_point p_point);

   /*
    * Add a point constructed from 3 coordinates into the repesentation.
    */
   void AddPoint(double p_x, double p_y, double p_z);

   /*
    * Append a representation to the current object.
    */
   void Append(cls_SolidRepresentation_point* v_addned);

   /*
    * Iteratively Dump() each point in the representation.
    */
   void Dump() const;

   /*
    * Dump current cls_SolidRepresentation_point object into an OBJ file.
    * After that this OBJ file can be imported into another 3D software, for example Blender.
    */
   void DumpToObj(QTextStream& p_stream);

   void SendToGPU(GLuint p_VAO, GLuint p_VBO) const;
   void Draw(GLuint p_program, GLuint p_VAO) const;

private:
   std::vector<nspGeometry::cls_Cartesian_point> mPoints;

private:
   std::vector<nspGeometry::cls_Cartesian_point>& GetPoints();
};
