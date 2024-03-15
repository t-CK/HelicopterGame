#ifndef TEXTURE_COMPONENT_H
#define TEXTURE_COMPONENT_H

#include <string>
#include <vector>
#include "GameComponent.h"
#include "../Renderer/Texture.h"

class TextureComponent :
	public GameComponent
{
public:
	TextureComponent() { }

	void AddTexture(const std::string& texPath);

	virtual void Update() override;
	virtual void Init(class Renderer*) override { }

	~TextureComponent();
protected:
	std::vector<Texture*> m_Textures;
};

#endif // !TEXTURE_COMPONENT_H