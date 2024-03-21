#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Camera.h"
#include "Renderer/Renderer.h"

Camera::Camera(Renderer* renderer)
{
	m_Renderer = renderer;
	
	m_Location = glm::vec3(1.f);
	m_Rotation = glm::vec3(1.f);
	m_Scale = glm::vec3(1.f);	

	u_Projection = glm::perspective(glm::radians(90.f), 800.0f / 600.0f, 0.1f, 100.0f);
	u_View = glm::mat4(1.f);
}

const glm::mat4 Camera::GetTransform() const
{
	glm::mat4 transform = glm::mat4(1.f);
	transform = glm::translate(transform, m_Location);
	transform = glm::rotate(transform, glm::radians(m_Rotation.x), m_Rotation);
	transform = glm::rotate(transform, glm::radians(m_Rotation.y), m_Rotation);
	transform = glm::rotate(transform, glm::radians(m_Rotation.z), m_Rotation);
	transform = glm::scale(transform, m_Scale);

	return transform;
}

void Camera::SetPos(glm::vec3 pos)
{
	m_Location = pos;
}

void Camera::SetScale(glm::vec3 scale)
{
	m_Scale = scale;
}

void Camera::MoveX(float value)
{
	m_Location.x += value;
}

void Camera::MoveY(float value)
{
	m_Location.y += value;
}

void Camera::MoveZ(float value)
{
	m_Location.z += value;
}

void Camera::RotateX(float radians)
{
	m_Rotation.x += radians;
}

void Camera::RotateY(float radians)
{
	m_Rotation.y += radians;
}

void Camera::RotateZ(float radians)
{
	m_Rotation.z += radians;
}

void Camera::Render()
{

}

void Camera::Update()
{
	u_View = glm::translate(u_View, m_Location);
	u_View = glm::rotate(u_View, glm::radians(m_Rotation.x), m_Rotation);
	u_View = glm::rotate(u_View, glm::radians(m_Rotation.y), m_Rotation);
	u_View = glm::rotate(u_View, glm::radians(m_Rotation.z), m_Rotation);
	u_View = glm::scale(u_View, m_Scale);
}

Camera::~Camera()
{
	delete m_Renderer;
}