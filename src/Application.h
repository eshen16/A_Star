#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Astar.h"

class Application {
public:
	Application();

	void run();

private:
	void init();
	void update();
	void draw();

	void processEvents();
	void processMultipleEvents(sf::Event& event);


	sf::RenderWindow window;
	sf::Vector2f MouseWorldPosition;
	sf::Vector2i MouseViewPosition;
	Grid grid;
	Astar astar;

};