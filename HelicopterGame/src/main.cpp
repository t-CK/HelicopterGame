
// Project
//#include "Window.h"
//#include "Renderer/Renderer.h"
//#include "GameObjects/Helicopter.h"

#include "Game.h"
#include "Window.h"


int main()
{
	Window* window = new Window;
	if (!window->Init())
		return -1;
//
//	Renderer renderer();
//	
//	Helicopter* helicopter = new Helicopter(&renderer);
//
//	// Game loop
//	while (!window->GetClosed())
//	{
//		renderer.BeginScene();
//		glfwPollEvents();
//
//		helicopter->Tick(0.0f);
//		helicopter->Render();
//
//
//		renderer.EndScene();
//	}

//	delete window;

	Game* game = new Game;
	game->Init();

	game->Loop();

	delete game;
	delete window;
	return 0;
}
