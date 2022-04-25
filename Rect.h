#ifndef RECT_H
#define RECT_H

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

#ifdef DEBUG
#include <cstdio>
#endif

#include <GLFW/glfw3.h>

#include "App.h"
#include "Node2d.h"
#include "Math.h"

namespace Engine {

	class Rect : public Node2d {
	protected:
		Transform2d transform;
		Rect2dShape rect;
		Color color;
	public:
		Rect(Rect2dShape rect, Color color);
		Rect(Transform2d transform, Rect2dShape rect, Color color);
		~Rect();
		void update(double delta);
		void draw();
	};

}

#endif
