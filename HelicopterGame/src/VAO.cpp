#include "VAO.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

VAO::VAO()
{
	glGenVertexArrays(1, &m_ID);
}

void VAO::Bind()
{
	glBindVertexArray(m_ID);
}

void VAO::UnBind()
{
	glBindVertexArray(0);
}

VAO::~VAO()
{
	glDeleteVertexArrays(1, &m_ID);
}