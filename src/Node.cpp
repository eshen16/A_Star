#include "Node.h"
#include <iostream>

Tile::Tile(sf::Vector2i position) :
	tile(sf::Vector2f(SIZE, SIZE * (float)16/9))
{
	tile.setPosition(sf::Vector2f(position));
	tile.setOutlineColor(sf::Color::Black);
	tile.setOutlineThickness(0.2f);
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(tile);
}

void Tile::changeColour(Type nodeType)
{
	switch (nodeType)
	{
	case startingNode:
		tile.setFillColor(sf::Color::Green);
		break;
	case targetNode:
		tile.setFillColor(sf::Color::Red);
		break;
	case obstacleNode:
		tile.setFillColor(sf::Color::Black);
		break;
	case pathNode:
		tile.setFillColor(sf::Color::Magenta);
		break;
	case visitedNode:
		tile.setFillColor(sf::Color::Blue);
		break;
	case none:
		break;
	default:
		break;
	}
}

Node::Node(sf::Vector2i& position) :
	tile(position)
{
	this->position = position;
}
void Node::setG(const int G)
{
	this->G = G;
}
void Node::setH(const int H)
{
	this->H = H;
}
void Node::setNodeType(Type nodeType)
{
	this->nodeType = nodeType;
	tile.changeColour(nodeType);
}
void Node::setParentNode(Node* const parentNode)
{
	this->parentNode = parentNode;
}