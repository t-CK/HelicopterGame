// OpenGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>
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

	float vertecies[] = {
		 0.0f,  0.5f, 0.0f, // Top
		-0.5f, -0.5f, 0.0f,	// Bottom left
		 0.5f, -0.5f, 0.0f  // Bottom right
	};
	unsigned int indecies[] = {
		0, 1, 2
	};

	uint32_t vao, vbo, ebo;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertecies), vertecies, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indecies), indecies, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// SHADERS

	std::ifstream shaderStream;
	std::stringstream vshaderString, fshaderString;
	std::string line;

	shaderStream.std::ifstream::open("assets/vertex.glsl");
	while (std::getline(shaderStream, line))
	{
		vshaderString << line << '\n';
	}
	std::string tmp = vshaderString.str();
	const char* vertexSrc = tmp.c_str();
	shaderStream.close();

	uint32_t fragmentShader, vertexShader, shaderProgram;
	vertexShader =  glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, &vertexSrc, NULL);
	glCompileShader(vertexShader);
	
	int status;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
	if (!status)
	{
		char infolog[512];
		glGetShaderInfoLog(vertexShader, 512, NULL, infolog);
		std::cout << "FAILED TO COMPILE SHADER : VERTEX\n" << infolog << std::endl;
	}

	shaderStream.std::ifstream::open("assets/fragment.glsl");
	while (std::getline(shaderStream, line))
	{
		fshaderString << line << '\n';
	}
	tmp = fshaderString.str();
	const char* fragmentSrc = tmp.c_str();
	shaderStream.close();

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSrc, 0);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
	if (!status)
	{
		char infolog[512];
		glGetShaderInfoLog(fragmentShader, 512, NULL, infolog);
		std::cout << "FAILED TO COMPILE SHADER : FRAGMENT\n" << infolog << std::endl;
	}


	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
	if (!status)
	{
		char infolog[512];
		glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
		std::cout << "FAILED TO LINK PROGRAM:\n" << infolog << std::endl;
	}


	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();

		glUseProgram(shaderProgram);
		glBindVertexArray(vao);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (const void*)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
	}

	return 0;
}