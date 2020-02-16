#ifndef PLATFORMER_H
#define PLATFORMER_H

#include "Game.h"
#include "Player.h"

class PlatformerGame : public Game
{
public:
	PlatformerGame(const std::string& title, int width, int height);
	virtual ~PlatformerGame();

	virtual void OnInit() override;
	virtual void OnUpdate() override;
	virtual void OnDraw(Window& window) override;
	virtual void OnHandleInput();

private:
	//void Tick(float timer);
	void Reset();

private:
	sf::Texture texture1;
	//sf::Sprite sprite1;
	Player player;

	sf::Clock clock;

	float time;
	float timer;

	float curFrame = 0.f;
};

#endif