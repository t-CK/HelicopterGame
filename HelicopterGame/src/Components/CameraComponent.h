#include "GameComponent.h"
#include "../Camera.h"

class GameObject;

class CameraComponent :
	public GameComponent
{
public:
	CameraComponent(GameObject* owner);

	virtual void Init(class Renderer* renderer) override { }
	virtual void Update() override;

	const glm::vec3 GetPos() const { return m_Location; }
	Camera* GetCamera() const { return m_Camera; }
	
	// Render scene using component camera
	void Render();

	~CameraComponent();
protected:
	glm::vec3 m_Location;
	GameObject* m_Owner;
	Camera* m_Camera;
};