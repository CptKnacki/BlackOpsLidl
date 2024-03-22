#include "Node.h"
#include "Kismet.h"
#include "GPE_Fence.h"

Node::Node(GridPointData* _data, Vector2f _position, int _gap)
{
	gridData = _data;
	position = _position;
	size = Vector2f(_gap, _gap);
}

void Node::CheckForObstacle()
{
	vector<HitInfo> _infos;
	vector<Actor*> _actorToIgnore;
	Vector2f _castPosition = position - (size * 0.5f);

	bool _hit = BoxCastAll(FloatRect(_castPosition, size), _infos, _actorToIgnore);

	for (HitInfo _info  : _infos)
	{
		GPE_Fence* _fence = dynamic_cast<GPE_Fence*>(_info.actor);
	
		if (_fence)
		{
		cout << "Has Collision with Fence \n";
			isOpen = false;
		}
	}

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
