#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SFML/System/Vector2.hpp>
#include "SFML/Graphics.hpp"

class Window
{
public:

	Window(const std::string& title, uint height, uint width);
	~Window();

	bool IsDone() const { return bDone_; }

	void Update();

	void BeginDraw();
	void EndDraw();
	void Draw(sf::Drawable& drawable);

	void Close() { bDone_ = true; }


protected:
	void Setup(const std::string& title, const sf::Vector2u& size);

	void Create();
	void Destroy();

private:
	bool m_isFullscreen = false;
	bool bDone_ = false;
	std::string title_;
	sf::Vector2u size_;
	sf::RenderWindow renderWindow;
};

#endif