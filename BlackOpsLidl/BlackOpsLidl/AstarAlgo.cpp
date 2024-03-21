#include "AstarAlgo.h"
#include "Zombie.h"
#include "Macro.h"

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
        EraseElement<Node>(_openList, _current);
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

            if (Contains<Node>(_next, _closeList) && !_next->isOpen)
                continue;

            float _hCost = Distance(_current->position, _end->position);
            float _gCost = _current->G + _hCost;

            if (_next->hasBeenVisited || !_next->isOpen)
                continue;

            if (_gCost < _next->G || !Contains<Node>(_next, _openList))
            {
                _next->G = _gCost;
                _next->H = _hCost;
                _next->parent = _current;
                _next->hasBeenVisited = true;
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
        _newPath.push_back(_path[_pathSize - 1 - i]);
    }

    return _newPath;
}