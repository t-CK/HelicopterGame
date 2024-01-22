#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include <string>

// Base class for components in game
class GameComponent
{
public:
	GameComponent() = default;

	// Initialize component with reference to renderer
	virtual void Init(class Renderer*) = 0;
	virtual void Update() = 0;

	std::string GetName() const { return m_Name; }

protected:
	std::string m_Name;
};

#endif // !GAME_COMPONENT_H