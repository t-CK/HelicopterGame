#include "VBO.h"
#include <glad/glad.h>

VBO::VBO()
{
	// Generate openGL buffer object and bind it
	glGenBuffers(1, &m_ID);
	Bind();
}

void VBO::AddData() const
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
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