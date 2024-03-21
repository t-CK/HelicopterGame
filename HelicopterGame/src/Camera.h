#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include "Preset/preset.h"

class Renderer;
class Camera
{
public:
	Camera(Renderer*);

	glm::vec3 GetPos() const { return m_Location; }
	glm::vec3 GetRotation() const { return m_Rotation; }
	glm::vec3 GetScale() const { return m_Scale; }
	// Get the transformation matrix of camera
	const glm::mat4 GetTransform() const;
	const glm::mat4 GetProjection() const { return u_Projection; }
	const glm::mat4 GetView() const { return u_View; }
	
	void SetPos(glm::vec3 pos);
	void SetScale(glm::vec3 scale);

	void MoveX(float value);
	void MoveY(float value);
	void MoveZ(float value);

	void RotateX(float radians);
	void RotateY(float radians);
	void RotateZ(float radians);

	// Render the scene using this camera
	void Render();
	// Update the camera
	void Update();

	~Camera();
private:
	glm::vec3 m_Location;
	glm::vec3 m_Rotation;
	glm::vec3 m_Scale;

	glm::mat4 u_Projection;
	glm::mat4 u_View;

	Renderer* m_Renderer;
};
#endif // !CAMERA_H