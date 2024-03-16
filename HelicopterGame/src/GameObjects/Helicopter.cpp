#include "Helicopter.h"
#include "../Components/StaticMeshComponent.h"
#include "../Components/InputComponent.h"

Helicopter::Helicopter(Renderer* renderer)
{
	float vert[] = {
		// Vertex pos		Color			  Texture coordinates
		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, // Top right
		-0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // Top left
		-0.5f, -0.5f, 0.0f,	0.0f, 1.0f, 0.0f, 1.0f, 1.0f, // Bottom left
		 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f  // Bottom right
	};
	 unsigned int indecies[] = {
		0, 1, 2,
		2, 3, 0
	};

	// Initialize necessary components
	m_Input = new InputComponent(this);
	m_Mesh.Init(m_Renderer);
	m_Mesh.AddMesh(vert, indecies, 8);
	m_Input->Init(m_Renderer);

	m_Shader.LoadShader("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl");

	m_Texture.AddTexture("assets/sprites/ScreenChopper.png");
	m_Texture.Update();

	m_Shader.SetInt("tex", 0);
	m_Renderer = renderer;
}

void Helicopter::Tick(float deltaTime)
{
}

Helicopter::~Helicopter()
{
}
