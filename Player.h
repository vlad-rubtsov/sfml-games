#ifndef PLAYER_H
#define PLAYER_H


#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>


class Player
{

	const int GROUND = 400;

public:
	Player();

	void SetTexture(sf::Texture& texture);
	void Update(float time);

public:
	bool onGround;

	float dx;
	float dy;
	float curFrame;

	sf::FloatRect rect;
	sf::Sprite sprite;

private:
	void CollisionX();
	void CollisionY();
};

#endif
