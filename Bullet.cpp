#include "Bullet.h"
//constructor && destructor
Bullet::Bullet()
{
}

Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed )
{
	this->shape.setTexture(*texture);
	this->shape.setPosition(pos_x, pos_y);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
}

Bullet::~Bullet()
{
}
//Accesors
const sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}
//modifiers
void Bullet::gainBulletAttackSpeed()
{
	this->movementSpeed = 2;
}

//functions
void Bullet::update()
{
	//move
	this->shape.move(this->direction * this->movementSpeed);
}

void Bullet::draw(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
