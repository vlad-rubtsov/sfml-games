#include "Game.h"

const int HEIGHT = 600;
const int WIDTH = 600;


Game::Game() : window("Game", HEIGHT, WIDTH)
{
	// game init here
	texture_.loadFromFile("ball.png");
	sprite_.setTexture(texture_);
    sprite_.setPosition(sf::Vector2f(100, 100));
}

Game::~Game()
{
}

void Game::Update()
{
	window.Update();

	// objects update here
}

void Game::Render()
{
	window.BeginDraw();

	// objects draw here

	window.Draw(sprite_);

	window.EndDraw();
}

void Game::HandleInput()
{

}
