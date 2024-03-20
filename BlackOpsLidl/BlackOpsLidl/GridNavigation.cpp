#include "GridNavigation.h"
#include "Node.h"
#include "Game.h"
#include "Macro.h"

GridNavigation::GridNavigation(int _size, int _gap, Vector2f _position)
{
    size = _size;
    gap = _gap;
    position = _position;
    data = new GridPointData();
}

GridNavigation::~GridNavigation()
{
}

void GridNavigation::Generate()
{
    if (!data)
        return;

    data->nodes.clear();
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            Vector2f _pos = Vector2f(x * gap, y * gap) + position;

            Node* _n = new Node(data, _pos);
            _n->CheckForObstacle(); // TODO FINIR LE CHECK
            data->nodes.push_back(_n);
        }
    }
    SetSucessors();
}

void GridNavigation::SetSucessors()
{
    for (int i = 0; i < size * size; i++)
    {
        bool _canRight = i % size != size - 1,
            _canTop = i >= size,
            _canDown = i < (size * size) - size,
            _canLeft = i % size != 0;
        if (_canRight)
            data->nodes[i]->AddSuccessor(i + 1);
        if (_canLeft)
            data->nodes[i]->AddSuccessor(i - 1);
        if (_canTop)
        {
            data->nodes[i]->AddSuccessor(i - size);
            if (_canRight)
                data->nodes[i]->AddSuccessor((i + 1 - size));
            if (_canLeft)
                data->nodes[i]->AddSuccessor((i - 1 - size));
        }
        if (_canDown)
        {
            data->nodes[i]->AddSuccessor(i + size);
            if (_canRight)
                data->nodes[i]->AddSuccessor((i + 1 + size));
            if (_canLeft)
                data->nodes[i]->AddSuccessor((i - 1 + size));
        }
    }
}

void GridNavigation::ShowNodes()
{

    for (Node* _node : data->nodes)
    {
        sf::CircleShape _shape(5.0f);
        _shape.setPosition(_node->position);
        SetOriginAtMiddle(&_shape);
        _shape.setFillColor(Color::White);
        Game::GetWindow().draw(_shape);


        //for (int i = 0; i < _node->successors.size(); i++)
        //{
        //    sf::VertexArray lines(sf::LinesStrip, 2);
        //    lines[0].position = _node->position;
        //    lines[1].position = data->nodes[_node->successors[i]]->position;
        //    lines[0].color = Color::Red;
        //    lines[1].color = Color::Red;
        //
        //    Game::GetWindow().draw(lines);
        //}

    }
}
