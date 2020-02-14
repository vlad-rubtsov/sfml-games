#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "Game.h"



class SnakeGame : public Game
{
public:
	SnakeGame(const std::string& title, int width, int height);
	virtual ~SnakeGame();

	virtual void OnInit() override;
	virtual void OnUpdate() override;
	virtual void OnDraw(Window& window) override;
	virtual void OnHandleInput();

private:
	void Tick();
	void Reset();

private:
	sf::Texture textureRed;
	sf::Texture textureWhite;
	sf::Texture textureGreen;

	sf::Sprite spriteBackground;
	sf::Sprite spriteSnake;
	sf::Sprite spriteApple;

	sf::Clock clock;

	float timer;

	static const int SEGMENT_MAX = 100;
	int nSegments;

	enum class etDirection
	{
		eNONE,
		eUP,
		eDOWN,
		eRIGHT,
		eLEFT
	}
	direction;

	struct SnakeSegment
	{
		int x;
		int y;
		bool operator==(const SnakeSegment& other) const
		{
			return (x == other.x && y == other.y);
		}
	}
	snakePos[SnakeGame::SEGMENT_MAX] = {-1, -1};

	SnakeSegment applePos;
	
};

#endif