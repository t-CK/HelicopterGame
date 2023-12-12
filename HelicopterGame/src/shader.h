#include <cstdint>
#include <string>

class Shader
{
public:
	Shader(std::string vertexPath, std::string fragmentPath);

	// Bind shader for use
	void Bind();
	// Unbind shader
	void UnBind();

	~Shader();

private:
	// Read in shader from file
	std::string ReadFile(std::string& filePath) const;

	uint32_t m_ID;
};