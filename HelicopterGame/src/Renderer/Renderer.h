#ifndef RENDERER_H
#define RENDERER_H



namespace RendererFunc
{
	static void SetClearColor();
	static void RenderClear();
	static void SwapBuffers(GLFWwindow* wnd);
}

class Window;
class Renderer
{
public:
	Renderer(Window* wnd);

	static void BeginScene();
	static void Submit(class VertexBufferLayout&, class VAO&, class VBO&, class EBO& ebo);

	void EndScene();
private:
	class Window* m_Window;
};

#endif // !RENDERER_H