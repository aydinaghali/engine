#ifndef MATH_H
#define MATH_H

#include <cmath>

namespace Engine {

	struct Vec2i {
		int x, y;
		Vec2i(int x, int y) : x(x), y(y){}
	};

	struct Vec2f {
		float x, y;
		Vec2f(float x, float y) : x(x), y(y){}
	};

	struct Rect2dShape {
		float x, y;
		float w, h;
		Rect2dShape(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}
	};

	struct Transform2d {
		float x, y;
		float r;

		Transform2d() : x(0), y(0), r(0) {}
		Transform2d(float x, float y, float r) : x(x), y(y), r(r) {}

		Vec2f transform(Vec2f v) const{
			return Vec2f(v.x*cos(r) - v.y*sin(r) + x,
						 v.x*sin(r) + v.y*cos(r) + y);
		}

		Transform2d transform(Transform2d t){
			return Transform2d(	t.x*cos(r) - t.y*sin(r) + x,
								t.x*sin(r) + t.y*cos(r) + y,
							   	t.r + r);
		}
	};

	struct Color {
		float r, g, b, a;

		Color(float r, float g, float b) : r(r), g(g), b(b), a(1.f) {}
		Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
	};
}

#endif
