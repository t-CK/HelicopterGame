#include "Helicopter.h"

Helicopter::Helicopter(Renderer* renderer)
{

	m_VAO.Bind();

	m_Layout.PushFloat(3, false);
	m_Layout.PushFloat(3, false);
	m_Layout.PushFloat(2, false);

	m_VBO.Bind();
	m_VBO.AddData(m_Layout);

	m_EBO.Bind();
	m_EBO.AddBuffer();

	m_Shader.LoadShader("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl");

	m_Texture.Create("assets/sprites/ScreenChopper.png");
	m_Texture.Bind();

	m_Shader.SetInt("tex", 0);
	m_Renderer = renderer;
}

void Helicopter::Tick(float deltaTime)
{
}

void Helicopter::MoveH(float value)
{
}

void Helicopter::MoveV(float value)
{
}

Helicopter::~Helicopter()
{
}
