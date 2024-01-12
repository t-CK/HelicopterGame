#include <cstdint>
#include <vector>
#include <GLFW/glfw3.h>
#include <iostream>

struct VertexBufferElement
{
	VertexBufferElement(GLenum dataType, int dataCount, bool dataNormalized, int dataOffset)
	{
		type = dataType;
		count = dataCount;
		normalized = dataNormalized;
		offset = dataOffset;
		std::cout << offset << std::endl;
	}

	size_t GetSizeOfType()
	{
		switch (type)
		{
			case GL_INT:		 
			case GL_UNSIGNED_INT:
			case GL_FLOAT:		   return 4; break;
			case GL_BYTE:
			case GL_UNSIGNED_BYTE: return 1;
		}
	}

	GLenum type;
	int count;
	int offset;
	bool normalized;
};

class VertexBufferLayout
{
public:

	inline void PushInt(int count, bool normalized)
	{
		Elements.push_back(new VertexBufferElement(GL_INT, count, normalized, m_Offset));
		Stride += count * sizeof(int); 
		m_Offset += count * 4;
	}

	inline void PushUInt(int count, bool normalized)
	{
		Elements.push_back(new VertexBufferElement(GL_UNSIGNED_INT, count, normalized, m_Offset));
		Stride += count * sizeof(unsigned int);
		m_Offset += count * 4;
	}

	inline void PushFloat(unsigned int count, bool normalized)
	{
		int offset = 0;
		for (auto i : Elements)
			offset += i->count * i->GetSizeOfType();
		Elements.push_back(new VertexBufferElement(GL_FLOAT, count, normalized, m_Offset));
		Stride += count * sizeof(float);
		m_Offset += count * 4;
	}

	inline void PushChar(unsigned int count, bool normalized)
	{
		Elements.push_back(new VertexBufferElement(GL_BYTE, count, normalized, m_Offset));
		Stride += count * sizeof(char);
		m_Offset += count * 1;
	}

	inline void PushUChar(unsigned int count, bool normalized)
	{
		Elements.push_back(new VertexBufferElement(GL_UNSIGNED_BYTE, count, normalized, m_Offset));
		Stride += count * sizeof(unsigned char);
		m_Offset += count * 1;
	}

	inline ~VertexBufferLayout() 
	{
		for (auto element : Elements)
			delete element; 
	}

	std::vector<VertexBufferElement*> Elements;
	unsigned int Stride = 0;

private:
	size_t m_Offset;
};