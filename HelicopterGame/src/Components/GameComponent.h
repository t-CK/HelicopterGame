#include <string>

// Base class for components in game
class GameComponent
{
public:
	GameComponent() = default;

	virtual void Update();

	std::string GetName() const { return m_Name; }

	~GameComponent();
protected:
	std::string m_Name;
};