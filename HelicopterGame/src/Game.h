#ifndef GAME_H
#define GAME_H

#include <vector>

class GameObject;
class Camera;
class Renderer;
class Window;

class Game
{
public:
	Game();

	// Update the game, Camera and GameObjects
	void Update();
	static Game* Get() { return s_Game; }

	float GetDeltaTime() const { return m_DeltaTime; }
	Camera* GetCamera() const { return m_Camera; }
	Renderer* GetRenderer() const { return m_Renderer; }


	~Game();
private:
	void AddObject();
	void RemoveObject();
private:
	float m_DeltaTime;

	std::vector<GameObject*> m_Objects;
//	Camera* m_Camera;
	Renderer* m_Renderer;
	Window* m_Window;

	// We need only one game running at time, so make Game a static class
	static Game* s_Game;

};
#endif // !GAME_H