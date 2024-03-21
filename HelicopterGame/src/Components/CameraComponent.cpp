#include <glm/glm.hpp>
#include "CameraComponent.h"
#include "../GameObjects/GameObject.h"
#include "../Game.h"

CameraComponent::CameraComponent(GameObject* owner) :
	m_Owner(owner)
{
	m_Name = "CameraComponent";
	// We need only 1 camera to game, so camera may be retrieved from Game class
	m_Camera = Game::Get()->GetCamera();
}

void CameraComponent::Update()
{
	// Get player location on current frame and negate component location to get player movement
	float movementX = m_Owner->GetPos().x -  m_Location.x;
	// Update component location
	m_Location.x += movementX;
	// Move camera with component
	m_Camera->MoveX(movementX);
}

void CameraComponent::Render()
{
	m_Camera->Render();
}

CameraComponent::~CameraComponent()
{
	delete m_Owner;
	delete m_Camera;
}