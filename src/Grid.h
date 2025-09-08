#pragma once
#include <iostream>
#include <vector>
#include "Node.h"
#include <SFML/Graphics.hpp>

class Grid : public sf::Drawable, sf::Transformable
{
private:
	std::vector<Node*> nodes;
	Node* startingNode = nullptr;
	Node* targetNode = nullptr;

	Node* getNode(int posX, int posY);
	bool outOfBounds(int posX, int posY);
public:
	Grid();
	void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const;
	
	void processMouseEvents(sf::Event event, sf::Vector2f mouseWorldPosition);

	std::vector<Node*> getNeighbours(Node* currentNode);
	Node* getStartingNode() { return startingNode; }
	Node* getTargetNode() { return targetNode; }
	bool released = false;
	bool clicked = true;
};