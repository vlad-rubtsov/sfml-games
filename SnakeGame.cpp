
#include "SnakeGame.h"

using namespace sf;

const int FIELD_WIDTH = 30;
const int FIELD_HEIGHT = 20;
const int BLOCK_SIZE = 16;
const int WIDTH = BLOCK_SIZE * FIELD_WIDTH;
const int HEIGHT = BLOCK_SIZE * FIELD_HEIGHT;

const int SNAKE_HEAD_START_POS_X = 15;
const int SNAKE_HEAD_START_POS_Y = 10;
const int INCREMENT_BODY = 2;
const int START_BODY = 4;

const int APPLE_START_POS_X = 5;
const int APPLE_START_POS_Y = 5;

const float DELAY = 0.1f;


SnakeGame::SnakeGame(const std::string& title, int width, int height) : Game(title, WIDTH, HEIGHT)
{
	Reset();
}


SnakeGame::~SnakeGame() 
{

}

void SnakeGame::Reset()
{
	for (int i = 0; i < nSegments; ++i)
	{
		snakePos[i].x = SNAKE_HEAD_START_POS_X + i;
		snakePos[i].y = SNAKE_HEAD_START_POS_Y;
	}
	direction = etDirection::eNONE;
	nSegments = START_BODY;

	applePos.x = APPLE_START_POS_X;
	applePos.y = APPLE_START_POS_Y;
	timer = 0.0f;
}

void SnakeGame::OnInit()
{
	textureRed.loadFromFile("images/red.png");
	textureWhite.loadFromFile("images/white.png");
	textureGreen.loadFromFile("images/green.png");

	spriteApple.setTexture(textureGreen);
	spriteBackground.setTexture(textureWhite);
	spriteSnake.setTexture(textureRed);
}


void SnakeGame::OnUpdate()
{
	float time = clock.getElapsedTime().asSeconds();
	clock.restart();
	timer += time;
	if (timer >= DELAY)
	{
		timer = 0.0f;
		Tick();
	}
}


void SnakeGame::OnDraw(::Window& window)
{
	for (int i = 0; i < FIELD_WIDTH; ++i)
	{
		for (int j = 0; j < FIELD_HEIGHT; ++j)
		{
			spriteBackground.setPosition(i * BLOCK_SIZE, j * BLOCK_SIZE);
			window.Draw(spriteBackground);
		}
	}

	spriteApple.setPosition(applePos.x * BLOCK_SIZE, applePos.y * BLOCK_SIZE);
	window.Draw(spriteApple);

	for (int i = 0; i < nSegments; ++i)
	{
		spriteSnake.setPosition(snakePos[i].x * BLOCK_SIZE, snakePos[i].y * BLOCK_SIZE);
		window.Draw(spriteSnake);
	}
}


void SnakeGame::OnHandleInput()
{
	if (Keyboard::isKeyPressed(Keyboard::Left) && direction != etDirection::eRIGHT)
		direction = etDirection::eLEFT;
	if (Keyboard::isKeyPressed(Keyboard::Right) && direction != etDirection::eLEFT)
		direction = etDirection::eRIGHT;
	if (Keyboard::isKeyPressed(Keyboard::Up) && direction != etDirection::eDOWN)
		direction = etDirection::eUP;
	if (Keyboard::isKeyPressed(Keyboard::Down) & direction != etDirection::eUP)
		direction = etDirection::eDOWN;
}


void SnakeGame::Tick()
{
	// Move snake
	for (int i = nSegments - 1; i > 0; --i)
	{
		snakePos[i] = snakePos[i - 1];
	}
	switch (direction)
	{
		case etDirection::eDOWN:
			snakePos[0].y += 1;
		break;
		case etDirection::eLEFT:
			snakePos[0].x -= 1;
		break;
		case etDirection::eUP:
			snakePos[0].y -= 1;
		break;
		case etDirection::eRIGHT:
			snakePos[0].x += 1;
		break;
		default:
		break;
	}


	// Check with borders
	if (snakePos[0].x < 0 || snakePos[0].x > FIELD_WIDTH || 
		snakePos[0].y < 0 || snakePos[0].y > FIELD_HEIGHT)
	{
		Reset();
	}

	// Check with body
	for (int i = 1; i < nSegments; ++i)
	{
		if (snakePos[0] == snakePos[i])
		{
			Reset();
		}
	}

	// Check with apple
	if (applePos == snakePos[0])
	{
		applePos.x = rand() % FIELD_WIDTH;
		applePos.y = rand() % FIELD_HEIGHT;

		for (int i = nSegments; i < nSegments + INCREMENT_BODY; ++i)
		{
			snakePos[i] = snakePos[i - 1];
		}

		if (nSegments + INCREMENT_BODY < SEGMENT_MAX)
		{
			nSegments += INCREMENT_BODY;
		}
	}
}
