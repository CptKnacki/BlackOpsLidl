#include "Node.h"
#include "Kismet.h"

Node::Node(GridPointData* _data, Vector2f _position)
{
	gridData = _data;
	position = _position;
}

void Node::CheckForObstacle()
{
	HitInfo _info;
	vector<Actor*> _actorToIgnore;
	
	cout << to_string(isOpen) + "\n";

	//BoxCast(FloatRect(position, size), _info, _actorToIgnore);

}

void Node::AddSuccessor(int _successor)
{
	successors.push_back(_successor);
}

void Node::ResetNode()
{
	H = MAX_FLOAT;
	G = MAX_FLOAT;
	parent = nullptr;
	hasBeenVisited = false;
}
