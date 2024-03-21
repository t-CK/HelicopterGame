#include "Helicopter.h"
#include "../Components/StaticMeshComponent.h"
#include "../Components/InputComponent.h"
#include "../Components/CameraComponent.h"

Helicopter::Helicopter(Renderer* renderer)
{
	float vert[] = {
		// Vertex pos		Color			  Texture coordinates
		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, // Top right
		-0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // Top left
		-0.5f, -0.5f, 0.0f,	0.0f, 1.0f, 0.0f, 1.0f, 1.0f, // Bottom left
		 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f  // Bottom right
	};
	 unsigned int indecies[] = {
		0, 1, 2,
		2, 3, 0
	};

	// Initialize necessary components
	m_Input = new InputComponent(this);
	m_Mesh.Init(m_Renderer);
	m_Mesh.AddMesh(vert, indecies, 8);
	m_Input->Init(m_Renderer);

	m_Shader.LoadShader("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl");

	m_Texture.AddTexture("assets/sprites/ScreenChopper.png");
	m_Texture.Update();

	m_Shader.SetInt("tex", 0);
	m_Renderer = renderer;

	m_Mesh.m_Location.y = 0.f;
	m_Mesh.m_Location.z = -0.5f;
	m_Mesh.m_Location.x = -0.85f;

	m_Camera = new CameraComponent(this);
}

void Helicopter::Tick(float deltaTime)
{
	m_GoingUp ? m_Movement->Move(m_SpeedV, Axis::Y) : m_Movement->Move(-m_SpeedV, Axis::Y);
}

void Helicopter::UpdateComponents()
{
	m_Input->Update();
	m_Movement->Update();
	m_Mesh.Update();
	m_Texture.Update();
}

void Helicopter::Render()
{
	printf("Helicopter: {0}", m_Mesh.GetLocation());
	m_Mesh.Render();
	// Set transformations
	//glm::mat4 u_Model = glm::mat4(1.0f);
	//u_Model = glm::translate(u_Model, m_Mesh.GetLocation());
	//u_Model = glm::rotate(u_Model, glm::radians(m_Mesh.GetRotation().x), m_Mesh.GetRotation());
	//u_Model = glm::scale(u_Model, m_Mesh.GetScale());

//	glm::mat4 u_View = glm::mat4(1.0f);
//	u_View = glm::translate(u_View, glm::vec3(-3.f, 0.0f, -3.0f));
	//glm::mat4 u_Projection;
	//u_Projection = glm::perspective(glm::radians(90.f), 800.0f / 600.0f, 0.1f, 100.0f);

	// Submit transformations to shader
	m_Shader.SetMat4("u_Model", m_Mesh.GetModel());
	m_Shader.SetMat4("u_View", m_Camera->GetCamera()->GetView());
	m_Shader.SetMat4("u_Projection", m_Mesh.GetModel());

	m_Shader.Bind();

	m_Texture.Update();
}

Helicopter::~Helicopter()
{
	delete m_Input;
	delete m_Camera;
}
