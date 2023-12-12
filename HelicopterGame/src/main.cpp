// OpenGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// STL
#include <iostream>
#include <cstdint>

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

	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	return 0;
}