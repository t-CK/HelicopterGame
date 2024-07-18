#include "StaticMeshComponent.h"

StaticMeshComponent::StaticMeshComponent()
{
	m_Name = "Static mesh component";
}

void StaticMeshComponent::AddMesh(float* vertexPos, unsigned int* indecies, unsigned int indexCount, bool faceRight)
{
	m_VAO.Bind();

	m_Layout.PushFloat(3, false);
	m_Layout.PushFloat(3, false);
	m_Layout.PushFloat(2, false);

	m_VBO.Bind();
	m_VBO.AddData(vertexPos, (indexCount * 4), m_Layout);

	m_EBO.Bind();
	m_EBO.AddBuffer(indecies, indexCount);

	// Set vectors
	m_Right = faceRight ? glm::vec3(1.f, 0.f, 0.f) : glm::vec3(-1.f, 0.f, 0.f);
	m_Up = glm::vec3(0.f, 1.f, 0.f);
	m_Forward = glm::vec3(0.f, 0.f, 1.f);

	// Set transforms
	m_Location = glm::vec3(1.f);
	m_Rotation = glm::vec3(1.f);
	m_Scale = glm::vec3(1.f);
}

void StaticMeshComponent::Render()
{
	m_Renderer->Submit(m_Layout, m_VAO, m_VBO, m_EBO);
}

StaticMeshComponent::~StaticMeshComponent()
{
	delete m_Renderer;
}