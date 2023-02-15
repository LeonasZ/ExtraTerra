#include "Player.h"

//Private Functions
void Player::initSprite()
{
	this->playerSprite.setTexture(this->playerTexture);
	this->playerSprite.setPosition(
		800.f / 2.f - this->playerSprite.getGlobalBounds().width / 2.f,
		600.f / 2.f - this->playerSprite.getGlobalBounds().height / 2.f);
}

void Player::initTextures()
{
	if (!this->playerTexture.loadFromFile("Textures/spaceship1.png")) {
		std::cout << "Player::initTexture::Couldnt load the file" << "\n";
	}
	this->playerTexture.setSmooth(true);

}

void Player::initVariables()
{
	this->hpMax = 100;
	this->hp = this->hpMax;
	this->movementSpeed = 10.f;
	this->attackCooldownMax = 20.f;
	this->attackCooldown = this->attackCooldownMax;
	this->attackDamage = 3;
}

//constructor && destructor
Player::Player()
{
	this->initTextures();
	this->initSprite();
	this->initVariables();
}

Player::~Player()
{
}
//Accesors
const sf::Vector2f& Player::getPos() const
{
	return this->playerSprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->playerSprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

const int& Player::getAttackDamage() const
{
	return this->attackDamage;
}

const int& Player::getAttackCooldown() const
{
	return this->attackSpeed;
}

//MODIFIERS
void Player::setPosition(const sf::Vector2f pos )
{
	this->playerSprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->playerSprite.setPosition(x,y);

}
void Player::setHp(const int hp)
{
	this->hp = hp;
}
void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0) {
		this->hp = 0;
	}
}

const int& Player::getAttackCooldownMax() const
{
	return this->attackCooldownMax;
}


//functions
void Player::update()
{
	this->updateAttackCooldown();
}

void Player::draw(sf::RenderTarget& target)
{
	target.draw(this->playerSprite);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax) {
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Player::updateAttackCooldown()
{
	if (this->attackCooldown < this->attackCooldownMax) {
		this->attackCooldown += 1.f;
	}
}

void Player::gainHp(const int value)
{
	this->hp += value;
}

void Player::move(const int dirX, const int dirY)
{
	this->playerSprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}



void  Player::reduceAttackCooldown()
{
	this->attackCooldownMax -= 0.5;
}


