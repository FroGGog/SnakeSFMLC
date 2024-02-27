#pragma once

#include <SFML/Graphics.hpp>

class Apple
{
public:

	Apple(sf::Texture* texture, sf::RenderTarget& target);
	~Apple();
		
	//accessors
	const sf::FloatRect getBound() const;


	void render(sf::RenderTarget& target);

	void randomPos(sf::RenderTarget& target);

private:

	//vars

	sf::Sprite sprite;

	sf::Vector2f pos;

	bool spawned;

	

};

