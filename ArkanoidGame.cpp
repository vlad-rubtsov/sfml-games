#include "ArkanoidGame.h"


const int ROWS = 10;
const int COLS = 10;


ArkanoidGame::ArkanoidGame(int width, int height) : Game(width, height)
{
	static_assert(BLOCKS_MAX >= COLS * ROWS, "Increase max blocks");
}


ArkanoidGame::~ArkanoidGame() 
{
}


void ArkanoidGame::OnInit()
{
	ballCoord.x = 250;
	ballCoord.y = 400;
	ballDiff.x = 6;
	ballDiff.y = -5;
	textureBall.loadFromFile("ball.png");
	spriteBall.setTexture(textureBall);
	spriteBall.setPosition(ballCoord);

	textureBackground.loadFromFile("background.jpg");
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(sf::Vector2f(0, 0));

	texturePaddle.loadFromFile("paddle.png");
	spritePaddle.setTexture(texturePaddle);
	spritePaddle.setPosition(sf::Vector2f(300, 440));

	textureBlock.loadFromFile("block01.png");
	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			spriteBlock[i * COLS + j].setTexture(textureBlock);
			spriteBlock[i * COLS + j].setPosition((i + 1) * 43, (j + 1) * 20);
		}
	}
}


void ArkanoidGame::OnUpdate()
{
	ballCoord.x += ballDiff.x;

	float x = ballCoord.x;
	float y = ballCoord.y;

	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			if (sf::FloatRect(x + 3, y + 3, 6, 6).intersects(spriteBlock[i * COLS + j].getGlobalBounds()))
			{
				spriteBlock[i * COLS + j].setPosition(-200, -100);
				ballDiff.x = - ballDiff.x;
			}
		}
	}

	ballCoord.y += ballDiff.y;

	x = ballCoord.x;
	y = ballCoord.y;


	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			if (sf::FloatRect(x + 3, y + 3, 6, 6).intersects(spriteBlock[i * COLS + j].getGlobalBounds()))
			{
				spriteBlock[i * COLS + j].setPosition(-200, -100);
				ballDiff.y = - ballDiff.y;
			}
		}
	}

	if (ballCoord.y < 0 || ballCoord.y > Game::windowHeight)
	{
		ballDiff.y = -ballDiff.y;
	}
	if (ballCoord.x < 0 || ballCoord.x > Game::windowWidth)
	{
		ballDiff.x = -ballDiff.x;
	}

	if (sf::FloatRect(x, y, 12, 12).intersects(spritePaddle.getGlobalBounds()))
	{
		ballDiff.y = -(rand() % 5 + 2);
	}

	spriteBall.setPosition(ballCoord);
}


void ArkanoidGame::OnDraw(Window& window)
{
	window.Draw(spriteBackground);

	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			window.Draw(spriteBlock[i * COLS + j]);
		}
	}

	window.Draw(spriteBall);
	window.Draw(spritePaddle);
}


void ArkanoidGame::OnHandleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		spritePaddle.move(6, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		spritePaddle.move(-6, 0);
}
