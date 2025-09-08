#include <iostream>
#include "Grid.h"

Grid::Grid()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			sf::Vector2i position(i * SIZE, j * SIZE);
			Node* node = new Node(position);
			nodes.push_back(node);
		}
	}
}

void Grid::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
	for (auto& node : nodes)
		renderTarget.draw(node->getTile());
}

void Grid::processMouseEvents(sf::Event event, sf::Vector2f mouseWorldPosition)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
	{
		int mouseX = mouseWorldPosition.x;
		int mouseY = mouseWorldPosition.y;
		if (event.mouseButton.button == sf::Mouse::Left) {
			if (!startingNode) {
				std::cout << "Not set";
				getNode(mouseX, mouseY)->setNodeType(Type::startingNode);
				startingNode = getNode(mouseX, mouseY);
			}
			else {
				getNode(mouseX, mouseY)->setNodeType(Type::targetNode);
				targetNode = getNode(mouseX, mouseY);
			}
		}
		else if (event.mouseButton.button == sf::Mouse::Right) {
			getNode(mouseX, mouseY)->setNodeType(obstacleNode);
		}
		break;
	}
	default:
		break;
	}
}

Node* Grid::getNode(int posX, int posY)
{
	int x = posX / SIZE;
	int y = posY / SIZE;
	int position = COL * x + y;
	return nodes[position];
}

bool Grid::outOfBounds(int posX, int posY)
{
	if (0 <= posX && posX < ROW)
	{
		if (0 <= posY && posY < COL)
		{
			return false;
		}
	}
	return true;
}


std::vector<Node*> Grid::getNeighbours(Node* currentNode)
{
	int x = currentNode->getPosition().x / SIZE;
	int y = currentNode->getPosition().y / SIZE;

	std::vector<Node*> neighbours;

	for (int i = -1; i <= 1; i+=2)
	{
		if (outOfBounds(x - i, y) == false)
		{
			Node* neighbour = getNode((x - i) * SIZE, y * SIZE);
			neighbours.push_back(neighbour);
		}
		if (outOfBounds(x, y - i) == false)
		{
			Node* neighbour = getNode(x * SIZE, (y - i) * SIZE);
			neighbours.push_back(neighbour);
		}
	}
	return neighbours;
}