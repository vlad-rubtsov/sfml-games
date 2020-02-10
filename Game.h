#ifndef GAME_H
#define GAME_H

#include "Window.h"

class Game
{
public:
	Game(int width, int height);
	virtual ~Game();

	virtual void OnInit() {}
	virtual void OnDraw(Window& window) {}
	virtual void OnUpdate() {}
	virtual void OnHandleInput() {}

	void Init();
	void HandleInput();
	void Update();
	void Render();
	const Window* GetWindow() const { return &window; }

protected:
	int windowWidth;
	int windowHeight;

private:
	Window window;
};

#endif