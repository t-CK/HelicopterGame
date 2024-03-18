#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

#include "GameComponent.h"

enum Axis
{
	X = 1, Y = 2, Z = 3
};

class MovingObject;
class MovementComponent :
	public GameComponent
{
public:
	MovementComponent(MovingObject* owner);

	// Move the owning object horizontaly
	// Takes in the value of desired movement and axis as parameter
	void Move(float value, Axis axis);
	// Rotate the owning object verticaly along axis
	// Takes in the value of desired rotation and axis as parameter
	void Rotate(float value, Axis axis);
	// Move the owning object verticaly
	// Takes in the value of desired movement as parameter

	virtual void Init(class Renderer*) override { }
	virtual void Update() override { }

	~MovementComponent();
protected:
	MovingObject* m_Owner;
};
#endif // !MOVEMENT_COMPONENT_H