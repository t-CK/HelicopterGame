
// Project
#include "Window.h"
#include "Renderer/Renderer.h"
#include "GameObjects/Helicopter.h"
#include "Game.h"




int main()
{
//	Window* window = new Window;
//	if (!window->Init())
//		return -1;

	Game game;

	game.Update();



	// Game loop
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


	return 0;
}
