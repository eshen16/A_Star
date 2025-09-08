#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

enum Type {
	startingNode, targetNode, obstacleNode, pathNode, visitedNode, none

};

class Tile : public sf::Drawable{
public:
	Tile(sf::Vector2i position);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void changeColour(Type nodeType);

private:
	sf::RectangleShape tile;
};




class Node
{
private:
	Tile tile;
	Node* parentNode;
	Type nodeType;
	sf::Vector2i position;
	int G = 0;
	int H = 0;
public:
	Node(sf::Vector2i& position);
	void setG(const int G);
	void setH(const int H);
	void setParentNode(Node* const parentNode);
	void setNodeType(Type nodeType);

	int getG() { return G; };
	int getH() { return H; };
	int getF() { return G + H; };
	bool isObstacle() { return nodeType == obstacleNode; }
	Tile getTile() { return tile; }
	sf::Vector2i getPosition() const { return position; }

	Node* getParentNode() { return parentNode; }
	Type getNodeType() { return nodeType; }

};