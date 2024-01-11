

struct GLFWwindow;

// A Class to handle window related functionality
// Handels glfw and glad initializion and cleanup
// Must be initialized before calling any of openGL functions
class Window
{
public:
	Window() { }

	// Initialize glad and glfw,
	// create GLFWwindow and set the viewport
	// Returns 0 on success
	int Init();
	void Update();
	bool GetClosed();

	inline GLFWwindow* GetNativeWindow() const { return m_Wnd; }

	~Window();
private:
	GLFWwindow* m_Wnd = nullptr;
};