#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb-image/stb_image.h>

#include <glad/glad.h>

#include <iostream>

Texture::Texture(const std::string& filePath)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	m_Source = stbi_load(filePath.c_str(), &m_Width, &m_Height, &m_BitsPerPixel, STBI_rgb_alpha);
	if (!m_Source)
	{
		std::cout << "Failed to load texture" << std::endl;
		return;
	}
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Source);

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
