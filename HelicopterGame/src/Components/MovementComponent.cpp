#include <glm/glm.hpp>
#include "MovementComponent.h"
#include "../GameObjects/MovingObject.h"

MovementComponent::MovementComponent(MovingObject* owner) :
	m_Owner(owner)
{
	m_Name = "MovemenComponent";
}

void MovementComponent::Move(float value, Axis axis)
{
	switch (axis)
	{
	case X: { m_Owner->m_Mesh.m_Location.x += value; break; }
	case Y: { m_Owner->m_Mesh.m_Location.y += value; break; }
	case Z: { m_Owner->m_Mesh.m_Location.z += value; break; }
	}
}

void MovementComponent::Rotate(float value, Axis axis)
{
	switch (axis)
	{
	case X: { m_Owner->m_Mesh.m_Rotation.x += value; break; }
	case Y: { m_Owner->m_Mesh.m_Rotation.y += value; break; }
	case Z: { m_Owner->m_Mesh.m_Rotation.z += value; break; }
	}
}

MovementComponent::~MovementComponent()
{
	delete m_Owner;
}