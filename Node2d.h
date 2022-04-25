#ifndef NODE2D_H
#define NODE2D_H

#include "Node.h"
#include "Math.h"

namespace Engine {

	class Node2d : public Node {
	protected:
		Transform2d transform;
	public:
		Node2d();
		explicit Node2d(Transform2d transform);
		virtual ~Node2d();
		virtual void update(double delta) = 0;
		virtual void draw() = 0;
	};

}

#endif
