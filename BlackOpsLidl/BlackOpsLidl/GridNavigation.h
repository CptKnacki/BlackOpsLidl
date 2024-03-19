#pragma once
#include "GridPointData.h"
#include "Object.h"


class GridNavigation 
{

	int size = 5;
	int gap = 10;
	Vector2f position = Vector2f(0.0f, 0.0f);

public:
	GridPointData* data = nullptr;

public:
	GridNavigation(int _size, int _gap, Vector2f _position);
	~GridNavigation();

public:
	void Generate();
	void SetSucessors();
	void ShowNodes();

};

