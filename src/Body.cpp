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

	this->Bsprite.setRotation(90);
}

Body::~Body()
{

}

const sf::Vector2f Body::getPos() const
{
	return this->Bsprite.getPosition();
}

const sf::Vector2f Body::getDir() const
{
	return this->direction;
}


bool Body::update(std::vector <TurnPoint>& turnPoints, sf::RenderTarget& target)
{
	this->updateBorderCol(target);

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

void Body::updateBorderCol(sf::RenderTarget& target)
{
	if (this->direction.x != 0) {
		//right side of screnn
		if (this->Bsprite.getGlobalBounds().left > target.getSize().x) {
			this->Bsprite.setPosition(0.f, this->Bsprite.getPosition().y);
		}

		//left side
		else if (this->Bsprite.getGlobalBounds().left + this->Bsprite.getGlobalBounds().width < 0) {
			this->Bsprite.setPosition(target.getSize().x, this->Bsprite.getPosition().y);
		}
	}
	else {
		if (this->Bsprite.getGlobalBounds().top + this->Bsprite.getGlobalBounds().height < 0) {
			this->Bsprite.setPosition(this->Bsprite.getPosition().x, target.getSize().y);
		}
		//down
		else if (this->Bsprite.getGlobalBounds().top > target.getSize().y) {
			this->Bsprite.setPosition(this->Bsprite.getPosition().x, 0.f);
		}
	}
	
	//up
	
	

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


