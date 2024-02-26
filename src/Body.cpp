#include "headers/SnakeHead.h"
#include "headers/Body.h"


Body::Body(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y)
{
	this->Bsprite.setTexture(*texture);

	this->Bsprite.setPosition(pos_x, pos_y);

	this->direction.x = dir_x;
	this->direction.y = dir_y;

	this->Bsprite.setOrigin(this->Bsprite.getGlobalBounds().width / 2, this->Bsprite.getGlobalBounds().height / 2);

	this->Bsprite.setScale(1.5f, 1.5f);
}

Body::~Body()
{

}

const sf::Vector2f Body::getPos() const
{
	return this->Bsprite.getPosition();
}


bool Body::update(std::vector <TurnPoint>& turnPoints)
{
	if (this->updateMoveDir(turnPoints)) {
		this->updateRotation();
		this->Bsprite.move(this->direction);
		return true;
	}
	else {
		this->Bsprite.move(this->direction);
		return false;
	}

	
}

bool Body::updateMoveDir(std::vector <TurnPoint>& turnPoints)
{
	for (auto& point : turnPoints) {
		if (this->Bsprite.getPosition().x == point.position.x && this->Bsprite.getPosition().y == point.position.y) {
			this->direction.x = point.dir.x;
			this->direction.y = point.dir.y;
			return true;
		}
	}
	return false;

}


void Body::updateRotation()
{

	if (this->direction.x > 0) {
		this->Bsprite.setRotation(90);
	}
	else if (this->direction.x < 0) {
		this->Bsprite.setRotation(270);
	}

	if (this->direction.y > 0) {
		this->Bsprite.setRotation(180);
	}
	else if (this->direction.y < 0) {
		this->Bsprite.setRotation(0);
	}

}




void Body::render(sf::RenderTarget& target)
{
	target.draw(this->Bsprite);
}


