
#include <time.h>
#include "Game.h"
#include <iostream>
#include "Menu.h"

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "ExtraTerra", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);
	Menu menu(window.getSize().x, window.getSize().y); 

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
					{
						window.clear();
						window.display();

						Game game(window);
						while (!game.isRunning()) {
							game.run();
						}
						//una vez que pierde,espera a que el usuario presione enter para volver al menu anterior
						
							bool waitForSpace = true;

							while (waitForSpace)
							{
								sf::Event event;
								while (window.pollEvent(event))
								{
									if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace)
									{
										waitForSpace = false;
									}

								}

							}
						
						
						break;
					}
					
					case 1:
						//SALIR	
						window.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();

		menu.draw(window);

		window.display();
	}
	return 0;
}