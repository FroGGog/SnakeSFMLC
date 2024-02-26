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
	const sf::Vector2f& getPos() const;
	const sf::Vector2f& getDir() const;


	void update(std::vector <TurnPoint>& turnPoints);
	void updateSnakeMovement(std::vector <TurnPoint>& turnPoints);

	void render(sf::RenderTarget& target);

private:

	sf::Texture headTexture;
	sf::Sprite headSprite;

	sf::Vector2f direction;
	
	float speed;
	bool isPressed;

	void initTexture();
	void initVars();

	TurnPoint addTurnPoint(DIR_X dir_x, DIR_Y dir_y);

};


