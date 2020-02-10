#ifndef ARKANOIDGAME_H
#define ARKANOIDGAME_H

#include "Game.h"

const int BLOCKS_MAX = 100;
class ArkanoidGame : public Game
{
public:
	ArkanoidGame(int width, int height);
	virtual ~ArkanoidGame();

	virtual void OnInit() override;
	virtual void OnUpdate() override;
	virtual void OnDraw(Window& window) override;
	virtual void OnHandleInput();

private:

	sf::Texture textureBall;
	sf::Texture textureBlock;
	sf::Texture texturePaddle;
	sf::Texture textureBackground;

	sf::Sprite spriteBackground;
	sf::Sprite spriteBlock[BLOCKS_MAX];
	sf::Sprite spritePaddle;
	sf::Sprite spriteBall;

	sf::Vector2f ballCoord;
	sf::Vector2f ballDiff;
};


#endif // ARKANOIDGAME_H