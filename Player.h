#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
class Player
{
private:

	sf::Sprite playerSprite;
	sf::Texture playerTexture;

	int hp;
	int hpMax;

	float attackSpeed;
	int attackDamage;
	float attackCooldown;
	float attackCooldownMax;

	float movementSpeed;

	//Private functions
	void initSprite();
	void initTextures();
	void initVariables();

public:
	//Constructor & Destructor
	Player();
	virtual ~Player();

	//Accesor
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const; //make sure that there is no reference or pointer, because if we dont return a copy it will bug out
	const int& getHp() const;
	const int& getHpMax() const;
	const int& getAttackDamage() const;
	const int& getAttackCooldown() const;
	const int& getAttackCooldownMax() const;


	//Modifiers

	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void loseHp(const int value);
	void gainHp(const int value);
	void reduceAttackCooldown() ;


	//Functions
	void update();
	void draw(sf::RenderTarget &target);

	const bool canAttack();
	void updateAttackCooldown();

	void move(const int dirX, const int dirY);
};

