
// Project
#include "Window.h"
#include "Renderer/Renderer.h"
#include "GameObjects/Helicopter.h"




int main()
{
	Window* window = new Window;
	if (!window->Init())
		return -1;

	Renderer renderer(window);
	
	Helicopter* helicopter = new Helicopter(&renderer);

	// Game loop
	while (!window->GetClosed())
	{
		renderer.BeginScene();
		glfwPollEvents();

		helicopter->Tick(0.0f);
		helicopter->Render();


		renderer.EndScene();
	}

	delete window;

	return 0;
}
