#include "Player.h"
#include <SFML/System/String.hpp>


extern sf::String tileMap[];
extern int BLOCK_SIZE;

extern float offsetX;
extern float offsetY;

const int START_POS_X = 3;
const int START_POS_Y = 5;


Player::Player()
{
	rect = sf::FloatRect(START_POS_X * BLOCK_SIZE, START_POS_Y * BLOCK_SIZE, 40, 50);
	dx = dy = 0;
	curFrame = 0;
	onGround = false;
}


void Player::SetTexture(sf::Texture& texture)
{
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(40 * int(curFrame), 244, 40, 50));
}


void Player::Update(long long time)
{
	rect.left += dx * time;

	CollisionX();

	if (!onGround)
	{
		dy += 0.0002 * time;
	}
	rect.top += dy * time;

	CollisionY();

	curFrame += 0.002 * time;
	if (curFrame > 6)
		curFrame -= 6;
	if (dx > 0)
	{
		sprite.setTextureRect(sf::IntRect(40 * int(curFrame), 244, 40, 50));
	}
	if (dx < 0)
	{
		sprite.setTextureRect(sf::IntRect(40 * int(curFrame) + 40, 244, -40, 50));
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
	dy = -0.2;
	onGround = false;
}
