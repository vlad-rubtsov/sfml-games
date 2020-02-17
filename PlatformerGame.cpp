
#include "PlatformerGame.h"

using namespace sf;



const float DELAY    = 0.1f;
const int TIME_SPEED = 700;  // bigger is slower

int BLOCK_SIZE = 16;

float offsetX = 0;
float offsetY = 0;

PlatformerGame::PlatformerGame(const std::string& title, int width, int height) 
: player(&world)
, Game(title, width, height)
{
	Reset();
}


PlatformerGame::~PlatformerGame() 
{
}


void PlatformerGame::Reset()
{
	time = 0;
}


void PlatformerGame::OnInit()
{
	texture1.loadFromFile("images/mario_tileset.png");
	player.SetTexture(texture1);
	world.SetTexture(texture1);
}


void PlatformerGame::OnUpdate()
{
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	time /= TIME_SPEED;
	if (time > 20)
		time = 20;

	player.Update(time);

	if (player.GetRect().left > windowWidth / 2)
	{
		offsetX = player.GetRect().left - windowWidth / 2;
	}
	//offsetY = player.GetRect().top - windowHeight / 2;
	offsetY = 0;
	world.SetOffset(offsetX, offsetY);
}


void PlatformerGame::OnDraw(::Window& window)
{
	world.Draw(window);
	player.Draw(window);
}


void PlatformerGame::OnHandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player.MoveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		player.MoveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (player.IsOnGround())
		{
			player.Jump();
		}
	}
}
