//#include "Game.h"
//#include "Window.h"

//#include <SFML/Graphics.hpp>

//using namespace sf;

/*
const int RADIUS = 12;
//*/


#include "ArkanoidGame.h"

const int WIDTH = 520;
const int HEIGHT = 450;


int main()
{
	ArkanoidGame game(WIDTH, HEIGHT);

	game.Init();

	while (!game.GetWindow()->IsDone())
	{
		game.HandleInput();
		game.Update();
		game.Render();
	}

    return 0;
}
