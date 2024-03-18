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

	void MoveX(float value) { m_Movement->Move(value * m_SpeedH, Axis::X); }
	void MoveY(float value) { m_Movement->Move(value * m_SpeedV, Axis::Y); }
protected:
	float m_SpeedH = 0.01f;
	float m_SpeedV = 0.01f;

	MovementComponent* m_Movement;

	friend class MovementComponent;
};

#endif // !MOVING_OBJECT_H