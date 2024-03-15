#include "TextureComponent.h"

void TextureComponent::AddTexture(const std::string& texPath)
{
	Texture* tex = new Texture;
	tex->Create(texPath);
	tex->Bind();
	m_Textures.push_back(tex);
}

void TextureComponent::Update()
{
	for (auto tex : m_Textures)
	{
		tex->Bind();
	}
}

TextureComponent::~TextureComponent()
{
	for (auto tex : m_Textures)
		delete tex;
}