#include "FifteenGame.h"

#include <iostream>

FifteenGame::FifteenGame(const std::string& title, int width, int height) 
: Game(title, width, height)
{
	font.loadFromFile("arial.ttf");
}


void FifteenGame::OnInit()
{
	sf::View view(sf::FloatRect(0.f, 0.f, windowWidth, windowHeight));
	view.move(sf::Vector2f(-50, -50));

	GetWindow().GetRender().setView(view);

	text.setFont(font);
	text.setString("F2 - New Game / Esc - Exit / Arrow keys - Move Tile");
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Cyan);
	text.setPosition(-5.f, -25.f);

	for (int i = 0; i < ARRAY_SIZE - 1; ++i)
	{
		elements[i] = i + 1;
	}
	solved = true;
	empty_index = ARRAY_SIZE - 1;
	elements[empty_index] = 0;
}


void FifteenGame::OnDraw(Window& window)
{
	window.Draw(text);

	sf::Color color(200, 100, 200);

	sf::RectangleShape shape(sf::Vector2f(FIELD_SIZE, FIELD_SIZE));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);
	window.Draw(shape);

	shape.setSize(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);

	sf::Text fieldText("", font, 52);

	for (unsigned int i = 0; i < ARRAY_SIZE; i++)
	{
		fieldText.setString(std::to_string(elements[i]));
		fieldText.setFillColor(color);
		shape.setOutlineColor(color);

		if (solved)
		{
			shape.setOutlineColor(sf::Color::Cyan);
			fieldText.setFillColor(sf::Color::Cyan);
		}
		else if (elements[i] == i + 1)
		{
			fieldText.setFillColor(sf::Color::Green);
		}

		if (elements[i] > 0)
		{
			sf::Vector2f position(i % SIZE * CELL_SIZE + 10.f, i / SIZE * CELL_SIZE + 10.f);
			shape.setPosition(position);
			fieldText.setPosition(position.x + 30.f + ((elements[i] < 10) ? 10.f : 0.f), position.y + 30.f);
			window.Draw(shape);
			window.Draw(fieldText);
		}
	}
}


void FifteenGame::Move(Direction direction)
{
	//std::cout << "Move: " << (int)direction << std::endl;
	const int col = empty_index % SIZE;
	const int row = empty_index / SIZE;

	int move_index = -1;

	if (direction == Direction::LEFT &&	col < (SIZE - 1))
		move_index = empty_index + 1;
	if (direction == Direction::RIGHT && col > 0)
		move_index = empty_index - 1;
	if (direction == Direction::UP && row < (SIZE - 1))
		move_index = empty_index + SIZE;
	if (direction == Direction::DOWN && row > 0)
		move_index = empty_index - SIZE;


	if (empty_index >= 0 && move_index >= 0)
	{
		int tmp = elements[empty_index];
		elements[empty_index] = elements[move_index];
		elements[move_index] = tmp;
		empty_index = move_index;
	}

	solved = Check();
}

/*
void FifteenGame::OnHandleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		Move(Direction::RIGHT);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		Move(Direction::LEFT);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		Move(Direction::UP);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		Move(Direction::DOWN);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
		NewGame();
}
*/

void FifteenGame::OnHandleInput(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		//std::cout << "Input: " << std::endl;
		if (event.key.code == sf::Keyboard::Right)
			Move(Direction::RIGHT);
		if (event.key.code == sf::Keyboard::Left)
			Move(Direction::LEFT);
		if (event.key.code == sf::Keyboard::Up)
			Move(Direction::UP);
		if (event.key.code == sf::Keyboard::Down)
			Move(Direction::DOWN);
		if (event.key.code == sf::Keyboard::F2)
			NewGame();
	}
}

bool FifteenGame::Check() const
{
	for (unsigned int i = 0; i < ARRAY_SIZE; ++i)
	{
		if (elements[i] > 0 && elements[i] != i + 1)
			return false;
	}
	return true;
}


void FifteenGame::NewGame()
{
	OnInit();

	for (int i = 0; i < 100; ++i)
	{
		Move((Direction)(rand() % 4));
	}
}
