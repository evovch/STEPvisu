/**
 * Представление геометрического объекта с помощью каркасных элементов - только рёбра.
 */

#ifndef CLS_SOLIDREPRESENTATION_WIRE_H
#define CLS_SOLIDREPRESENTATION_WIRE_H

#include "cls_SolidRepresentation.h"

class cls_SolidRepresentation_wire : public cls_SolidRepresentation
{
public:
   cls_SolidRepresentation_wire();
   ~cls_SolidRepresentation_wire();

   void SendToGPU();

private:

};

#endif // CLS_SOLIDREPRESENTATION_WIRE_H