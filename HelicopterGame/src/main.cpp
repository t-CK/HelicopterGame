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
	glBlendFunc(GL_SOURCE0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	unsigned int texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//
//	int width, height, nChannels;
//	unsigned char* data = stbi_load("assets/sprites/bunnysheet5.png", &width, &height, &nChannels, STBI_rgb_alpha);
//
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//		std::cout << "Failed to load texture" << std::endl;
//
//	stbi_image_free(data);
	Texture texture("assets/sprites/ScreenChopper.png");
	texture.Bind();

	shader.SetInt("tex", 0);


	glClearColor(0.5f, 0.2f, 0.4f, 1.0f);
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();

		shader.Bind();
		vao.Bind();

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
