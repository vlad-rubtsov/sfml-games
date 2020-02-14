
#include "SnakeGame.h"

const int WIDTH = 520;
const int HEIGHT = 450;


int main()
{
	SnakeGame game(std::string("Snake"), WIDTH, HEIGHT);

	game.Init();

	while (!game.GetWindow()->IsDone())
	{
		game.HandleInput();
		game.Update();
		game.Render();
	}

    return 0;
}
