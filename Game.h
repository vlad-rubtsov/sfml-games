#ifndef GAME_H
#define GAME_H

#include "Window.h"

class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	const Window* GetWindow() const { return &window; }
	//Window* GetWindow() { return m_window; }

protected:

	sf::Texture texture_;
	sf::Sprite sprite_;

private:

	Window window;

};

#endif