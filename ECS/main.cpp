#ifdef _DEBUG
# define _CRTDBG_MAP_ALLOC
# include <crtdbg.h>
#endif

#include <SFML/Graphics.hpp>

#include "Entity.hpp"
#include "Engine.hpp"
#include "EntityManager.hpp"

#include "RenderComponent.hpp"

int main(void)
{
#ifdef _DEBUG
	{
#endif
		Engine engine;

		engine.createPlayer(1);
		
		sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			//engine.input()
			//engine.update();
			engine.draw(window);

			/*window.clear();
			window.draw(shape);
			window.display();*/
		}

#ifdef _DEBUG
	}
	_CrtDumpMemoryLeaks();
	system("pause");
#endif

	return 0;
}