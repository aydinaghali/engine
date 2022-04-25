#include "App.h"

namespace Engine {

	App::App(const char *title, Vec2i size) :
			windowTitle(title), windowSize(size), clearColor(0.5f, 0.5f, 0.5f) {
		if (!glfwInit())
			exit(-1);

#ifdef __APPLE__
		/* We need to explicitly ask for a 3.2 context on OS X */
		/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);*/
#endif

		window = glfwCreateWindow(size.x, size.y, title, NULL, NULL);
		if (!window) {
			glfwTerminate();
			exit(-1);
		}

		glfwMakeContextCurrent(window);

		glfwSwapInterval(1);
		lastTime = 0.f;
	}

	App::~App() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void App::loop() {
		lastTime = 0.f;
		glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);

		double currentTime = glfwGetTime();
		double delta = currentTime - lastTime;
		lastTime = currentTime;
		while (!glfwWindowShouldClose(window)) {
			glClear(GL_COLOR_BUFFER_BIT);

			update(delta);
			draw();

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	void App::update(double delta) {
		std::vector<Node *, std::allocator<Node *> >::iterator child;
		for (child = children.begin(); child != children.end(); ++child)
			(*child)->_updateCall(delta);
	}

	void App::draw() {
		std::vector<Node *, std::allocator<Node *> >::iterator child;
		for (child = children.begin(); child != children.end(); ++child)
			(*child)->_drawCall();
	}

	void App::addChild(Node *child) {
		child->app = this;
		children.push_back(child);
	}

	Vec2i App::getWindowSize(){
		return windowSize;
	}

	void App::setClearColor(Color c) {
		clearColor = c;
	}

	Color App::getClearColor() {
		return clearColor;
	}

}
