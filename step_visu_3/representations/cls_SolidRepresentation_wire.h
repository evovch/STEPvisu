/**
 * Представление геометрического объекта с помощью каркасных элементов - только рёбра.
 */

#pragma once

#include "cls_SolidRepresentation.h" // mother class

class cls_SolidRepresentation_wire : public cls_SolidRepresentation
{
public:
   cls_SolidRepresentation_wire();
   ~cls_SolidRepresentation_wire();

   void SendToGPU(GLuint p_VAO, GLuint p_VBO) /*const*/;

   void Draw(GLuint p_program, GLuint p_VAO) /*const*/ = 0;

private:

};
