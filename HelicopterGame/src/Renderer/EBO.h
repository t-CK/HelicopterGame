#include <cstdint>

class EBO
{
public:
	EBO();

	void AddBuffer() const;

	void Bind() const;
	void UnBind() const;

	~EBO();
private:
	uint32_t m_ID;
};