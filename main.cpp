
#include "FifteenGame.h"

const int WIDTH = 600;
const int HEIGHT = 600;


int main()
{
	FifteenGame game(std::string("15"), WIDTH, HEIGHT);
	game.Init();

	while (!game.GetWindow().IsDone())
	{
		game.HandleInput();
		game.Update();
		game.Render();
	}

    return 0;
}
