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


void Apple::update()
{


}

void Apple::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

}

void Apple::randomPos(sf::RenderTarget& target)
{
	float x_pos = rand() % target.getSize().x;
	float y_pos = rand() % target.getSize().y;
}
