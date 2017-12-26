/**
 * Representation of an object using points.
 * Basically just an std::vector of cartesian points.
 */

#pragma once

#include "cls_SolidRepresentation.h" // mother class

// STL
#include <vector>

// Qt
#include <QTextStream>

// Project
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
   void Dump(void) const;

   /*
    * Dump current cls_SolidRepresentation_point object into an OBJ file.
    * After that this OBJ file can be imported into another 3D software, for example Blender.
    */
   void DumpToObj(QTextStream& p_stream);

   // Reimplemented method of the mother class cls_SolidRepresentation
   void SendToGPU(GLuint p_VAO, GLuint p_VBO) /*const*/;

   // Reimplemented method of the mother class cls_SolidRepresentation
   void Draw(GLuint p_program, GLuint p_VAO) /*const*/;

private: // data members
   std::vector<nspGeometry::cls_Cartesian_point> mPoints;

private: // methods
   const std::vector<nspGeometry::cls_Cartesian_point>& GetPoints(void) const;

};
