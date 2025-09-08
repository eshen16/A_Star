#include <iostream>
#include <queue>
#include <chrono>
#include <thread>
#include "Grid.h"

class drawPath {
private:
	std::vector<Node*> path;

public:
	void init(Node* startingNode, Node* targetNode);
	void draw();

};


class Astar {
private:
	Grid* grid;
	Node* startingNode;
	Node* targetNode;
	Node* currentNode;
	std::vector<Node*> openSet;
	std::vector<Node*> closedSet;
	drawPath drawing;
	sf::Clock clock;
	int counter;

	int calculateDistance(Node* const from, Node* const to);
	void handleNeighbour(Node* neighbour);
	bool alreadyInSet(Node* node, std::vector<Node*> vector);
	//void handleNeighbours
public:
	void getGrid(Grid& grid);
	void run();
};