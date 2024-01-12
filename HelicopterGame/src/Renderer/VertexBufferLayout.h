#include <cstdint>
#include <vector>
#include <GLFW/glfw3.h>

struct VertexBufferElement
{
	VertexBufferElement(GLenum dataType, int dataCount, bool dataNormalized, int dataOffset)
	{
		type = dataType;
		count = dataCount;
		normalized = dataNormalized;
		offset = dataOffset * GetSizeOfType();
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
		Elements.push_back(new VertexBufferElement(GL_INT, count, normalized, Elements.size())); 
		Stride += count * sizeof(int); 
	}

	inline void PushUInt(int count, bool normalized)
	{
		Elements.push_back(new VertexBufferElement(GL_UNSIGNED_INT, count, normalized, Elements.size()));
		Stride += count * sizeof(unsigned int); 
	}

	inline void PushFloat(unsigned int count, bool normalized)
	{
		Elements.push_back(new VertexBufferElement(GL_FLOAT, count, normalized, Elements.size())); Stride += count * sizeof(float);
	}

	inline void PushChar(unsigned int count, bool normalized)
	{
		Elements.push_back(new VertexBufferElement(GL_BYTE, count, normalized, Elements.size()));
		Stride += count * sizeof(char);
	}

	inline void PushUChar(unsigned int count, bool normalized)
	{
		Elements.push_back(new VertexBufferElement(GL_UNSIGNED_BYTE, count, normalized, Elements.size()));
		Stride += count * sizeof(unsigned char);
	}

	inline ~VertexBufferLayout() 
	{
		for (auto element : Elements)
			delete element; 
	}

	std::vector<VertexBufferElement*> Elements;
	unsigned int Stride = 0;
};