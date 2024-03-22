#pragma once
#include "GridPointData.h"
#include "Object.h"


#define MAX_FLOAT 99999999999.0f

class GridPointData;

class Node 
{

public:
	GridPointData* gridData = nullptr;
	Vector2f position = Vector2f(0.0f, 0.0f);
	Vector2f size = Vector2f(0.0f, 0.0f);
	vector<int> successors;

	Node* parent = nullptr;

	float G = MAX_FLOAT; // Distance depuis le départ //
	float H = MAX_FLOAT; // Distance depuis l'arrivée //
	float F = G + H; // Coût total //

	bool isOpen = true;
	bool hasBeenVisited = false;

public:
	Node(GridPointData* _data, Vector2f _position, int _gap);


public:
	void CheckForObstacle();
	void AddSuccessor(int _successor);
	void ResetNode();



};

