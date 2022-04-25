#include <cstdio>
#include "Engine.h"

class MyRect : public Engine::Rect {
public:
	MyRect(Engine::Transform2d t, Engine::Rect2dShape r, Engine::Color c) \
			: Rect::Rect(t, r, c) {}
	void update(double delta){
		Rect::update(delta);
		transform.r += (float)(M_PI/4 * delta);
	}

	void draw(){
		Rect::draw();
	}
};

int main(){
	Engine::App a("Window", Engine::Vec2i(600, 480));

	MyRect *rect1 = new MyRect(	Engine::Transform2d(10, 10, 0), \
								Engine::Rect2dShape(-50.f, -50.f, 100.f, 100.f), \
								Engine::Color(1.f, 1.f, 0.f, 1.f) );
	a.addChild(rect1);


	MyRect *rect2 = new MyRect(	Engine::Transform2d(50, 50, 0), \
								Engine::Rect2dShape(-50.f, -50.f, 100.f, 100.f), \
								Engine::Color(1.f, 0.f, 1.f, 1.f) );
	rect1->addChild(rect2);
	a.loop();

	delete rect2;
	delete rect1;

	return 0;
}
