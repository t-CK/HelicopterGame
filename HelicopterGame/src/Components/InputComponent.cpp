#include <GLFW/glfw3.h>
#include "InputComponent.h"
#include "../GameObjects/Helicopter.h"
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
	if (key == GLFW_KEY_SPACE)
	{
		if (action == GLFW_PRESS)
			m_Owner->m_GoingUp = true;
		else if (action == GLFW_RELEASE)
			m_Owner->m_GoingUp = false;
	}
}