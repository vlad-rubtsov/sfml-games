#ifndef ARKANOIDGAME_H
#define ARKANOIDGAME_H

#include "Game.h"



class ArkanoidGame : public Game
{
public:
	virtual ~ArkanoidGame();

	virtual void OnInit() override;

	virtual void OnDraw(Window& window) override;


protected:
	sf::Texture texture_;

private:
	sf::Sprite spriteBackground;
	sf::Sprite spriteBlock[100];
	sf::Sprite spritePaddle;
	sf::Sprite spriteBall;

};


#endif // ARKANOIDGAME_H