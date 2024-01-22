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

}

void StaticMeshComponent::Render()
{
	m_Renderer->Submit(m_Layout, m_VAO, m_VBO, m_EBO);
}

StaticMeshComponent::~StaticMeshComponent()
{
	delete m_Renderer;
}