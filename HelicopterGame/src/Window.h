

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
	// Returns true on success
	bool Init();
	void Update();
	bool GetClosed();

	inline GLFWwindow* GetNativeWindow() const { return m_Wnd; }
	inline static Window* Get() { return s_Window; }

	~Window();
private:
	GLFWwindow* m_Wnd = nullptr;
	// Make Window to static class
	static Window* s_Window;
};