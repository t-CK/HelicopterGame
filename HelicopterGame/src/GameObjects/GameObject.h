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
#include "../Components/StaticMeshComponent.h"
#include "../Components/TextureComponent.h"
#include "../Game.h"
#include "../Camera.h"

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
		m_Mesh.Render();

		// Set transformations
		glm::mat4 u_Model = glm::mat4(1.0f);
		u_Model = glm::translate(u_Model, m_Mesh.GetLocation());
		u_Model = glm::rotate(u_Model, glm::radians(m_Mesh.GetRotation().x), m_Mesh.GetRotation());
		u_Model = glm::scale(u_Model, m_Mesh.GetScale());

		// Get the Camera pointer from Game
		Camera* cam = Game::Get()->GetCamera();

		// Submit transformations to shader
		m_Shader.SetMat4("u_Model", u_Model);
		// Set u_View and u_Projection uniforms in shader
		m_Shader.SetMat4("u_View", cam->GetView());
		m_Shader.SetMat4("u_Projection", cam->GetProjection());

		m_Shader.Bind();

		m_Texture.Update();
	}


	virtual ~GameObject() { delete m_Renderer; }

protected:
	VertexBufferLayout m_Layout;
	Shader m_Shader;
	Renderer* m_Renderer;

	StaticMeshComponent m_Mesh;
	TextureComponent m_Texture;
};
#endif // !GAME_OBJECT_H