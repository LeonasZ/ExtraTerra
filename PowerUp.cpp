#include "PowerUp.h"
void PowerUp::initVariables()
{
	//variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;

	this->type = 1 + std::rand() % (2 + 1 - 1);
	this->hpHeal = 10;
}
//private functions
void PowerUp::initShape()
{
	switch (this->type)
	{
	case 1:
		this->shape.setTextureRect({ 240,166,36,30 });
		break;
	case 2:
		this->shape.setTextureRect({ 245,115,26,40 });
		break;
	}
	
}

//constructor & destructor
PowerUp::PowerUp(sf::Texture* textures, float pos_x, float pos_y)
{
	this->shape.setTexture(*textures);
	this->initVariables();
	this->initShape();

	this->shape.setPosition(pos_x, pos_y);
}

PowerUp::~PowerUp()
{
}
//Accesors
const sf::FloatRect PowerUp::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int& PowerUp::getHpHeal() const
{
	return this->hpHeal;
}

const int& PowerUp::getType() const
{
	return this->type;
}



//functions
void PowerUp::update()
{
}

void PowerUp::draw(sf::RenderTarget& target)
{
	target.draw(this->shape);
}


