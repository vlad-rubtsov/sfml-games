
#include "PlatformerGame.h"

using namespace sf;


const float DELAY    = 0.1f;
const int TIME_SPEED = 700;  // bigger is slower

const int H = 12;
const int W = 40;

int BLOCK_SIZE = 32;

float offsetX = 0;
float offsetY = 0;


String tileMap[] = {
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"B                                B     B",
"B                                B     B",
"B                                B     B",
"B                                B0    B",
"B         0000                BBBB     B",
"B          00                    B     B",
"BBB                              B     B",
"B              BB                BB    B",
"B              BB                      B",
"B    B         BB         BB           B",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};


PlatformerGame::PlatformerGame(const std::string& title, int width, int height) : Game(title, width, height)
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
	texture1.loadFromFile("images/fang.png");
	player.SetTexture(texture1);
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
}


void PlatformerGame::OnDraw(::Window& window)
{
	RectangleShape rectShape(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			if (tileMap[i][j] == 'B')
			{
				rectShape.setFillColor(Color::Black);
			}
			if (tileMap[i][j] == '0')
			{
				rectShape.setFillColor(Color::Green);
			}
			if (tileMap[i][j] == ' ')
			{
				continue;
			}
			rectShape.setPosition(j * BLOCK_SIZE - offsetX, i * BLOCK_SIZE - offsetY);
			window.Draw(rectShape);
		}
	}

	window.Draw(player.GetSprite());
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
