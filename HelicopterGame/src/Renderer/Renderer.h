#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace RendererFunc
{
	void SetClearColor() { glClearColor(0.5f, 0.2f, 0.4f, 1.0f); }
	void RenderClear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }
	void SwapBuffers(GLFWwindow* wnd) { glfwSwapBuffers(wnd); }
}

class Window;
class Renderer
{
public:
	Renderer(Window* wnd) :
		m_Window(wnd) { }
	void BeginScene();
	void Submit();
	void EndScene();
private:
	class Window* m_Window;
};