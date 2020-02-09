#ifndef GAME_H
#define GAME_H

#include "Window.h"

class Game
{
public:
	Game();
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

private:

	Window window;
};

#endif