#include "Node.h"

namespace Engine {

	Node::Node() {
		parent = nullptr;
		app = nullptr;
	}

	Node::~Node() {

	}

	void Node::_updateCall(double delta) {
		std::vector<Node *, std::allocator<Node *> >::iterator child;
		for (child = children.begin(); child != children.end(); ++child)
			(*child)->_updateCall(delta);

		update(delta);
	}

	void Node::_drawCall() {
		std::vector<Node *, std::allocator<Node *> >::iterator child;
		for (child = children.begin(); child != children.end(); ++child)
			(*child)->_drawCall();

		draw();
	}

	void Node::addChild(Node *child) {
		child->parent = this;
		child->app = app;
		children.push_back(child);
	}

}
