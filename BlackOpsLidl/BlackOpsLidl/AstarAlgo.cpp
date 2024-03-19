#include "AstarAlgo.h"

AstarAlgo::AstarAlgo()
{
}

void AstarAlgo::ComputePath(Node* _start, Node* _end)
{
    _start->gridData->ResetCost();
    correctPath.clear();

    vector<Node*> _openList,
                 _closeList;

    _start->G = 0;
    _start->H = 0;

    _openList.push_back(_start);

    while (_openList.size() > 0)
    {
        Node* _current = _openList[0];
        RemoveNode(_openList, _current);
        _closeList.push_back(_current);

        if (_current == _end)
        {
            correctPath = GetFinalPath(_start, _end);
            //TODO return final path//
            return;
        }

        for (int i = 0; i < _current->successors.size(); i++)
        {
            Node* _next = _current->gridData->nodes[_current->successors[i]];

            if (ContainsNode(_closeList, _next) && !_next->isOpen)
                continue;

            float _hCost = GetDistanceBetweenPoints(_current->position, _end->position);
            float _gCost = _current->G + _hCost;

            if (_gCost < _next->G || !ContainsNode(_openList, _next))
            {
                _next->G = _gCost;
                _next->H = _hCost;
                _next->parent = _current;
                _openList.push_back(_next);
            }
        }
    }
}

vector<Node*> AstarAlgo::GetFinalPath(Node* _start, Node* _end)
{
    vector<Node*> _path;
    Node* _current = _end;
    _path.push_back(_end);

    while (_current != _start)
    {
        _path.push_back(_current->parent);
        _current = _current->parent;
    }

    _path = ReversePath(_path);
    return _path;
}

vector<Node*> AstarAlgo::ReversePath(vector<Node*> _path)
{
    vector<Node*> _newPath;
    size_t _pathSize = _path.size();


    for (size_t i = 0; i < _pathSize; i++)
    {
        if (!_path[_pathSize - 1 * i])
            continue;

        _newPath.push_back(_path[_pathSize - 1 * i]);
    }

    return _newPath;
}

vector<Node*> AstarAlgo::RemoveNode(vector<Node*> _list, Node* _node)
{
    vector<Node*> _newPath;

    if (!ContainsNode(_list, _node))
        return _list;

    size_t _size = _list.size();
    for (size_t i = 0; i < _size; i++)
    {
        if (_list[i] == _node)
            continue;

        _newPath.push_back(_list[i]);
    }

    return _newPath;
}

float AstarAlgo::GetDistanceBetweenPoints(Vector2f _start, Vector2f _end)
{
    float _xValue = (_end.x - _start.x);
    float _yValue = (_end.y - _start.y);

    return sqrt((_xValue * _xValue) + (_yValue * _yValue));
}

bool AstarAlgo::ContainsNode(vector<Node*> _list, Node* _node)
{
    for (size_t i = 0; i < _list.size(); i++)
    {
        if (_list[i] == _node)
            return true;
    }

    return false;
}
