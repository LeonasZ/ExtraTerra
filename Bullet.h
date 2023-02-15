#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"
class Bullet
{
private:
	sf::Sprite shape;
	//sf::Texture *texture; //its a pointer because we load textures only one time

	sf::Vector2f direction;
	float movementSpeed;
public:
	Bullet();
	Bullet(sf::Texture *texture,float pos_x,float pos_y,float dir_x, float dir_y,float movement_speed); 
																				//si le paso el puntero de la textura en el constructor ya 
	virtual ~Bullet();															//tengo la textura cargada y no tengo que cargar una 
																				//por una cada vez que se crea una bala
																				//pos_x y pos_y son la posicion de origen
	//Accesors
	const sf::FloatRect getBounds() const;

	//modifiers
	void gainBulletAttackSpeed(); 

	//functions
	void update();
	void draw(sf::RenderTarget& target);
};

