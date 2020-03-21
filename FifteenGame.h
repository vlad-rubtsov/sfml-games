#ifndef FIFTEEN_H
#define FIFTEEN_H

#include "Game.h"

const int SIZE = 4;
const int ARRAY_SIZE = SIZE * SIZE;
const int FIELD_SIZE = 500;
const int CELL_SIZE = 120;

enum class Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class FifteenGame : public Game
{
public:
	FifteenGame(const std::string& title, int width, int height);

	virtual void OnDraw(Window& window) override;

protected:
	virtual void OnInit() override;
	//virtual void OnHandleInput() override;
	virtual void OnHandleInput(sf::Event& event) override;

private:
	void Move(Direction direction);
	bool Check() const;
	void NewGame();

	int elements[ARRAY_SIZE];
	int empty_index;
	bool solved;

	sf::Font font;
	sf::Text text;
};

#endif
