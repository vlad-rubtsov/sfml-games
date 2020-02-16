
#include "PlatformerGame.h"

const int WIDTH = 600;
const int HEIGHT = 400;


int main()
{
	PlatformerGame game(std::string("Platformer"), WIDTH, HEIGHT);

	game.Init();

	while (!game.GetWindow()->IsDone())
	{
		game.HandleInput();
		game.Update();
		game.Render();
	}

    return 0;
}
