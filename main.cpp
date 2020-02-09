#include "Game.h"
#include "Window.h"

#include <SFML/Graphics.hpp>

//using namespace sf;

//*
const int RADIUS = 12;
//*/



int main()
{
    srand(time(0));

	Game game;

	//game.Init();

	while (!game.GetWindow()->IsDone())
	{
		game.HandleInput();
		game.Update();
		game.Render();
	}

/*
	Window wnd;
	wnd.Setup("Arkanoid", sf::Vector2u(WIDTH, HEIGHT));

	while (!wnd.IsDone())
	{
		wnd.Update();
		wnd.BeginDraw();
		//wnd.Draw();
		wnd.EndDraw();
	}
*/

#if 0
    float x = rand() % (WIDTH - RADIUS * 2);
    float y = rand() % (HEIGHT - RADIUS * 2);

	int dx = 2;
	int dy = 2;


    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "first SFML");
    window.setFramerateLimit(60);

	sf::Texture texture;
	texture.loadFromFile("ball.png");

	sf::Sprite sprite(texture);
    sprite.setPosition(sf::Vector2f(x, y));

	sprite.setColor(sf::Color::Green);

/*
    sf::CircleShape shape(RADIUS);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(x, y));
//*/

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape) 
					window.close();
				
				if (event.key.code == sf::Keyboard::Down)
				{
					dy += (dy > 0) ? -1 : 1;
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					dy += (dy > 0) ? 1 : -1;
				}
            }
        }

        window.clear();

        // Update
		x +=dx;
		y +=dy;
		//shape.setPosition(sf::Vector2f(x, y));
		sprite.setPosition(sf::Vector2f(x, y));

		if (x + 1 * RADIUS >= WIDTH)
			dx = -1 * dx;
		if (x <= 0)
			dx = -1 * dx;
		if (y + 1 * RADIUS >= HEIGHT)
			dy = -1 * dy;
		if (y <= 0)
			dy = -1 * dy;

        // Draw
        //window.draw(shape);
		window.draw(sprite);

        window.display();
    }
#endif
    return 0;
}
