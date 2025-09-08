#include "Astar.h"


void drawPath::init(Node* startingNode, Node* targetNode)
{
	Node* currentNode = targetNode;
	while (currentNode != startingNode)
	{
		path.push_back(currentNode);
		currentNode = currentNode->getParentNode();
	}
}

void drawPath::draw()
{
	for (int i = 0; i < path.size(); i++)
	{
			path[i]->setNodeType(pathNode);
	}
}

int Astar::calculateDistance(Node* const from, Node* const to)
{
	sf::Vector2i fromPos = from->getPosition();
	sf::Vector2i toPos = to->getPosition();

	int x = abs(toPos.x - fromPos.x);
	int y = abs(toPos.y - fromPos.y);

	//x *= x;
	//y *= y;

	return x+y;
}

void Astar::getGrid(Grid& grid) {
	this->grid = &grid;
	this->startingNode = grid.getStartingNode();
	this->targetNode = grid.getTargetNode();
	counter = 0;
	openSet.push_back(startingNode);
}

void Astar::run() {
	startingNode->setG(0);

	startingNode->setH(calculateDistance(startingNode, targetNode));

	currentNode = startingNode;

	clock.restart();
	while (openSet.size() > 0)
	{
			counter++;
			currentNode = openSet.front();

			for (int i = 0; i < openSet.size(); i++)
			{
				if (openSet[i]->getF() < currentNode->getF() || openSet[i]->getF() == currentNode->getF() && openSet[i]->getH() == currentNode->getH())
				{
					currentNode = openSet[i];
				}
			}

			for (int i = 0; i < openSet.size(); i++)
			{
				if (openSet[i] == currentNode)
				{
					openSet.erase(openSet.begin() + i);
					continue;
				}
			}

			if (currentNode == targetNode)
			{
				std::cout << closedSet.size();
				drawing.init(startingNode, currentNode);
				drawing.draw();
				return;
			}

			closedSet.push_back(currentNode);
			std::vector<Node*> neighbours = grid->getNeighbours(currentNode);
			for (auto& node : neighbours)
			{
				if (alreadyInSet(node, closedSet) == false && node->isObstacle() == false)
					handleNeighbour(node);
			}
	}

}

void Astar::handleNeighbour(Node* neighbour)
{
	int tentative_gScore = currentNode->getG() + calculateDistance(currentNode, neighbour);
	if (tentative_gScore < currentNode->getG() || !alreadyInSet(neighbour, openSet))
	{
		neighbour->setParentNode(currentNode);
		neighbour->setG(tentative_gScore);
		neighbour->setH(calculateDistance(neighbour, targetNode));
		neighbour->setNodeType(visitedNode);
		if (alreadyInSet(neighbour, openSet) == false)
		{
			openSet.push_back(neighbour);
		}

	}
}

bool Astar::alreadyInSet(Node* node, std::vector<Node*> vector)
{
	return std::find(vector.begin(), vector.end(), node) != vector.end();
}