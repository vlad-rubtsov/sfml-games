#include "World.h"
#include "Window.h"

using namespace sf;

extern int BLOCK_SIZE;


void World::Draw(::Window& window)
{
	sf::Sprite tile(texture);
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			if (TileMap[i][j] == 'P')
			{
				//rectShape.setFillColor(sf::Color::Black);
				tile.setTextureRect(sf::IntRect(143 - 16 * 3, 112, 16, 16));
			}
			if (TileMap[i][j] == 'k')
			{
				tile.setTextureRect(sf::IntRect(143, 112, 16, 16));
			}

			if (TileMap[i][j] == 'c')
				tile.setTextureRect(sf::IntRect(143 - 16, 112, 16, 16));
			if (TileMap[i][j] == 't')
				tile.setTextureRect(IntRect(0, 47, 32, 95 - 47));

			if (TileMap[i][j] == 'g')
				tile.setTextureRect(sf::IntRect(0, 16 * 9 - 5, 3 * 16, 16 * 2 + 5));

			if (TileMap[i][j] == 'G')
				tile.setTextureRect(sf::IntRect(145, 222, 222 - 145, 255 - 222));

			if (TileMap[i][j] == 'd')
				tile.setTextureRect(sf::IntRect(0, 106, 74, 127 - 106));

			if (TileMap[i][j] == 'w')
				tile.setTextureRect(sf::IntRect(99, 224, 140 - 99, 255 - 224));

			if (TileMap[i][j] == 'r')
				tile.setTextureRect(sf::IntRect(143 - 32, 112, 16, 16));
			if (TileMap[i][j] == ' ' || TileMap[i][j] == '0')
			{
				continue;
			}
			tile.setPosition(j * BLOCK_SIZE - offsetX, i * BLOCK_SIZE - offsetY);
			window.Draw(tile);
		}
	}
}
