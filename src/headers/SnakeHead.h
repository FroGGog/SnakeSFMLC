#pragma once
#include <SFML/Graphics.hpp>

enum DIR_X { LEFT = -3, ZERO_X = 0, RIGHT = 3,  };
enum DIR_Y { UP = -3, ZERO_Y = 0, DOWN = 3,  };

struct TurnPoint {

	TurnPoint(DIR_X dir_x, DIR_Y dir_y, sf::Vector2f _turnPoint);

	sf::Vector2f dir;

	sf::Vector2f position;

};


class SnakeHead
{
public:

	SnakeHead();
	virtual ~SnakeHead();

	//accessors
	const sf::FloatRect getBounds() const;

	//update
	void update(std::vector <TurnPoint>& turnPoints, sf::RenderTarget& target);
	void updateSnakeMovement(std::vector <TurnPoint>& turnPoints);
	void updateBorderCol(sf::RenderTarget& target);

	//render
	void render(sf::RenderTarget& target);

private:

	//texture and sprite
	sf::Texture headTexture;
	sf::Sprite headSprite;

	//vars
	sf::Vector2f direction;
	
	float speed;
	bool isPressed;

	//functions
	void initTexture();
	void initVars();

	TurnPoint addTurnPoint(DIR_X dir_x, DIR_Y dir_y);

};


