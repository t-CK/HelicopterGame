#include "MovingObject.h"

class InputComponent;
class Helicopter :
	public MovingObject
{
public:
	Helicopter(Renderer* renderer);

	virtual void Tick(float deltaTime) override;

	~Helicopter();
private:
	bool m_GoingUp = false;
	const float m_MovementSpeed = 5.f;
private:
	InputComponent* m_Input = nullptr;

	friend class InputComponent;
};