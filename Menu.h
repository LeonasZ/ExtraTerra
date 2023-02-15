#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#define MAX_NUMBER_OF_ITEMS 2
class Menu
{
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

	//background images
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	

public:
	//constructor && desctructor
	Menu(float width, float height);
	~Menu();

	//functions
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	
};
