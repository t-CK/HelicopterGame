#include <cstdint>
#include <vector>

class VBO
{
public:
	VBO();

	// At the moment all vao objects have fixed amount of vertecies since we do not need more complex meshes
	void AddData(class VertexBufferLayout& layout) const;

	void Bind() const;
	void UnBind() const;

	~VBO();

private:
	uint32_t m_ID;
};