#include <cstdint>
#include <vector>
#ifndef VBO_H
#define VBO_H


class VertexBufferLayout;
class VBO
{
public:
	VBO();

	// Add data to vertex buffer
	// Parameters:
	// Pointer to array of float data
	// size of element
	//	3D position = 3;
	//	3D position + texture coordinates = 3 + 2
	//	etc.
	void AddData(float* buffer, size_t bufferSize, VertexBufferLayout& layout);

	void Bind() const;
	void UnBind() const;

	~VBO();

private:
	uint32_t m_ID;
	VertexBufferLayout* m_Layout = nullptr;
};
#endif // !VBO_H