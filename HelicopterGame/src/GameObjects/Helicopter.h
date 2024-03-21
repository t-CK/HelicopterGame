#include "MovingObject.h"

class InputComponent;
class Helicopter :
	public MovingObject
{
public:
	Helicopter(Renderer* renderer);

	virtual void Tick(float deltaTime) override;
	virtual void UpdateComponents();
	virtual void Render();

	~Helicopter();
private:
	bool m_GoingUp = false;
private:
	InputComponent* m_Input = nullptr;
	class CameraComponent* m_Camera = nullptr;

	friend class InputComponent;
};