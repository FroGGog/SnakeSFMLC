#pragma once

#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

#include "headers/SnakeHead.h"
#include "headers/Body.h"
#include "headers/Apple.h"

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
	void updateHeadApplesColl();

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

	Apple* apple;

	SnakeHead* snakeHead;

	std::vector <TurnPoint> turnPoints;

	//resources
	std::map<std::string, sf::Texture*> textures;

	int applesCount;

	void initVars();
	void initWindow();
	void initSnakeHeadAndBody();
	void initTextures();
	void addTail();
	void spawnApple();


};

