#ifndef STATIC_MESH_COMPONENT_H
#define STATIC_MESH_COMPONENT_H

#include <glm/glm.hpp>

#include "GameComponent.h"
#include "../Renderer/VAO.h"
#include "../Renderer/VBO.h"
#include "../Renderer/EBO.h"
#include "../Renderer/VertexBufferLayout.h"
#include "../Renderer/Renderer.h"

class StaticMeshComponent :
	public GameComponent
{
public:
	StaticMeshComponent();
	inline virtual void Init(class Renderer* renderer) override { m_Renderer = renderer; }

	// Add 2d plane into game world
	void AddMesh(float* vertexPos, unsigned int* indecies, unsigned int indexCount);
	virtual void Update() { }
	void Render();

	inline glm::vec3 GetLocation() const { return m_Location; }
	inline glm::vec3 GetRotation() const { return m_Rotation; }
	inline glm::vec3 GetScale() const { return m_Scale; }

	~StaticMeshComponent();

private:
	glm::vec3 m_Location;
	glm::vec3 m_Rotation;
	glm::vec3 m_Scale;

protected:
	VAO m_VAO;
	VBO m_VBO;
	EBO m_EBO;
	VertexBufferLayout m_Layout;
	Renderer* m_Renderer;
};

#endif // !STATIC_MESH_COMPONENT_H