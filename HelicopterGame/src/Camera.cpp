#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
	m_Projection = glm::perspective(glm::radians(59.f), 800.0f / 600.0f, 0.1f, 100.0f);

	// We use only static X and Y axis in game so values can be hard coded
	m_Right = glm::vec3(1.f, 0.f, 0.f);
	m_Up = glm::vec3(0.f, 1.f, 0.f);
	m_Forward = glm::vec3(0.f, 0.f, 1.f);

	m_CameraPos = glm::vec3(0.f, 0.f, -1.f);
	m_View = glm::lookAt(m_Forward, m_CameraPos, m_Up);
}

void Camera::Update()
{
	// Temp value for debugging
	m_CameraPos += m_Right * 0.0003f;

	m_View = glm::lookAt(m_Forward, m_CameraPos, m_Up);
}