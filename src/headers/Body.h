#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class Body
{
public:
	Body(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y);
	virtual ~Body();

	const sf::Vector2f getPos() const;

	bool update(std::vector <TurnPoint>& turnPoints);
	void updateRotation();
	bool updateMoveDir(std::vector<TurnPoint>& turnPoints);

	void render(sf::RenderTarget &target);

private:

	sf::Sprite Bsprite;

	sf::Vector2f direction;

};

