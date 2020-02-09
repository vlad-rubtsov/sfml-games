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
	//size_  = size;
	m_windowSize = size;
	window.setTitle(title_);
	//window.setSize(size_);
	window.setFramerateLimit(60);

	Create();
}


void Window::Update()
{
	sf::Event event;
	while (window.pollEvent(event))
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
}


void Window::BeginDraw()
{
	window.clear();
}


void Window::EndDraw()
{
	window.display();
}


void Window::Draw(sf::Drawable& drawable)
{
	window.draw(drawable);
}


void Window::Create()
{
	auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	window.create({m_windowSize.x, m_windowSize.y, 32}, title_, style);
}


void Window::Destroy()
{
	window.close();
}
