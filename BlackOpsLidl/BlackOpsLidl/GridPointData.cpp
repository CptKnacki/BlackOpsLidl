#include "GridPointData.h"
#include "Node.h"

GridPointData::GridPointData()
{
    nodes.clear();
}

void GridPointData::ResetCost()
{
    for (int i = 0; i < nodes.size(); ++i)
    {
        nodes[i]->ResetNode();
    }
}

Node* GridPointData::GetClosestNode(Vector2f _position)
{
    Node* _current = nullptr;
    float _max = MAX_FLOAT;

    size_t _nodesSize = nodes.size();
    for (int i = 0; i < _nodesSize; i++)
    {
        float _dist = GetDistanceBetweenPoints(nodes[i]->position, _position);
        if (_dist < _max)
        {
            _max = _dist;
            _current = nodes[i];
        }
    }

    return _current;
}

float GridPointData::GetDistanceBetweenPoints(Vector2f _start, Vector2f _end)
{
    float _xValue = (_end.x - _start.x);
    float _yValue = (_end.y - _start.y);

    return sqrt((_xValue * _xValue) + (_yValue * _yValue));
}

bool GridPointData::ContainsNode(vector<Node*> _list, Node* _node)
{
    for (size_t i = 0; i < _list.size(); i++)
    {
        if (_list[i] == _node)
            return true;
    }

    return false;
}
