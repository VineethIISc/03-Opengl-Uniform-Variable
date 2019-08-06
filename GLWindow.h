#ifndef GL_WINDOW_H
#define GL_WINDOW_H

#include <QtWidgets/qopenglwidget.h>

class TestTriangle;

class GLWindow: public QOpenGLWidget
{
public:
	GLWindow();
	~GLWindow();

protected:
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int w, int h) override;

private:
	TestTriangle* triangle;

private:
	void sendDataToGPU();
	void drawObjects();
};
#endif

