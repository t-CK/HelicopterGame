#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H

#include "GameObject.h"
#include "../Components/MovementComponent.h"

// Base class for moving sprites in game
// Derived from GameObject
class MovingObject :
	public GameObject
{
public:
	MovingObject() { m_Movement = new MovementComponent(this); }

	void MoveX(float value)
	{
		
	}
	void MoveY(float value)
	{
		if ((m_Mesh.GetLocation().y <= 1.f) && (m_Mesh.GetLocation().y >= -1.f))
			m_Movement->Move(value * 0.01f, Axis::Y);
	}
protected:
	float m_SpeedH = 0.001f;
	float m_SpeedV = 0.001f;

	MovementComponent* m_Movement;

	friend class MovementComponent;
};

#endif // !MOVING_OBJECT_H