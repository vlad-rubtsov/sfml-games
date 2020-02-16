
#include "PlatformerGame.h"

using namespace sf;


const float DELAY    = 0.1f;
const int TIME_SPEED = 140;  // bigger is slower

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
	timer = 0;
}


void PlatformerGame::OnInit()
{
	texture1.loadFromFile("images/fang.png");
	player.SetTexture(texture1);
}


void PlatformerGame::OnUpdate()
{
	time = clock.getElapsedTime().asMicroseconds() / TIME_SPEED;
	clock.restart();
	timer += time;
	player.Update(time);

	if (player.rect.left > windowWidth / 2)
	{
		offsetX = player.rect.left - windowWidth / 2;
	}
	offsetY = player.rect.top - windowHeight / 2;
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

	window.Draw(player.sprite);
}


void PlatformerGame::OnHandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player.dx = 0.1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		player.dx = -0.1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (player.onGround)
		{
			player.dy = -0.2;
			player.onGround = false;
		}
	}
}
