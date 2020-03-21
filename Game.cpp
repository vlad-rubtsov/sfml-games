#include "Game.h"

#include <iostream>

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

	sf::sleep(sf::seconds(0.02));
}


void Game::HandleInput()
{
	sf::Event event;
	while (window.GetRender().pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.Close();
		}
		if ((event.type == sf::Event::KeyPressed) && 
			(event.key.code == sf::Keyboard::Escape))
		{
			window.Close();
		}
		OnHandleInput(event);
	}
}
