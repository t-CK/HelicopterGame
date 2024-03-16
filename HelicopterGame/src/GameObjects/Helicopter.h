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
	InputComponent* m_Input = nullptr;

	friend class InputComponent;
};