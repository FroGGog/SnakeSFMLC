#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class Body
{
public:
	Body(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y);
	virtual ~Body();

	//accessors
	const sf::Vector2f getPos() const;
	const sf::Vector2f getDir() const;
	const sf::FloatRect getBounds() const;

	//update
	bool update(std::vector <TurnPoint>& turnPoints, sf::RenderTarget& target);
	void updateRotation();
	bool updateMoveDir(std::vector<TurnPoint>& turnPoints);
	void updateBorderCol(sf::RenderTarget& target);

	void render(sf::RenderTarget &target);

private:
	//vars

	sf::Sprite Bsprite;

	sf::Vector2f direction;

};

