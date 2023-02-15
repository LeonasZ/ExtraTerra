#pragma once
#include "SFML/Graphics.hpp"


class Enemy
{
private:
	sf::Sprite shape;


	int pointCount;
	int type;
	int hp;
	int hpMax;
	int points;
	int damage;
	float speed;



	//Private functions
	void initVariables();
	void initShape();

public:
	//constructor & destructor
	Enemy(sf::Texture* texture,float pos_x, float pos_y);
	virtual ~Enemy();	

	//Accesor
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;
	const int& getHp() const;

	//modifiers
	void loseHp(const int value);
	
	
	//functions
	
	void update();
	void draw(sf::RenderTarget& target);
};

