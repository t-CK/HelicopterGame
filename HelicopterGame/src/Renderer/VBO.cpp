#include <glad/glad.h>
#include "VBO.h"
#include "VertexBufferLayout.h"

VBO::VBO()
{
	// Generate openGL buffer object and bind it
	glGenBuffers(1, &m_ID);
	Bind();
}

void VBO::AddData(float* buffer, size_t bufferSize, VertexBufferLayout& layout)
{
	m_Layout = &layout;
	
	// Add data to buffer and set vertex attributes
	glBufferData(GL_ARRAY_BUFFER, (bufferSize * sizeof(float)), buffer, GL_STATIC_DRAW);

	// Submit data in layout into openGL
	for (size_t i{}; i < layout.Elements.size(); i++)
	{
		glVertexAttribPointer(i, layout.Elements[i]->count, layout.Elements[i]->type,
			layout.Elements[i]->normalized, layout.Stride, (void*)layout.Elements[i]->offset);
		glEnableVertexAttribArray(i);
	}

}

void VBO::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VBO::UnBind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VBO::~VBO()
{
	glDeleteBuffers(1, &m_ID);
}