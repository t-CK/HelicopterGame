#include <glad/glad.h>
#include "VBO.h"
#include "VertexBufferLayaut.h"

VBO::VBO()
{
	// Generate openGL buffer object and bind it
	glGenBuffers(1, &m_ID);
	Bind();
}

void VBO::AddData(VertexBufferLayout& layout) const
{
	// At the time we only need uniform sized meshes, so vertex count can be fixed

	// Create array of  vertecies
	float vert[] = {
		// Vertex pos		Color			  Texture coordinates
		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, // Top right
		-0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // Top left
		-0.5f, -0.5f, 0.0f,	0.0f, 1.0f, 0.0f, 1.0f, 1.0f, // Bottom left
		 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f  // Bottom right
	};

	
	// Add data to buffer and set vertex attributes
	glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);

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