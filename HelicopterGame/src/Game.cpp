#include "Game.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/Helicopter.h"
#include "Window.h"
#include "Renderer/Renderer.h"

Game* Game::s_Game = nullptr;

bool Game::Init()
{
	s_Game = this;

	m_Wnd = Window::Get();

	m_Renderer = new Renderer;
	m_Player = new Helicopter(m_Renderer);

	return true;
}

void Game::Loop()
{
	while (!m_Wnd->GetClosed())
	{
		Update();
		Render();
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
	delete m_Renderer;
}