/**
 * Представление геометрического объекта с помощью каркасных элементов - только рёбра.
 */

#pragma once

#include "cls_SolidRepresentation.h"

class cls_SolidRepresentation_wire : public cls_SolidRepresentation
{
public:
   cls_SolidRepresentation_wire();
   ~cls_SolidRepresentation_wire();

   void SendToGPU();

private:

};
