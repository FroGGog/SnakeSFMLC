#pragma once

#include <SFML/Graphics.hpp>

class Apple
{
public:

	Apple(sf::Texture* texture, sf::RenderTarget& target);
	~Apple();
		
	//accessors
	const sf::FloatRect getBound() const;


	void update();

	void render(sf::RenderTarget& target);

private:

	sf::Sprite sprite;

	sf::Vector2f pos;

	bool spawned;

	void randomPos(sf::RenderTarget& target);

};

