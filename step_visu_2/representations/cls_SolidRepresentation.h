/**
 * Áàçîâûé êëàññ äëÿ ãðàôè÷åñêîãî ïðåäñòàâëåíèÿ îáúåêòà.
 */

#pragma once

#include <QOpenGLFunctions_4_5_Core> // mother class

class cls_SolidRepresentation : protected QOpenGLFunctions_4_5_Core
{
public:
   cls_SolidRepresentation();
   ~cls_SolidRepresentation();

   virtual void SendToGPU(GLuint p_VAO, GLuint p_VBO) /*const*/ = 0;

   virtual void Draw(GLuint p_program, GLuint p_VAO) /*const*/ = 0;

private:

};
