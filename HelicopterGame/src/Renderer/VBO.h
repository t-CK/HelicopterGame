#include <cstdint>
#include <vector>
#ifndef VBO_H
#define VBO_H


class VertexBufferLayout;
class VBO
{
public:
	VBO();

	// At the moment all vao objects have fixed amount of vertecies since we do not need more complex meshes
	void AddData(VertexBufferLayout& layout);

	void Bind() const;
	void UnBind() const;

	~VBO();

private:
	uint32_t m_ID;
	VertexBufferLayout* m_Layout = nullptr;
};
#endif // !VBO_H