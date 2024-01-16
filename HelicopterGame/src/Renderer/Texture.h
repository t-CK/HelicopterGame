#include <cstdint>
#include <string>

class Texture
{
public:
	Texture() { }
	void Create(const std::string& filePath);

	void Bind();
	void UnBind();

	~Texture();
private:
	uint32_t m_ID;
	int m_Width, m_Height, m_BitsPerPixel;
	unsigned char* m_Source;
};