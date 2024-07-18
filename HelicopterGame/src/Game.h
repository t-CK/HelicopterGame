#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include <glm/glm.hpp>

class GameObject;

class Game {
public:
	// Initialize Game
	bool Init();

	static Game* Get() { return s_Game; }
	static float GetDeltaTime() { return m_DeltaTime; }

	inline class Camera* GetCamera() const { return m_Camera; }

	void Loop();

	~Game();

	// Private class functions
private:
	// Adds new GameObject to m_Objects vector
	void AddObject(GameObject* object);
	// Removes last object in GameObject vector
	void RemoveObject() { m_Objects.pop_back(); }
		
	// Updates Game, game objects and delta time
	// Returns false once user has quit the window
	void Update();
	void Render();

	// Free up allocated memory before destroying Game;
	void Terminate();
private:
	// Delta time
	static float m_DeltaTime;

	// Class Objects

	class Helicopter* m_Player;
	std::vector<GameObject*> m_Objects;

	// Renderer related class objects

	class Camera* m_Camera;

	class Renderer* m_Renderer;
	class Window* m_Wnd;
	// We only need one instance of game at a time, so make Game into static class
	static Game* s_Game;

//public:
//	// Camera
//	glm::mat4 GetView() { return m_View; }
//	glm::mat4 GetProjection() { return m_Projection; }
//private:
//	glm::vec3 m_CameraRight;
//	glm::vec3 m_CameraUp;
//	glm::vec3 m_CameraForward;
//
//	glm::mat4 m_View;
//	glm::vec3 m_CamPos;
//
//	glm::mat4 m_Projection;
};
#endif // !GAME_H