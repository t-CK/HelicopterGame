// Project
#include "Shader.h"
// STL
#include <iostream>
#include <sstream>
#include <fstream>
// Vendor
#include <glad/glad.h>

Shader::Shader(std::string vertexPath, std::string fragmentPath)
{
	// VERTEX
	
	// Create variables
	int status;
	std::string tmp;
	uint32_t fragmentShader, vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	// Read shader code from file and convert it into c-string
	tmp = ReadFile(vertexPath);
	const char* vertexSrc = tmp.c_str();

	// Compile shader
	glShaderSource(vertexShader, 1, &vertexSrc, NULL);
	glCompileShader(vertexShader);

	// Check for errors
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
	if (!status)
	{
		char infolog[512];
		glGetShaderInfoLog(vertexShader, 512, NULL, infolog);
		std::cout << "FAILED TO COMPILE SHADER : VERTEX\n" << infolog << std::endl;
	}

	// FRAGMENT

	tmp = ReadFile(fragmentPath).c_str();
	const char* fragmentSrc = tmp.c_str();

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

	// Create shader program
	m_ID = glCreateProgram();

	// Attach shaders and link program
	glAttachShader(m_ID, vertexShader);
	glAttachShader(m_ID, fragmentShader);
	glLinkProgram(m_ID);

	// Delete shaders, since they are no longer needed
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// Check for errors
	glGetProgramiv(m_ID, GL_LINK_STATUS, &status);
	if (!status)
	{
		char infolog[512];
		glGetProgramInfoLog(m_ID, 512, NULL, infolog);
		std::cout << "FAILED TO LINK PROGRAM:\n" << infolog << std::endl;
	}
}

void Shader::Bind()
{
	glUseProgram(m_ID);
}

void Shader::UnBind()
{
	glUseProgram(0);
}

std::string Shader::ReadFile(std::string& filePath) const
{
	std::ifstream fileStream;
	std::stringstream shaderStream;
	std::string line;

	fileStream.std::ifstream::open(filePath);
	while (std::getline(fileStream, line))
	{
		shaderStream << line << '\n';
	}
	fileStream.close();
	return shaderStream.str();
}

Shader::~Shader()
{
}
