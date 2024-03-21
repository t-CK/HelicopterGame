#include <glm/gtc/matrix_transform.hpp>
#include "StaticMeshComponent.h"

StaticMeshComponent::StaticMeshComponent()
{
	m_Name = "Static mesh component";
}

void StaticMeshComponent::AddMesh(float* vertexPos, unsigned int* indecies, unsigned int indexCount)
{
	m_VAO.Bind();

	m_Layout.PushFloat(3, false);
	m_Layout.PushFloat(3, false);
	m_Layout.PushFloat(2, false);

	m_VBO.Bind();
	m_VBO.AddData(vertexPos, (indexCount * 4), m_Layout);

	m_EBO.Bind();
	m_EBO.AddBuffer(indecies, indexCount);

	m_Location = glm::vec3(1.f);
	m_Rotation = glm::vec3(1.f);
	m_Scale = glm::vec3(1.f);

	u_Model = glm::mat4(1.0f);
}

void StaticMeshComponent::SetLocation(glm::vec3 loc)
{
	m_Location = loc;
}

void StaticMeshComponent::SetRotation(glm::vec3 rot)
{
	m_Rotation = rot;
}

void StaticMeshComponent::SetScale(glm::vec3 s)
{
	m_Scale = s;
}

void StaticMeshComponent::Update()
{
	// Update u_Model transforms
	u_Model = glm::translate(u_Model, m_Location);
	u_Model = glm::rotate(u_Model, glm::radians(m_Rotation.x), m_Rotation);
	u_Model = glm::scale(u_Model, m_Scale);
}

void StaticMeshComponent::Render()
{
	m_Renderer->Submit(m_Layout, m_VAO, m_VBO, m_EBO);
}

StaticMeshComponent::~StaticMeshComponent()
{
	delete m_Renderer;
}