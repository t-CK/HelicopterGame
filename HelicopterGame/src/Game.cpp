#include "Game.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/Helicopter.h"
#include "Window.h"
#include "Renderer/Renderer.h"
#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

Game* Game::s_Game = nullptr;

bool Game::Init()
{
	s_Game = this;

	m_Wnd = Window::Get();

	m_Renderer = new Renderer;
	m_Player = new Helicopter(m_Renderer);
	m_Camera = new Camera;

	// Camera setup
//	m_CameraRight = glm::vec3(1.f, 0.f, 0.f);
//	m_CameraUp = glm::vec3(0.f, 1.f, 0.f);
//	m_CameraForward = glm::vec3(0.f, 0.f, 1.f);
//
//	m_CamPos = glm::vec3(0.f, 0.f, -3.f);
//	m_View = glm::lookAt(m_CameraForward, m_CamPos, m_CameraUp);
//
//	m_Projection = glm::perspective(glm::radians(90.f), 800.0f / 600.0f, 0.1f, 100.0f);
	return true;
}

void Game::Loop()
{
	while (!m_Wnd->GetClosed())
	{
		Update();
		m_Camera->Update();
		Render();
//		m_CamPos += m_CameraRight * -0.001f;
//		m_View = glm::lookAt(m_CameraForward, m_CamPos, m_CameraUp);
	}
}

void Game::AddObject(GameObject* object)
{
	auto obj = std::make_shared<GameObject*>(object);
	m_Objects.push_back(dynamic_cast<GameObject*>(object));
}

void Game::Update()
{	
	// Update delta time
	m_Renderer->BeginScene();
	glfwPollEvents();

	m_Player->Tick(0.0f);
}

void Game::Render()
{
	m_Player->Render();

	m_Renderer->EndScene();
}

Game::~Game()
{
	for (auto obj : m_Objects)
		delete obj;
	delete m_Camera;
	delete m_Renderer;
}