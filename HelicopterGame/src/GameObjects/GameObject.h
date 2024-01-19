#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
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

	// Update object in every frame
	virtual void Tick(float deltaTime) = 0;

	// Render sprite at end of the frame
	inline void Render() 
	{ 
		m_Renderer->Submit(m_Layout, m_VAO, m_VBO, m_EBO);

		// Set transformations
		glm::mat4 u_Model = glm::mat4(1.0f);
		glm::mat4 u_View = glm::mat4(1.0f);
		u_View = glm::translate(u_View, glm::vec3(-3.3f, 0.0f, -3.0f));
		glm::mat4 u_Projection;
		u_Projection = glm::perspective(glm::radians(90.f), 800.0f / 600.0f, 0.1f, 100.0f);

		// Submit transformations to shader
		m_Shader.SetMat4("u_Model", u_Model);
		m_Shader.SetMat4("u_View", u_View);
		m_Shader.SetMat4("u_Projection", u_Projection);

		m_Shader.Bind();

		m_Texture.Bind();
	}

	// Getters

	inline glm::vec4 GetLocation() const { return m_Location; }
	inline glm::vec4 GetRotation() const { return m_Rotation; }
	inline glm::vec4 GetScale() const { return m_Scale; }

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
#endif // !GAME_OBJECT_H