#include <cstdint>
#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
	Shader(std::string vertexPath, std::string fragmentPath);

	// Bind shader for use
	void Bind();
	// Unbind shader
	void UnBind();

	// Set uniform values

	void SetInt(const std::string& name, int value);
	void SetMat4(const std::string& name, glm::mat4 mat);

	~Shader();

private:
	// Read in shader from file
	std::string ReadFile(std::string& filePath) const;

	uint32_t m_ID;
};