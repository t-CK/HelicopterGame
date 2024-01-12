#include <cstdint>

class VAO
{
public:
	// At the moment all vao objects have fixed amount of vertecies since we do not need more complex meshes
	VAO();

	void Bind();
	void UnBind();

	~VAO();
private:
	uint32_t m_ID;
};