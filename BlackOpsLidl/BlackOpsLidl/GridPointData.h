#pragma once
#include "Object.h"

class Node;


class GridPointData
{

public:
	vector<Node*> nodes;

public:
	GridPointData();

public:
	void ResetCost();
	Node* GetClosestNode(Vector2f _position);
	float GetDistanceBetweenPoints(Vector2f _start, Vector2f _end);
	bool ContainsNode(vector<Node*> _list, Node* _node);


};


