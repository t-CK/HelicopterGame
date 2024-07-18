#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera
{
public:
	Camera();
	
	void Update();

	inline glm::vec3 GetForwardVector() const { return m_Forward; }
	inline glm::vec3 GetRightVector()	const { return m_Right; }
	inline glm::vec3 GetUpVector()		const { return m_Up; }

	inline glm::vec3 GetLocation() const { return m_CameraPos; }

	inline glm::mat4 GetView()			const { return m_View; }
	inline glm::mat4 GetProjection()	const { return m_Projection; }
private:
	// Camera transforms
	glm::vec3 m_Forward;
	glm::vec3 m_Right;
	glm::vec3 m_Up;

	glm::vec3 m_CameraPos;

	glm::mat4 m_View;
	glm::mat4 m_Projection;
};
#endif // !CAMERA_H
