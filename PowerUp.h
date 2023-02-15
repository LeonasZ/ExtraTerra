#pragma once
#include "SFML/Graphics.hpp"
class PowerUp
{
private:
	sf::Sprite shape;

	int type;
	int hpHeal;

	//private functions
	void initVariables();
	void initShape();


public:
	//constructor & destructor
	PowerUp(sf::Texture* textures, float pos_x, float pos_y);
	virtual ~PowerUp();

	//accesors
	const sf::FloatRect getBounds() const;
	const int& getHpHeal() const; //devuelve la hp que cura
	const int& getType() const;	//devuelve el tipo de powerup


	//functions
	void update();
	void draw(sf::RenderTarget &target);
};

