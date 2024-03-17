#include <GLFW/glfw3.h>
#include "InputComponent.h"
#include "../GameObjects/MovingObject.h"
#include "../Renderer/Renderer.h"
#include "../Window.h"

void InputComponent::Init(Renderer* renderer)
{
	bool inputPresent;
	glfwSetWindowUserPointer(Window::Get()->GetNativeWindow(), static_cast<void*>(this));
	glfwSetKeyCallback(Window::Get()->GetNativeWindow(), [](GLFWwindow* wnd, int key, int scancode, int action, int mod) {
		auto comp = static_cast<InputComponent*>(glfwGetWindowUserPointer(wnd));
		comp->HandleInput(key, action);
		});
}

void InputComponent::HandleInput(int key, int action)
{
	(key == GLFW_KEY_SPACE && action == GLFW_PRESS) || (key == GLFW_KEY_SPACE && action == GLFW_REPEAT) ?
		// DEBUG
		// Test input
		printf("input present\n") : printf("\n");
}