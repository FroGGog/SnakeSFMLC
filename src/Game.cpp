#include "headers/Game.h"

Game::Game()
{
	this->initVars();
	this->initWindow();
	this->initTextures();

	this->initSnakeHeadAndBody();
}

Game::~Game()
{
	delete this->window;

	delete this->snakeHead;

	//delete textures
	for (auto& i : this->textures) {
		delete i.second;
	}

	//delete all body parts
	for (auto* i : this->snakeBody) {
		delete i;
	}

	delete apple;
}

const bool Game::windowOpen() const
{
	return this->window->isOpen();
}

void Game::update()
{

	this->updateEvents();

	if (this->applesCount == 0) {

	}

	this->updateBody();

	this->snakeHead->update(this->turnPoints, *this->window);

	this->updateHeadApplesColl();

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

		turned = this->snakeBody[i]->update(this->turnPoints, *this->window);

		if (turned && i == this->snakeBody.size() - 1 && this->turnPoints.size() > this->snakeBody.size() * 2) {
			std::cout << this->turnPoints.size() << '\n';
			this->turnPoints.erase(this->turnPoints.begin());
		}
		
	}

}

void Game::updateHeadApplesColl()
{
	if (this->apple != nullptr) {
		if (this->snakeHead->getBounds().intersects(this->apple->getBound())) {
			//eat apple
			this->applesCount--;
			this->addTail();
			this->apple = nullptr;
		}
	}


}

void Game::render()
{
	this->window->clear();

	if (this->apple != nullptr) {
		this->apple->render(*this->window);
	}
	

	//render snake stuff
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

	this->applesCount = 0;
}

void Game::initWindow()
{
	this->vd.width = 900;
	this->vd.height = 600;
	this->window = new sf::RenderWindow(this->vd, "Snake", sf::Style::Resize | sf::Style::Close);
	this->window->setFramerateLimit(60);

	
}

void Game::initSnakeHeadAndBody()
{
	this->snakeHead = new SnakeHead();

	this->snakeBody.push_back(new Body(this->textures["BODY"], 114.f, 50.f, DIR_X::RIGHT, DIR_Y::ZERO_Y));

	this->apple = new Apple(this->textures["APPLES"], *this->window);

	this->applesCount++;

}

void Game::initTextures()
{
	this->textures["BODY"] = new sf::Texture;
	if (!this->textures["BODY"]->loadFromFile("src/textures/snake_body.png")) {
		std::cout << "ERROR::LOAD::error while loading snake_body.png\n";
	}

	this->textures["APPLES"] = new sf::Texture;
	if (!this->textures["APPLES"]->loadFromFile("src/textures/apple.png")) {
		std::cout << "ERROR::LOAD::error while loading apple.png\n";
	}

}

void Game::addTail()
{
	//checks where last tail going and depending on it spawns new tail
	float spawn_pos_X{0.f};
	float spawn_pos_Y{0.f};

	float dir_x = this->snakeBody[this->snakeBody.size() - 1]->getDir().x;
	float dir_y = this->snakeBody[this->snakeBody.size() - 1]->getDir().y;

	//calculate new tail pos
	if (this->snakeBody[this->snakeBody.size() - 1]->getDir().x != 0) {

		spawn_pos_X = this->snakeBody[this->snakeBody.size() - 1]->getDir().x > 0 ? this->snakeBody[this->snakeBody.size() - 1]->getPos().x - 36 :
			this->snakeBody[this->snakeBody.size() - 1]->getPos().x + 36;
		spawn_pos_Y = this->snakeBody[this->snakeBody.size() - 1]->getPos().y;

	}
	else {
		spawn_pos_X = this->snakeBody[this->snakeBody.size() - 1]->getPos().x;
		spawn_pos_Y = this->snakeBody[this->snakeBody.size() - 1]->getDir().y > 0 ? this->snakeBody[this->snakeBody.size() - 1]->getPos().y - 36 :
			this->snakeBody[this->snakeBody.size() - 1]->getPos().y + 36;
	}
	
	this->snakeBody.push_back(new Body(this->textures["BODY"], spawn_pos_X, spawn_pos_Y, dir_x, dir_y));


}
