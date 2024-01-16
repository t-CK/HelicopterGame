#include "GameObject.h"

class Helicopter :
	public GameObject
{
public:
	Helicopter(Renderer* renderer);

	virtual void Tick(float deltaTime) override;

	void MoveH(float value);
	void MoveV(float value);

	~Helicopter();
private:
	float m_SpeedH;
	float m_SpeedV;
};