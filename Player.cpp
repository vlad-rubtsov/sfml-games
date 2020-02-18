#include "Player.h"
#include "Window.h"
#include "World.h"
#include <SFML/System/String.hpp>


extern int BLOCK_SIZE;

const int START_POS_X = 100;
const int START_POS_Y = 100;
const int TEXTURE_POS_Y = 144;

const float DY_STEP = 0.0005f;
const float FRAME_STEP = 0.005f;

const int FRAMES = 3;


Player::Player(const World* pNewWorld) : pWorld(pNewWorld) 
{
	rect = sf::FloatRect(START_POS_X, START_POS_Y, BLOCK_SIZE, BLOCK_SIZE);
	dx = dy = 0.1;
	curFrame = 0;
	onGround = false;
}


void Player::SetTexture(sf::Texture& texture)
{
	sprite.setTexture(texture);
}


void Player::Draw(::Window& window)
{
	window.Draw(sprite);
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
		sprite.setTextureRect(sf::IntRect(112 + 31 * int(curFrame), TEXTURE_POS_Y, BLOCK_SIZE, BLOCK_SIZE));
	}
	if (dx < 0)
	{
		sprite.setTextureRect(sf::IntRect(112 + 31 * int(curFrame) + BLOCK_SIZE, TEXTURE_POS_Y, -BLOCK_SIZE, BLOCK_SIZE));
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
			if (pWorld->Intersects(i, j))
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
		}
	}
}


void Player::CollisionY()
{
	for (int i = rect.top / BLOCK_SIZE; i < (rect.top + rect.height) / BLOCK_SIZE; ++i)
	{
		for (int j = rect.left / BLOCK_SIZE; j < (rect.left + rect.width) / BLOCK_SIZE; ++j)
		{
			if (pWorld->Intersects(i, j))
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
		if (!pWorld->Intersects(i, j))
		{
			onGround = false;
		}
	}
	if (dx > 0)
	{
		int i = (rect.top + rect.height) / BLOCK_SIZE;
		int j = (rect.left -1) / BLOCK_SIZE;
		if (!pWorld->Intersects(i, j))
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
	dy = -0.27;
	onGround = false;
}


void Player::SetOffset(float x, float y)
{
	offsetX = x;
	offsetY = y;
}
