#include <GLFW/glfw3.h>
#include "InputComponent.h"
#include "../GameObjects/MovingObject.h"
#include "../Renderer/Renderer.h"
#include "../Window.h"

void InputComponent::Init(Renderer* renderer)
{
	bool inputPresent;
	glfwSetKeyCallback(Window::Get()->GetNativeWindow(), [](GLFWwindow*, int key, int scancode, int action, int mod) {
		(key == GLFW_KEY_SPACE && action == GLFW_PRESS) || (key == GLFW_KEY_SPACE && action == GLFW_REPEAT) ?
			// DEBUG
			// Test input
			printf("input present\n") : printf("\n");
		});
}