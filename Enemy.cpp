#include "Enemy.h"

//private functions
void Enemy::initVariables()
{
	this->type = rand() % 3 + 1; // minim = 3 , max = 10   //me da un numero entre 0 y 2, pero como le sumo 1 , el numero minimo sera 1 y el max 3
	this->hpMax = static_cast<int>(this->type * 3);
	this->hp = this->hpMax;
	this->points = static_cast<int>(this->type * 3);
	this->damage= static_cast<int>(this->type * 3);

}
void Enemy::initShape()
{
	
	switch (this->type)
	{
	case 1:
		this->shape.setTextureRect({ 9,0,58,60 });
		this->speed = 2.f;
		break;
	case 2:
		this->shape.setTextureRect({ 75,0,75,60 });
		this->shape.setScale(1.5, 1.5);
		this->speed = 3.f;
		break;
	case 3:
		this->shape.setTextureRect({ 251,0,70,60 });
		this->shape.setScale(2, 2);
		this->speed = 4.f;

		break;
	default:
		this->shape.setTextureRect({ 9,0,58,60 });
		break;
	}
}

//constructor & destructor
Enemy::Enemy(sf::Texture* texture, float pos_x, float pos_y)
{
	this->shape.setTexture(*texture);
	this->initVariables();
	
	this->initShape();

	this->shape.setPosition(pos_x, pos_y);
}

Enemy::~Enemy()
{
}

//Accesors
const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

const int& Enemy::getHp() const
{
	return this->hp;
}


//Modifiers

void Enemy::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp <= 0) {
		this->hp = 0;
	}
}






//functions
void Enemy::update()
{
	this->shape.move(0.f, this->speed);
}

void Enemy::draw(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
