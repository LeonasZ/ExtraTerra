#include "Menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Fonts/Vogue.ttf"))
	{
		// handle error
	}
	if (!this->backgroundTexture.loadFromFile("Textures/menubackground.png")) {
		std::cout << "MENU::MENU Couldnt load background menu texture from file" << "\n";
	}
	this->backgroundSprite.setTexture(this->backgroundTexture);


	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2.f - menu[0].getGlobalBounds().width/2.f, height / (MAX_NUMBER_OF_ITEMS +1 ) * 1 + 50.f) );


	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(width / 2.f - menu[1].getGlobalBounds().width / 2.f, height / (MAX_NUMBER_OF_ITEMS + 1) * 2 - 50.f));

	selectedItemIndex = 0;
}


Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(this->backgroundSprite);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}


}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
