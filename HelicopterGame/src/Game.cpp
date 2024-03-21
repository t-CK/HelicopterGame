#include <chrono>
#include "Game.h"
#include "Window.h"
#include "Renderer/Renderer.h"
#include "Camera.h"
#include "GameObjects/GameObject.h"
#include <iostream>
#include "GameObjects/MovingObject.h"
#include "GameObjects/Helicopter.h"

Game* Game::s_Game = nullptr;

Game::Game()
{
	s_Game = this;
	m_Window = new Window();
	m_Window->Init();
	m_Renderer = new Renderer();
	m_Camera = new Camera(m_Renderer);
	m_Objects.push_back(new Helicopter(m_Renderer));
	m_Helicopter = new Helicopter(m_Renderer);
}

void Game::Update()
{
	// Game loop
	while (!m_Window->GetClosed())
	{
		m_Renderer->BeginScene();
		glfwPollEvents();

		m_Helicopter->Tick(0.0f);
		for (auto obj : m_Objects)
		{
			obj->Tick(0.0);
			obj->UpdateComponents();
		}

		m_Helicopter->Render();

		for (auto obj : m_Objects)
			obj->Render();



		m_Renderer->EndScene();
	}
}

void Game::AddObject()
{

}

void Game::RemoveObject()
{

}

Game::~Game()
{
	// Delete camera, window and renderer from memory
	delete m_Camera;
	delete m_Renderer;
	delete m_Window;

	// Clear any game objects in m_Objects vector from memory
	for (auto obj : m_Objects)
		delete obj;
}