#include <iostream>
#include "Application.h"
#include "Constants.h"
#include <thread>

Application::Application() 
	: window(sf::VideoMode(1600, 900), "A* Algorithm")
{
	init();
}

void Application::init() {
	float sizeX = SIZE * ROW;
	float sizeY = SIZE * COL;
	sf::FloatRect viewSize = { 0,0, sizeX, sizeY };
	window.setView(sf::View(viewSize));
	
}
void Application::run() {
	while (true) {
		processEvents();
		update();
		draw();
	}
}
void Application::processEvents() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		processMultipleEvents(event);
		grid.processMouseEvents(event, MouseWorldPosition);
	}
}
void Application::processMultipleEvents(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::Closed:
		window.close();
	case sf::Event::MouseMoved:
		MouseViewPosition = sf::Mouse::getPosition(window);
		MouseWorldPosition = window.mapPixelToCoords(MouseViewPosition);
	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Num1) {
			astar.getGrid(grid);
			astar.run();
		}


	default:
		break;
	}
}
void Application::draw() {
	window.clear();
	window.draw(grid);
	window.display();
}
void Application::update() {

}