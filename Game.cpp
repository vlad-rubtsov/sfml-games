#include "Game.h"


Game::Game(const std::string& title, int width, int height) 
 : window(title, width, height)
 , windowWidth(width)
 , windowHeight(height)
{
    srand(time(0));
}

Game::~Game()
{
}

void Game::Init()
{
	// game init here
	OnInit();
}

void Game::Update()
{
	window.Update();

	// objects update here
	OnUpdate();
}

void Game::Render()
{
	window.BeginDraw();

	// objects draw here
	OnDraw(window);

	window.EndDraw();

	//sf::sleep(sf::seconds(0.12));
}

void Game::HandleInput()
{
	OnHandleInput();
}
