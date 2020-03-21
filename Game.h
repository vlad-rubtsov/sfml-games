#ifndef GAME_H
#define GAME_H

#include "Window.h"

class Game
{
public:
	Game(const std::string& title, int width, int height);
	virtual ~Game();

	void Init();
	void HandleInput();
	void Update();
	void Render();

	Window& GetWindow() { return window; }

protected:
	virtual void OnInit() {}
	virtual void OnDraw(Window& window) {}
	virtual void OnUpdate() {}
	virtual void OnHandleInput() {}
	virtual void OnHandleInput(sf::Event& event) {}

	int windowWidth;
	int windowHeight;

private:
	Window window;
};

#endif