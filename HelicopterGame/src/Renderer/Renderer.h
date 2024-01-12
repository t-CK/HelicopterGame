

namespace RendererFunc
{
	static void SetClearColor() { glClearColor(0.5f, 0.2f, 0.4f, 1.0f); }
	static void RenderClear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }
	static void SwapBuffers(GLFWwindow* wnd) { glfwSwapBuffers(wnd); }
}

class Window;
class Renderer
{
public:
	Renderer(Window* wnd) :
		m_Window(wnd) { }

	static void BeginScene();
	static void Submit(class VertexBufferLayout&, class VAO&, class VBO&);
	static void RenderObject();

	void EndScene(class EBO&);
private:
	class Window* m_Window;
};