#ifndef PLAYER_H
#define PLAYER_H


#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>


class Player
{
public:
	Player();

	void SetTexture(sf::Texture& texture);
	void Update(long long time);

	void MoveLeft();
	void MoveRight();
	void Jump();
	bool IsOnGround() const { return onGround; }

	sf::FloatRect GetRect() const { return rect; }
	const sf::Sprite& GetSprite() const { return sprite; }

protected:
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
