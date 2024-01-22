#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "EBO.h"
#include <glad/glad.h>
#include <string>

EBO::EBO()
{
	glGenBuffers(1, &m_ID);
	Bind();
}

void EBO::AddBuffer(unsigned int* indexBuffer, unsigned int indexCount)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (indexCount * sizeof(unsigned int)), indexBuffer, GL_STATIC_DRAW);

	m_Count += indexCount;
}

void EBO::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void EBO::UnBind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

EBO::~EBO()
{
	glDeleteBuffers(1, &m_ID);
}