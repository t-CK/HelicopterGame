#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "../Window.h"
#include "shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "VertexBufferLayout.h"
#include "Texture.h"

#include <iostream>
void Renderer::BeginScene()
{
	RendererFunc::RenderClear();
}

void Renderer::Submit(VertexBufferLayout& layout, VAO& vao, VBO&, EBO& ebo)
{
	vao.Bind();

	for (size_t i{}; i < layout.Elements.size(); i++)
	{
		glVertexAttribPointer(i, layout.Elements[i]->count, layout.Elements[i]->type,
			layout.Elements[i]->normalized, layout.Stride, (void*)layout.Elements[i]->offset);
		glEnableVertexAttribArray(i);
	}
	glDrawElements(GL_TRIANGLES, ebo.GetCount(), GL_UNSIGNED_INT, 0);
}

void Renderer::EndScene()
{
	RendererFunc::SwapBuffers(m_Window->GetNativeWindow());
}
