#include "Node2d.h"

namespace Engine {

	Node2d::Node2d() : transform(0, 0, 0) {
	}

	Node2d::Node2d(Transform2d transform) : transform(transform) {

	}

	Node2d::~Node2d() {

	}

}
