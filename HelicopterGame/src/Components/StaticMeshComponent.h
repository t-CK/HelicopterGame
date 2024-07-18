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
	void AddMesh(float* vertexPos, unsigned int* indecies, unsigned int indexCount, bool faceRight);
	virtual void Update() { }
	void Render();

	inline glm::vec3 GetLocation() const { return m_Location; }
	inline glm::vec3 GetRotation() const { return m_Rotation; }
	inline glm::vec3 GetScale() const { return m_Scale; }

	inline glm::vec3 GetForwardVector() const { return m_Forward; }
	inline glm::vec3 GetUpVector()		const { return m_Up; }
	inline glm::vec3 GetRightVector()	const { return m_Right; }

	inline void SetLocation(glm::vec3 newPos) { m_Location = newPos; }

	~StaticMeshComponent();

public:
	glm::vec3 m_Location;
	glm::vec3 m_Rotation;
	glm::vec3 m_Scale;

	glm::vec3 m_Forward;
	glm::vec3 m_Right;
	glm::vec3 m_Up;

protected:
	VAO m_VAO;
	VBO m_VBO;
	EBO m_EBO;
	VertexBufferLayout m_Layout;
	Renderer* m_Renderer;
};

#endif // !STATIC_MESH_COMPONENT_H