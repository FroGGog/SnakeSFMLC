#include <iostream>
#include "headers/SnakeHead.h"

//turn point
TurnPoint::TurnPoint(DIR_X dir_x, DIR_Y dir_y, sf::Vector2f _turnPoint) {

	this->dir = sf::Vector2f{ static_cast<float>(dir_x), static_cast<float>(dir_y) };

	this->position = _turnPoint;

}


SnakeHead::SnakeHead()
{
	this->initTexture();
	this->initVars();
}

SnakeHead::~SnakeHead()
{

}

//return previous position of head
const sf::Vector2f& SnakeHead::getPos() const
{
	return this->headSprite.getPosition();
}

const sf::Vector2f& SnakeHead::getDir() const
{
	return this->direction;

}


void SnakeHead::update(std::vector <TurnPoint>& turnPoints)
{
	this->updateSnakeMovement(turnPoints);
	
	this->headSprite.move(this->direction);

}

TurnPoint SnakeHead::addTurnPoint(DIR_X dir_x, DIR_Y dir_y)
{
	TurnPoint tempPoint{ dir_x, dir_y, this->headSprite.getPosition() };


	return tempPoint;

}


void SnakeHead::updateSnakeMovement(std::vector <TurnPoint>& turnPoints)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->isPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->direction.x == 0 && !this->isPressed) {
		this->direction.x = -this->speed;
		this->direction.y = 0;
		this->headSprite.setRotation(270);
		this->isPressed = true;
		//adding new turn point
		turnPoints.push_back(this->addTurnPoint(DIR_X::LEFT, DIR_Y::ZERO_Y));

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->direction.x == 0 && !this->isPressed) {
		this->direction.x = this->speed;
		this->direction.y = 0;
		this->headSprite.setRotation(90);
		this->isPressed = true;
		turnPoints.push_back(this->addTurnPoint(DIR_X::RIGHT, DIR_Y::ZERO_Y));

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->direction.y == 0 && !this->isPressed) {
		this->direction.y = -this->speed;
		this->direction.x = 0;
		this->headSprite.setRotation(0);
		this->isPressed = true;
		turnPoints.push_back(this->addTurnPoint(DIR_X::ZERO_X, DIR_Y::UP));

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->direction.y == 0 && !this->isPressed) {
		this->direction.y = this->speed;
		this->direction.x = 0;
		this->headSprite.setRotation(180);
		this->isPressed = true;
		turnPoints.push_back(this->addTurnPoint(DIR_X::ZERO_X, DIR_Y::DOWN));
	}


}



void SnakeHead::render(sf::RenderTarget &target)
{
	target.draw(this->headSprite);
}


void SnakeHead::initTexture()
{
	if (!this->headTexture.loadFromFile("src/textures/snake_head.png")) {
		std::cout << "ERROR::LOADFROMFILE::SNAKE_HEAD\n";
	}
	this->headSprite.setTexture(this->headTexture);

	this->headSprite.setOrigin(this->headSprite.getGlobalBounds().width / 2, this->headSprite.getGlobalBounds().height / 2);

	this->headSprite.setPosition(150.f, 50.f);

	this->headSprite.setRotation(90);

}

void SnakeHead::initVars()
{
	this->speed = 3.f;
	this->direction = sf::Vector2f(this->speed, 0.f);

	this->isPressed = false;



}






