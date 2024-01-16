#include <glm/glm.hpp>
#include "../Renderer/VAO.h"
#include "../Renderer/VBO.h"
#include "../Renderer/VertexBufferLayout.h"
#include "../Renderer/EBO.h"
#include "../Renderer/Shader.h"
#include "../Renderer/Texture.h"
#include "../Renderer/Renderer.h"

// Base class for game objects
class GameObject
{
public:
	GameObject() = default;
	GameObject(Renderer* renderer) { }

	// Virtual functions

	// Update object in every frame
	virtual void Tick(float deltaTime) = 0;

	// Render sprite at end of the frame
	inline void Render() { m_Renderer->Submit(m_Layout, m_VAO, m_VBO, m_EBO); }

	// Getters

	inline virtual glm::vec4 GetLocation() const { return m_Location; }
	inline virtual glm::vec4 GetRotation() const { return m_Rotation; }
	inline virtual glm::vec4 GetLocation() const { return m_Scale; }

protected:
	glm::vec4 m_Location;
	glm::vec4 m_Rotation;
	glm::vec4 m_Scale;

	VAO m_VAO;
	VBO m_VBO;
	EBO m_EBO;
	VertexBufferLayout m_Layout;
	Shader m_Shader;
	Texture m_Texture;
	Renderer* m_Renderer;
};