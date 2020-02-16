#include "Player.h"
#include <SFML/System/String.hpp>


extern sf::String tileMap[];
extern int BLOCK_SIZE;

extern float offsetX;
extern float offsetY;

const int START_POS_X = 7;
const int START_POS_Y = 9;

const int TEXTURE_POS_Y = 244;

const int IMG_WIDTH = 40;
const int IMG_HEIGHT = 50;

const float DY_STEP = 0.0005f;
const float FRAME_STEP = 0.005f;

const int FRAMES = 6;

Player::Player()
{
	rect = sf::FloatRect(START_POS_X * BLOCK_SIZE, START_POS_Y * BLOCK_SIZE, IMG_WIDTH, IMG_HEIGHT);
	dx = dy = 0.1;
	curFrame = 0;
	onGround = false;
}


void Player::SetTexture(sf::Texture& texture)
{
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(IMG_WIDTH * int(curFrame), TEXTURE_POS_Y, IMG_WIDTH, IMG_HEIGHT));
}


void Player::Update(float time)
{
	rect.left += dx * time;

	CollisionX();

	if (!onGround)
	{
		dy += DY_STEP * time;
	}
	rect.top += dy * time;

	CollisionY();

	curFrame += FRAME_STEP * time;
	if (curFrame > FRAMES)
		curFrame -= FRAMES;
	if (dx > 0)
	{
		sprite.setTextureRect(sf::IntRect(IMG_WIDTH * int(curFrame), TEXTURE_POS_Y, IMG_WIDTH, IMG_HEIGHT));
	}
	if (dx < 0)
	{
		sprite.setTextureRect(sf::IntRect(IMG_WIDTH * int(curFrame) + IMG_WIDTH, TEXTURE_POS_Y, -IMG_WIDTH, IMG_HEIGHT));
	}

	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

	dx = 0;
}


void Player::CollisionX()
{
	for (int i = rect.top / BLOCK_SIZE; i < (rect.top + rect.height) / BLOCK_SIZE; ++i)
	{
		for (int j = rect.left / BLOCK_SIZE; j < (rect.left + rect.width) / BLOCK_SIZE; ++j)
		{
			if (tileMap[i][j] == 'B')
			{
				if (dx > 0)
				{
					rect.left = j * BLOCK_SIZE - rect.width;
				}
				if (dx < 0)
				{
					rect.left = j * BLOCK_SIZE + BLOCK_SIZE;
				}
			}
			if (tileMap[i][j] == '0')
			{
				tileMap[i][j] = ' ';
			}
		}
	}
}


void Player::CollisionY()
{
	for (int i = rect.top / BLOCK_SIZE; i < (rect.top + rect.height) / BLOCK_SIZE; ++i)
	{
		for (int j = rect.left / BLOCK_SIZE; j < (rect.left + rect.width) / BLOCK_SIZE; ++j)
		{
			if (tileMap[i][j] == 'B')
			{
				if (dy > 0)
				{
					rect.top = i * BLOCK_SIZE - rect.height;
					dy = 0;
					onGround = true;
				}
				if (dy < 0)
				{
					rect.top = i * BLOCK_SIZE + BLOCK_SIZE;
					dy = 0;
				}
			}
		}
	}

	if (dx < 0)
	{
		int i = (rect.top + rect.height) / BLOCK_SIZE;
		int j = (rect.left + rect.width + 1) / BLOCK_SIZE;
		if (tileMap[i][j] == ' ')
		{
			onGround = false;
		}
	}
	if (dx > 0)
	{
		int i = (rect.top + rect.height) / BLOCK_SIZE;
		int j = (rect.left -1) / BLOCK_SIZE;
		if (tileMap[i][j] == ' ')
		{
			onGround = false;
		}
	}
}


void Player::MoveLeft()
{
	dx = -0.1;
}


void Player::MoveRight()
{
	dx = 0.1;
}


void Player::Jump()
{
	dy = -0.35;
	onGround = false;
}
