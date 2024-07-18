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


	virtual ~MovingObject() { delete m_Movement; }
protected:
	float m_SpeedH = 0.001f;
	float m_SpeedV = 0.001f;

	MovementComponent* m_Movement;

	friend class MovementComponent;
};

#endif // !MOVING_OBJECT_H