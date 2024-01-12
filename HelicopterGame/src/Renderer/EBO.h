#include <cstdint>

class EBO
{
public:
	EBO();

	void AddBuffer();

	void Bind() const;
	void UnBind() const;

	// Get the count of indecies in EBO object
	inline int GetCount() { return m_Count; }

	~EBO();
private:
	uint32_t m_ID;
	size_t m_Count = 0;
};