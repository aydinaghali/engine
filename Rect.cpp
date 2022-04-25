#include "Rect.h"

namespace Engine {


	Rect::Rect(Rect2dShape rect, Color color) : transform(0, 0, 0), \
					rect(rect), \
					color(color) {

	}

	Rect::Rect(Transform2d transform, Rect2dShape rect, Color color) \
	: transform(transform), rect(rect), color(color) {

	}

	Rect::~Rect() {

	}

	void Rect::update(double delta) {

	}

	void Rect::draw() {
		float windowWidth = (float)app->getWindowSize().x;
		float windowHeight = (float)app->getWindowSize().y;
		glColor4f(color.r, color.g, color.b, color.a);

		Transform2d gt = transform;

		Vec2f v1 = gt.transform(Vec2f(rect.x, rect.y));
		Vec2f v2 = gt.transform(Vec2f(rect.x+rect.w, rect.y));
		Vec2f v3 = gt.transform(Vec2f(rect.x+rect.w, rect.y+rect.h));
		Vec2f v4 = gt.transform(Vec2f(rect.x, rect.y+rect.h));

		glBegin(GL_POLYGON);
			glVertex2f( v1.x / windowWidth, v1.y / windowHeight);
			glVertex2f( v2.x / windowWidth, v2.y / windowHeight);
			glVertex2f( v3.x / windowWidth, v3.y / windowHeight);
			glVertex2f( v4.x / windowWidth, v4.y / windowHeight);
		glEnd();
	}

}
