#include <chrono>
#include "Game.h"
#include "Window.h"
#include "Renderer/Renderer.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/MovingObject.h"
#include "GameObjects/Helicopter.h"

Game* Game::s_Game = nullptr;

Game::Game()
{
	s_Game = this;
	m_Window = new Window();
	m_Renderer = new Renderer(m_Window);
}

void Game::AddObject()
{

}

void Game::RemoveObject()
{

}

Game::~Game()
{
	// Delete window and renderer from memory
	delete m_Window;
	delete m_Renderer;

	// Clear any game objects in m_Objects vector from memory
	for (auto obj : m_Objects)
		delete obj;
}