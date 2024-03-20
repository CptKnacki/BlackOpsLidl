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

};

