#ifndef NODE_H
#define NODE_H

#include <vector>

#include "Math.h"

namespace Engine {
	class App;

	class Node {
	protected:
		std::vector<Node *> children;
		Node *parent;
		App *app;
		void _updateCall(double delta);
		void _drawCall();
	public:
		Node();
		virtual ~Node();
		virtual void update(double delta) = 0;
		virtual void draw() = 0;
		void addChild(Node *child);
		friend class App;
	};

}

#endif
