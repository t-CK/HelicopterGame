#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H

#include "GameObject.h"

// Base class for moving sprites in game
// Derived from GameObject
class MovingObject :
	public GameObject
{
public:
	void MoveH(float value) { }
	void MoveV(float value) { }
protected:
	float m_SpeedH;
	float m_SpeedV;
};

#endif // !MOVING_OBJECT_H