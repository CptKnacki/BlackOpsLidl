#pragma once
#include "Node.h"



class AstarAlgo
{

public:
	vector<Node*> correctPath;


public:
	AstarAlgo();

public:
	void ComputePath(Node* _start, Node* _end);
	vector<Node*> GetFinalPath(Node* _start, Node* _end);
	vector<Node*> ReversePath(vector<Node*> _path);
	vector<Node*> RemoveNode(vector<Node*> _list, Node* _node);
	float GetDistanceBetweenPoints(Vector2f _start, Vector2f _end);
	bool ContainsNode(vector<Node*> _list, Node* _node);

};

