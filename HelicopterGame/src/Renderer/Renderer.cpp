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

namespace RendererFunc
{
	void SetClearColor() { glClearColor(0.5f, 0.2f, 0.4f, 1.0f); }
	void RenderClear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }
	void SwapBuffers(GLFWwindow* wnd) { glfwSwapBuffers(wnd); }
}

Renderer::Renderer(Window* wnd) :
	m_Window(wnd)
{
	RendererFunc::SetClearColor();
}

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
