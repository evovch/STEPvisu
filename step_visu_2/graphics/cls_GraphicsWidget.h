#pragma once

#include "GL/glew.h"

#include <QGLWidget>

class cls_Camera;
class cls_SolidRepresentation;

class cls_GraphicsWidget : public QGLWidget
{
    Q_OBJECT

    friend class cls_Camera;

public:
    explicit cls_GraphicsWidget(QWidget *parent = 0);
   ~cls_GraphicsWidget(void);

    void InitProgs(void);
    void InitBuffers(void);

    // Get the linked camera object
    cls_Camera* GetCamera(void) const { return mCamera; }

    void SetRepresentation(cls_SolidRepresentation* p_representation);
    void SendRepresentationToGPU(void) const;

protected:
    void initializeGL(void);
    void resizeGL(int /*p_width*/, int /*p_height*/);
    void paintGL(void);

private:
    /*static*/ void CreateProg(GLuint p_program, const std::vector<GLuint>& p_shaderList);
    /*static*/ GLuint CreateShader(GLenum p_eShaderType, const QString& p_strShaderFile);
    
    // Camera object
    cls_Camera* mCamera;

    // Program objects
    GLuint mWireframeDrawProgram;

    // Vertex array objects, vertex buffer objects and index buffer objects
    GLuint mVAOshading;
    GLuint mVBOshading;
    GLuint mIBOwire;

    // Uniform variables for matrices
    GLuint mMVPwireUniform;

    // Representation object to be displayed
    cls_SolidRepresentation* mModel;

};
