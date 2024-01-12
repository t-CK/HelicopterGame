// OpenGL
#include <stb-image/stb_image.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// STL
#include <iostream>
#include <cstdint>
#include <sstream>
#include <fstream>
// Project
#include "Renderer/Texture.h"
#include "Renderer/Shader.h"
#include "Renderer/VAO.h"
#include "Renderer/VBO.h"
#include "Renderer/EBO.h"
#include "Window.h"
#include "Renderer/VertexBufferLayout.h"
#include "Renderer/Renderer.h"




int main()
{
	Window* window = new Window;
	if (!window->Init())
		return -1;

	VAO vao;
	VBO vbo;
	EBO ebo;

	vao.Bind();

	VertexBufferLayout layout;
	layout.PushFloat(3, false);
	layout.PushFloat(3, false);
	layout.PushFloat(2, false);

	vbo.Bind();
	vbo.AddData(layout);

	ebo.Bind();
	ebo.AddBuffer();

	Shader shader("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl");

	Texture texture("assets/sprites/ScreenChopper.png");
	texture.Bind();

	shader.SetInt("tex", 0);
	Renderer renderer(window);

	glClearColor(0.5f, 0.2f, 0.4f, 1.0f);
	// Game loop
	while (!window->GetClosed())
	{
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		renderer.BeginScene();
		glfwPollEvents();

		// Set transformations
		glm::mat4 u_Model = glm::mat4(1.0f);
		glm::mat4 u_View = glm::mat4(1.0f);
		u_View = glm::translate(u_View, glm::vec3(-3.3f, 0.0f, -3.0f));
		glm::mat4 u_Projection;
		u_Projection = glm::perspective(glm::radians(90.f), 800.0f / 600.0f, 0.1f, 100.0f);

		// Submit transformations to shader
		shader.SetMat4("u_Model", u_Model);
		shader.SetMat4("u_View", u_View);
		shader.SetMat4("u_Projection", u_Projection);

		shader.Bind();
		renderer.Submit(layout, vao, vbo, ebo);

		texture.Bind();

		renderer.EndScene();

	//	glfwSwapBuffers(window->GetNativeWindow());
	}

	delete window;

	return 0;
}
