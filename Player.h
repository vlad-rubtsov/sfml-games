#ifndef PLAYER_H
#define PLAYER_H


#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "AnimationHolder.h"

class Window;
class World;


class Player
{
public:
	Player(const World* pWorld);

	void SetTexture(sf::Texture& texture);
	void Update(float time);

	void MoveLeft();
	void MoveRight();
	void Jump();
	void SetOffset(float x, float y);

	void Draw(::Window& window);

	bool IsOnGround() const { return onGround; }

	sf::FloatRect GetRect() const { return rect; }

protected:
	bool onGround;

	float dx;
	float dy;
	float curFrame;

	sf::FloatRect rect;

	AnimationHolder animation;

private:
	void CollisionX();
	void CollisionY();

private:
	const World* pWorld;

	float offsetX = 0;
	float offsetY = 0;
};

#endif
