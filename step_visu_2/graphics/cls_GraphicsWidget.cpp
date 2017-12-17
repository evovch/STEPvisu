#include "cls_GraphicsWidget.h"

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "cls_Camera.h"
#include "representations/cls_SolidRepresentation_point.h"

cls_GraphicsWidget::cls_GraphicsWidget(QWidget *parent)
	: QGLWidget(parent),
	  mCamera(nullptr),
	  mModel(nullptr)
{
	// Moved everything from here to initializeGL()
	// as most probably QT create OpenGL context after construtor and before initializeGL()
}

cls_GraphicsWidget::~cls_GraphicsWidget()
{
	if (mCamera) delete mCamera;
	//if (mModel) delete mModel; //TODO needed?
}

void cls_GraphicsWidget::initializeGL()
{
	printf("Version of OpenGL detected in the system: '%s'\n", glGetString(GL_VERSION));

	GLenum glewInitResult = glewInit();
	if (glewInitResult != GLEW_OK) {
		printf("Error initializing GLEW\n");
		printf("%s\n", glewGetErrorString(glewInitResult));
	}

	// Init program and shaders
	this->InitProgs();

	// Init buffers
	this->InitBuffers();

	// Init culling		//TODO enable/disable
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glFrontFace(GL_CCW);

	// Init depth
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glDepthRange(0.0f, 1.0f);

	glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	// Init the camera 
	glm::vec3 v_center; float v_radius;
	v_center = glm::vec3(0.0f, 0.0f, 0.0f);
	v_radius = 1.0f;
	mCamera = new cls_Camera(this, v_center, v_radius);

}

void cls_GraphicsWidget::SetRepresentation(cls_SolidRepresentation* p_representation)
{
	mModel = p_representation;
}

void cls_GraphicsWidget::SendRepresentationToGPU(void) const
{
	mModel->SendToGPU(mVAOshading, mVBOshading);
}

void cls_GraphicsWidget::resizeGL(int p_width, int p_height)
{
	mCamera->SendCamToGPU();
	glViewport(0, 0, (GLsizei)p_width, (GLsizei)p_height);
	//this->paintGL();
}

void cls_GraphicsWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//FIXME - not the best way. mModel has to initialised before the first call of this
	// automatocally called function
	if (mModel) {
		mModel->Draw(mWireframeDrawProgram, mVAOshading);
	}
}

void cls_GraphicsWidget::InitProgs(void)
{
	// Create program and shaders

	// ------------------------------ Wireframe draw program ------------------------------
	mWireframeDrawProgram = glCreateProgram();
	std::vector<GLuint> shaderList2;
	shaderList2.push_back(CreateShader(GL_VERTEX_SHADER, "shaders/vertSh_wire.vp"));
	shaderList2.push_back(CreateShader(GL_GEOMETRY_SHADER, "shaders/geomSh_wire.gp"));
	shaderList2.push_back(CreateShader(GL_FRAGMENT_SHADER, "shaders/frSh_flat.fp"));

	CreateProg(mWireframeDrawProgram, shaderList2);

	// Cleanup
	std::for_each(shaderList2.begin(), shaderList2.end(), glDeleteShader);

	// Connect uniform variables
	mMVPwireUniform = glGetUniformLocation(mWireframeDrawProgram, "MVP");
}

void cls_GraphicsWidget::InitBuffers(void)
{
	glGenVertexArrays(1, &mVAOshading);
	glGenBuffers(1, &mVBOshading);
	glGenBuffers(1, &mIBOwire);
}

void cls_GraphicsWidget::CreateProg(GLuint p_program, const std::vector<GLuint>& p_shaderList)
{
	// (Create the program outside)
	// Here - attach the shaders, link.

	for (size_t iLoop = 0; iLoop < p_shaderList.size(); iLoop++)
		glAttachShader(p_program, p_shaderList[iLoop]);

	glLinkProgram(p_program);

	GLint v_status;
	glGetProgramiv(p_program, GL_LINK_STATUS, &v_status);
	if (v_status == GL_FALSE) {
		GLint v_infoLogLength;
		glGetProgramiv(p_program, GL_INFO_LOG_LENGTH, &v_infoLogLength);

		GLchar *v_strInfoLog = new GLchar[v_infoLogLength + 1];
		glGetProgramInfoLog(p_program, v_infoLogLength, NULL, v_strInfoLog);
		qDebug() << "Linker failure:" << v_strInfoLog << endl;
		delete[] v_strInfoLog;
	}

	// Cleanup
	for (size_t iLoop = 0; iLoop < p_shaderList.size(); iLoop++)
		glDetachShader(p_program, p_shaderList[iLoop]);
}

GLuint cls_GraphicsWidget::CreateShader(GLenum p_eShaderType, const QString& p_strShaderFile)
{
	// Open and read input file with shader code
	QFile v_shaderFile(p_strShaderFile);
	QString v_fullShaderCode;
	QByteArray ba;
	char* v_cstrFullShaderCode;

	if (!v_shaderFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug() << "Error opening shader file:" << p_strShaderFile << endl;
	}
	else {
		QTextStream v_inStream(&v_shaderFile);
		v_fullShaderCode = v_inStream.readAll();

		ba = v_fullShaderCode.toLatin1();
		v_cstrFullShaderCode = ba.data();
	}

	// Debug output
	//qDebug() << "---------------------------------------------------------------------";
	//qDebug() << cstrFullShaderCode;
	//qDebug() << "---------------------------------------------------------------------";

	// Prepare and compile shader
	GLuint v_shader = glCreateShader(p_eShaderType);
	glShaderSource(v_shader, 1, (const GLchar**)&v_cstrFullShaderCode, NULL);
	glCompileShader(v_shader);

	// Get diagnostics info and print it in case of error
	GLint v_status;
	glGetShaderiv(v_shader, GL_COMPILE_STATUS, &v_status);

	QString v_strShaderType;
	switch (p_eShaderType) {
	case GL_VERTEX_SHADER: v_strShaderType = "vertex"; break;
	case GL_GEOMETRY_SHADER: v_strShaderType = "geometry"; break;
	case GL_FRAGMENT_SHADER: v_strShaderType = "fragment"; break;
	}

	if (v_status == GL_FALSE) {
		GLint v_infoLogLength;
		glGetShaderiv(v_shader, GL_INFO_LOG_LENGTH, &v_infoLogLength);

		GLchar *v_strInfoLog = new GLchar[v_infoLogLength + 1];
		glGetShaderInfoLog(v_shader, v_infoLogLength, NULL, v_strInfoLog);

		qDebug().nospace() << "Compile failure in " << v_strShaderType.toStdString().c_str() << " shader from " << p_strShaderFile << ": " << endl << v_strInfoLog;
		delete[] v_strInfoLog;
	}
	else {
		qDebug().nospace() << "Successfully compiled " << v_strShaderType.toStdString().c_str() << " shader from " << p_strShaderFile << ".";
	}

	// Finalize
	v_shaderFile.close();
	return v_shader;
}
