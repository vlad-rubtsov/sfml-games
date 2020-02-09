#include "Game.h"

const int HEIGHT = 600;
const int WIDTH = 600;


Game::Game() : window("Game", HEIGHT, WIDTH)
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
}

void Game::HandleInput()
{
	OnHandleInput();
}
