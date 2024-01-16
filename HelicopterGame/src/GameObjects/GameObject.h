#include <glm/glm.hpp>
#include "../Renderer/VAO.h"
#include "../Renderer/VBO.h"
#include "../Renderer/VertexBufferLayout.h"
#include "../Renderer/EBO.h"
#include "../Renderer/Shader.h"
#include "../Renderer/Texture.h"

// Base class for game objects
class GameObject
{
public:
	GameObject() = default;

	// Virtual functions

	// Update object in every frame
	virtual void Tick(float deltaTime) = 0;
	virtual void Render() = 0;

	// Getters

	inline virtual glm::vec4 GetLocation() const { return m_Location; }
	inline virtual glm::vec4 GetRotation() const { return m_Rotation; }
	inline virtual glm::vec4 GetLocation() const { return m_Scale; }

protected:
	glm::vec4 m_Location;
	glm::vec4 m_Rotation;
	glm::vec4 m_Scale;
};