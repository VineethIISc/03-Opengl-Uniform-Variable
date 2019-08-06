#include "Shader.h"
#include "TestTriangle.h"

TestTriangle::TestTriangle(): VBO(0), VAO(0), objectShader(nullptr)
{
	//number of vertices
	numVertices = 3; 
	
	//create vertices
	init();

	
}


TestTriangle::~TestTriangle()
{
	if (VAO)
		glDeleteVertexArrays(1, &VAO);
	if (VBO)
		glDeleteBuffers(1, &VBO);

}

GLuint TestTriangle::getVBO()
{
	return VBO;
}

GLuint TestTriangle::getVAO()
{
	return VAO;
}

void TestTriangle::init()
{
	//create three vertices for the triangle
	vertices.push_back(Vector3f(0.5f, 0.0f, 0.0f));
	vertices.push_back(Vector3f(1.0f, 0.0f, 0.0f));
	vertices.push_back(Vector3f(0.0f, 1.0f, 0.0f));
}

void TestTriangle::loadData()
{
	//create vertex array objects
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	//bind VAO, VBO
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//allocate memory and copy data to GPU from CPU
	GLsizeiptr size = sizeof(Vector3f) * numVertices;
	glBufferData(GL_ARRAY_BUFFER, size, vertices[0], GL_STATIC_DRAW);

	//assign vertex attrib pointer and information about data
	glEnableVertexAttribArray(0);		//position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//unbind VAO, VBO
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(0);

	//create shader do after 
	objectShader = new Shader("shaders/vsTestTriangle.txt", "shaders/fsTestTriangle.txt");

	
}

void TestTriangle::render()
{
	//using the shader program
	objectShader->Bind();

	//set the uniform variables
	Vector3f c(0.0f, 1.0f, 0.0f);
	objectShader->setUniformVector("color", c);

	//bind the VAO and call draw function
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, numVertices);
	glBindVertexArray(0);
	objectShader->Unbind();
}

