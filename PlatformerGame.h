#ifndef PLATFORMER_H
#define PLATFORMER_H

#include "Game.h"
#include "Player.h"
#include "World.h"
#include "Level.h"

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
	void Reset();

private:
	sf::Texture texture1;
	sf::Clock clock;

	World world;
	Player player;

	Level level;

	double time;

	float offsetX = 0;
	float offsetY = 0;
};

#endif