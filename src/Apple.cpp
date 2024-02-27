#include "headers/Apple.h"

Apple::Apple(sf::Texture* texture, sf::RenderTarget& target)
{

	this->sprite.setTexture(*texture);

	this->randomPos(target);

}

Apple::~Apple()
{

}

const sf::FloatRect Apple::getBound() const
{
	return this->sprite.getGlobalBounds();
}


void Apple::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

}

void Apple::randomPos(sf::RenderTarget& target)
{
	//get new random position on screen 
	float x_pos = rand() % (target.getSize().x- 50) + 10.f ;
	float y_pos = rand() % (target.getSize().y - 50) + 10.f;

	this->sprite.setPosition(x_pos, y_pos);
}
