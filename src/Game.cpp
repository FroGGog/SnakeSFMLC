#include "headers/Game.h"

Game::Game()
{
	this->initVars();
	this->initWindow();
	this->initTextures();

	this->initSnakeHead();
}

Game::~Game()
{
	delete this->window;

	delete this->snakeHead;
	
	delete this->body1;

	delete this->body2;

	//delete textures
	for (auto& i : this->textures) {
		delete i.second;
	}

	//delete all body parts
	for (auto* i : this->snakeBody) {
		delete i;
	}
}

const bool Game::windowOpen() const
{
	return this->window->isOpen();
}

void Game::update()
{

	this->updateEvents();

	this->snakeHead->update(this->turnPoints);

	this->updateBody();

}

void Game::updateEvents()
{

	while (this->window->pollEvent(this->gameEvents)) {
		switch (this->gameEvents.type)
		{
		case sf::Event::Closed:
			this->window->close();
		default:
			break;
		}

	}
}

void Game::updateBody()
{
	bool turned = false;
	
	for (size_t i{ 0 }; i < this->snakeBody.size(); ++i){

		turned = this->snakeBody[i]->update(this->turnPoints);

		if (turned && i == this->snakeBody.size() - 1 && this->turnPoints.size() > this->snakeBody.size() + 1) {
			std::cout << this->turnPoints.size() << '\n';
			this->turnPoints.erase(this->turnPoints.begin());
		}
		
	}

}

void Game::render()
{
	this->window->clear();

	//render stuf
	this->snakeHead->render(*this->window);
	this->renderBody();

	this->window->display();
}

void Game::renderBody()
{
	for (auto* i : this->snakeBody) {
		i->render(*this->window);
	}
}

void Game::initVars()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->vd.width = 900;
	this->vd.height = 600;
	this->window = new sf::RenderWindow(this->vd, "Snake", sf::Style::Resize | sf::Style::Close);
	this->window->setFramerateLimit(60);

	
}

void Game::initSnakeHead()
{
	this->snakeHead = new SnakeHead();

	this->body1 = new Body(this->textures["BODY"], 6.f, 50.f, DIR_X::RIGHT, DIR_Y::ZERO_Y);

	this->body2 = new Body(this->textures["BODY"], 42.f, 50.f, DIR_X::RIGHT, DIR_Y::ZERO_Y);

	this->body3 = new Body(this->textures["BODY"], 78.f, 50.f, DIR_X::RIGHT, DIR_Y::ZERO_Y);

	this->body4 = new Body(this->textures["BODY"], 114.f, 50.f, DIR_X::RIGHT, DIR_Y::ZERO_Y);

	this->snakeBody.push_back(this->body1);
	this->snakeBody.push_back(this->body2);
	this->snakeBody.push_back(this->body3);
	this->snakeBody.push_back(this->body4);

}

void Game::initTextures()
{
	this->textures["BODY"] = new sf::Texture;
	if (!this->textures["BODY"]->loadFromFile("src/textures/snake_body.png")) {
		std::cout << "ERROR::LOAD::error while loading snake_body.png\n";
	}

}
