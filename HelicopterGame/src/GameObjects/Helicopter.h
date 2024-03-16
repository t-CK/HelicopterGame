#include "MovingObject.h"

class Helicopter :
	public MovingObject
{
public:
	Helicopter(Renderer* renderer);

	virtual void Tick(float deltaTime) override;


	~Helicopter();
private:
};