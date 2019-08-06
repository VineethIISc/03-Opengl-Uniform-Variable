#include "CommonHeader.h"
#include "TestTriangle.h"

#include "GLWindow.h"

GLWindow::GLWindow()
{
	triangle = new TestTriangle;
}


GLWindow::~GLWindow()
{
	if(triangle)
		delete triangle;
}

void GLWindow::initializeGL()
{
	//initialise glew at first before using opengl functions
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		std::cout << "Failed to initialise the glew" << std::endl;
		exit(EXIT_FAILURE);
	}

	//opengl version and graphic card driver
	std::cout << "GL version: " << glGetString(GL_VERSION) << std::endl;

	//graphic card
	std::cout << "GL renderer: " << glGetString(GL_RENDERER) << std::endl;

	//background
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	 //black color

	//load data to GPU
	sendDataToGPU();
}

void GLWindow::sendDataToGPU()
{
	//load triangle data
	triangle->loadData();
}



void GLWindow::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	//draw objects
	drawObjects();

	//check for any error
	GLenum err = glGetError();
	if (err != GL_NO_ERROR)
	{
		std::cerr << "OpenGL error: " << err << std::endl;
	}
	
}


void GLWindow::drawObjects()
{
	//draw triangle
	triangle->render();
}


void GLWindow::resizeGL(int w, int h)
{
}


