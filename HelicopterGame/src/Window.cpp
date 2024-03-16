#include "Window.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Window* Window::s_Window = nullptr;

bool Window::Init()
{
	s_Window = this;

	if (!glfwInit())
	{
		std::cout << "FATAL : Failed to initialize glfw" << std::endl;
		return false;
	}
	std::cout << "Initialized glfw" << std::endl;

	// Set glfw context to openGL 3.3 Core profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create window and set context to it
	m_Wnd = glfwCreateWindow(800, 600, "Helicopter Game", NULL, NULL);
	if (!m_Wnd)
	{
		const char* msg;
		glfwGetError(&msg);
		std::cout << "Failed to create window:\n\t" << msg << std::endl;
		return false;
	}
	glfwMakeContextCurrent(m_Wnd);

	// Initialize glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "FATAL : failed to load gald" << std::endl;
		return false;
	}
	std::cout << "Initialized glad" << std::endl;
	glViewport(0, 0, 800, 600);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}

void Window::Update()
{
}

bool Window::GetClosed()
{
	return glfwWindowShouldClose(m_Wnd);
}

Window::~Window()
{
	glfwDestroyWindow(m_Wnd);
	glfwTerminate();
}