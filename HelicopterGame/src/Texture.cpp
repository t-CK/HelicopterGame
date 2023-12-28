#include "Texture.h"

#ifndef STB_IMAGE_IMPLEMENTATION
	#define STB_IMAGE_IMPLEMENTATION
#endif // !STB_IMAGE_IMPLEMENTATION
#include <stb-image/stb_image.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

Texture::Texture(const std::string& filePath)
{
	glGenTextures(1, &m_ID);
	glBindTexture(GL_TEXTURE_2D, m_ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	m_Source = stbi_load(filePath.c_str(), &m_Width, &m_Height, &m_BitsPerPixel, STBI_rgb_alpha);
	if (!m_Source)
	{
		std::cout << "Failed to load texture" << std::endl;
		return;
	}
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Source);
	glGenerateMipmap(GL_TEXTURE_2D);
	
}

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_ID);
}

void Texture::UnBind()
{
}

Texture::~Texture()
{
	stbi_image_free(m_Source);
	glDeleteTextures(1, &m_ID);
}
