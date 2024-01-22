#ifndef STATIC_MESH_COMPONENT_H
#define STATIC_MESH_COMPONENT_H

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

	//float* GetVertecies() const { return m_Vertecies; }
	//int* GetIndecies() const { return m_Indecies; }

	~StaticMeshComponent();
protected:
	VAO m_VAO;
	VBO m_VBO;
	EBO m_EBO;
	VertexBufferLayout m_Layout;
	Renderer* m_Renderer;
};

#endif // !STATIC_MESH_COMPONENT_H