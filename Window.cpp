#include "Window.h"


Window::Window(const std::string& title, uint height, uint width)
: bDone_(false)
{
	Setup(title, sf::Vector2u(height, width));
}

Window::~Window()
{
	Destroy();
}


void Window::Setup(const std::string& title, const sf::Vector2u& size)
{
	title_ = title;
	size_  = size;
	renderWindow.setTitle(title_);
	renderWindow.setSize(size_);
	renderWindow.setFramerateLimit(60);

	Create();
}


void Window::Update()
{
//*
	sf::Event event;
	while (renderWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			bDone_ = true;
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		{
			bDone_ = true;
		}
	}
//*/
}


void Window::BeginDraw()
{
	renderWindow.clear();
}


void Window::EndDraw()
{
	renderWindow.display();
}


void Window::Draw(sf::Drawable& drawable)
{
	renderWindow.draw(drawable);
}


void Window::Create()
{
	auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	renderWindow.create({size_.x, size_.y, 32}, title_, style);
}


void Window::Destroy()
{
	renderWindow.close();
}
