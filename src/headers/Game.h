#pragma once

#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

#include "headers/SnakeHead.h"
#include "headers/Body.h"

class Game
{
public:
	//const dest
	Game();
	virtual ~Game();

	//accessors
	const bool windowOpen() const;

	//update functions
	void update();
	void updateEvents();
	void updateBody();

	//all render staff
	void render();
	void renderBody();

private:

	//window stuff
	sf::VideoMode vd;
	sf::RenderWindow* window;
	sf::Event gameEvents;

	//storage
	std::vector<Body*> snakeBody;
	Body* body1;
	Body* body2;
	Body* body3;
	Body* body4;

	std::vector <TurnPoint> turnPoints;

	//resources
	std::map<std::string, sf::Texture*> textures;

	SnakeHead* snakeHead;

	void initVars();
	void initWindow();
	void initSnakeHead();
	void initTextures();


};

