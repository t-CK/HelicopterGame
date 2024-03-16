#include "GameComponent.h"

class Helicopter;
class Renderer;
class InputComponent :
	public GameComponent
{
public:
	InputComponent(Helicopter* owner) :
		m_Owner(owner) { }
	virtual void Init(Renderer* renderer) override;
	virtual void Update() override { }

	~InputComponent() { delete m_Owner; }
protected:
	Helicopter* m_Owner;
};