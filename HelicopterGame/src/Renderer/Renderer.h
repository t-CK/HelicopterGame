#ifndef RENDERER_H
#define RENDERER_H



namespace RendererFunc
{
	inline static void SetClearColor() { glClearColor(0.5f, 0.2f, 0.4f, 1.0f); }
	inline static void RenderClear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }
	inline static void SwapBuffers(GLFWwindow* wnd) { glfwSwapBuffers(wnd); }
}

class Window;
class Renderer
{
public:
	Renderer(Window* wnd) :
		m_Window(wnd) { }

	static void BeginScene();
	static void Submit(class VertexBufferLayout&, class VAO&, class VBO&, class EBO& ebo);

	void EndScene();
private:
	class Window* m_Window;
};

#endif // !RENDERER_H