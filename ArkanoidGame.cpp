#include "ArkanoidGame.h"

ArkanoidGame::~ArkanoidGame() {}


void ArkanoidGame::OnInit()
{
	texture_.loadFromFile("ball.png");
	spriteBall.setTexture(texture_);
	spriteBall.setPosition(sf::Vector2f(250, 500));
}


void ArkanoidGame::OnDraw(Window& window)
{
	window.Draw(spriteBall);
}
