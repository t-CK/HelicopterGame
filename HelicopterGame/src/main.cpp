// Project
#include "Texture.h"
#include "Shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
// OpenGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb-image/stb_image.h>
// glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// STL
#include <iostream>
#include <cstdint>
#include <sstream>
#include <fstream>


int main()
{
	if (!glfwInit())
	{
		std::cout << "FATAL : Failed to initialize glfw" << std::endl;
		return -1;
	}
	std::cout << "Initialized glfw" << std::endl;
	
	// Set glfw context to openGL 3.3 Core profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create window and set context to it
	GLFWwindow* window = glfwCreateWindow(800, 600, "Helicopter Game", NULL, NULL);
	if (!window)
	{
		const char* msg;
		glfwGetError(&msg);
		std::cout << "Failed to create window:\n\t" << msg << std::endl;
	}
	glfwMakeContextCurrent(window);

	// Initialize glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "FATAL : failed to load gald" << std::endl;
		return -1;
	}
	std::cout << "Initialized glad" << std::endl;
	glViewport(0, 0, 800, 600);


	VAO vao;
	VBO vbo;
	EBO ebo;

	vao.Bind();

	vbo.Bind();
	vbo.AddData();

	ebo.Bind();
	ebo.AddBuffer();

	Shader shader("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl");

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	Texture texture("assets/sprites/ScreenChopper.png");
	texture.Bind();

	shader.SetInt("tex", 0);


	glClearColor(0.5f, 0.2f, 0.4f, 1.0f);
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwPollEvents();

		shader.Bind();
		vao.Bind();

		// Set transformations
		glm::mat4 u_Model = glm::mat4(1.0f);
		glm::mat4 u_View = glm::mat4(1.0f);
		u_View = glm::translate(u_View, glm::vec3(0.0f, 0.0f, -3.0f));
		glm::mat4 u_Projection;
		u_Projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

		// Submit transformations to shader
		shader.SetMat4("u_Model", u_Model);
		shader.SetMat4("u_View", u_View);
		shader.SetMat4("u_Projection", u_Projection);
	
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (const void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (const void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);
		ebo.Bind();

		texture.Bind();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
	}

	return 0;
}
