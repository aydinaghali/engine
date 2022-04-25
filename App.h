#ifndef APP_H
#define APP_H

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

#include <vector>
#include <GLFW/glfw3.h>

#include "Math.h"
#include "Node.h"

namespace Engine {
	class Node;

	class App {
	private:
		const char *windowTitle;
		double lastTime;
		Vec2i windowSize;
		Color clearColor;
		GLFWwindow *window;
		std::vector<Node *> children;
	public:
		App(const char *title, Vec2i size);
		~App();
		void loop();
		void update(double delta);
		void draw();
		void addChild(Node *child);
		Vec2i getWindowSize();
		void setClearColor(Color c);
		Color getClearColor();

		friend class Node;
	};

}

#endif
