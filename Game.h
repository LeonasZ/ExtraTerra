#pragma once
#include <sstream>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "PowerUp.h"	
class Game
{
private:
	//window
	sf::RenderWindow* window; //lo hago puntero para que sea dinamico

	//resources
	std::map <std::string, sf::Texture*> textures;  //c++ constructor, que para cada string hay una textura
	std::vector <Bullet*> bullets;


	//Sounds
	sf::SoundBuffer bulletBuffer, chargeBuffer, healthBuffer, alarmBuffer, detectedBuffer, hornBuffer;
	sf::Sound bulletSound, chargeSound, healthSound, alarmSound, detectedSound, hornSound;

	//GUI
	sf::Font font;
	sf::Text pointsText;

	sf::Text gameOverText;
	sf::Text returnMenu;
	bool endGame;

	//world background
	sf::Sprite worldBackground;
	sf::Texture worldBackgroundText;

	//Sytems
	unsigned point;

	//player
	Player *playerShip;

	//Player GUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	//Enemy
	float spawnTimer;
	float spawnTimerMax;
	std::vector <Enemy*> enemies;

	//PowerUp
	float spawnTimerPowerUp;
	float spawnTimerPowerUpMax;
	std::vector <PowerUp*> powerUps;
	
	//functions
	void initWindow();
	void initTextures();
	void initSounds();
	void initWorldBackground();
	void initGUI();
	void initSystems();
	void initPlayer();
	void initEnemies();
	void initPowerUp();

public:

	//constructor & destructor
	Game(sf::RenderWindow &_window);
	virtual ~Game();
	//accesors
	const bool isRunning() const;
	//functions
	void updatePollEvents();
	void updateInput(); //player,etc
	void updateBullet();
	void updateEnemies();
	void updatePowerUp();
	void updateCombat();
	void updateGUI();
	void updateWorldBackground();
	void updateCollision();
	bool run();
	void update();
	void drawGUI();
	void drawWorldBackground();

	void draw();

};

