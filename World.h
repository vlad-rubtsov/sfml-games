#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>

class Window;


class World
{
public:
	static const int H = 17;
	static const int W = 150;

	void SetTexture(sf::Texture& newTexture)
	{
		texture = newTexture;
	}

	void SetOffset(float x, float y)
	{
		offsetX = x;
		offsetY = y;
	}

	bool Intersects(int i, int j) const;

	void Draw(::Window& window);

private:
	sf::String TileMap[H] = {
		"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
		"0                                                                                                                                                    0",
		"0                                                                                    w                                                               0",
		"0                   w                                  w                   w                                                                         0",
		"0                                      w                                       kk                                                                    0",
		"0                                                                             k  k    k    k                                                         0",
		"0                      c                                                      k      kkk  kkk  w                                                     0",
		"0                                                                       r     k       k    k                                                         0",
		"0                                                                      rr     k  k                                                                   0",
		"0                                                                     rrr      kk                                                                    0",
		"0               c    kckck                                           rrrr                                                                            0",
		"0                                      t0                           rrrrr                                                                            0",
		"0G                                     00              t0          rrrrrr            G                                                               0",
		"0           d    g       d             00              00         rrrrrrr                                                                            0",
		"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
		"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
		"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
	};

	sf::Texture texture;

	float offsetX = 0;
	float offsetY = 0;
};

#endif