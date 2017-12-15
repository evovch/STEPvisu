/**
 * Áàçîâûé êëàññ äëÿ ãðàôè÷åñêîãî ïðåäñòàâëåíèÿ îáúåêòà.
 */

#ifndef CLS_SOLIDREPRESENTATION_H
#define CLS_SOLIDREPRESENTATION_H

#include "glew.h"

class cls_SolidRepresentation
{
public:
   cls_SolidRepresentation();
   ~cls_SolidRepresentation();

   virtual void SendToGPU(GLuint p_VAO, GLuint p_VBO) const = 0;

   virtual void Draw(GLuint p_program, GLuint p_VAO) const = 0;

private:

};

#endif // CLS_SOLIDREPRESENTATION_H