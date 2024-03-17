#include "GameComponent.h"

class Helicopter;
class Renderer;
class InputComponent :
	public GameComponent
{
public:
	InputComponent(Helicopter* owner) :
		m_Owner(owner) { m_Name = "InputComponent"; }

	virtual void Init(Renderer* renderer) override;
	virtual void Update() override { }

	~InputComponent() { delete m_Owner; }
private:
	void HandleInput(int key, int action);
protected:
	Helicopter* m_Owner;
};