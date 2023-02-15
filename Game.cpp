#include "Game.h"

//Private Functions

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	if (!this->textures["BULLET"]->loadFromFile("Textures/bullet1.png")) {
		std::cout << "GAME::initTextures::Couldnt load bullet texture" << "\n";
	}
	this->textures["ENEMY"] = new sf::Texture();
	if (!this->textures["ENEMY"]->loadFromFile("Textures/enemies1.png")) {
		std::cout << "GAME::initTextures::Couldnt load enemy texture" << "\n";
	}
	this->textures["POWERUP"] = new sf::Texture();
	if (!this->textures["POWERUP"]->loadFromFile("Textures/powerUp1.png")) {
		std::cout << "GAME::initTextures::Couldnt load powerup texture" << "\n";
	}
}

void Game::initSounds()
{
	//SOUNDS
	//laser gun
	if(!this->bulletBuffer.loadFromFile("Sounds/lasergun1.wav")) {
		std::cout << "GAME::InitSounds::Couldnt load lasergun1 sound from file"<< "\n";
	}
	this->bulletSound.setBuffer(this->bulletBuffer);
	this->bulletSound.setVolume(2);

	//attack speed up
	if (!this->chargeBuffer.loadFromFile("Sounds/charge.wav")) {
		std::cout << "GAME::InitSounds::Couldnt load charge sound from file" << "\n";
	}
	this->chargeSound.setBuffer(this->chargeBuffer);
	this->chargeSound.setVolume(20);

	//healing hearth 
	if (!this->healthBuffer.loadFromFile("Sounds/healing.wav")) {
		std::cout << "GAME::InitSounds::Couldnt load heal sound from file" << "\n";
	}
	this->healthSound.setBuffer(this->healthBuffer);
	this->healthSound.setVolume(20);

	//alien alarm
	if (!this->alarmBuffer.loadFromFile("Sounds/alienalarm.wav")) {
		std::cout << "GAME::InitSounds::Couldnt load alarm sound from file" << "\n";
	}
	this->alarmSound.setBuffer(this->alarmBuffer);
	this->alarmSound.setVolume(30);
	this->alarmSound.setPitch(.2);

	//enemy detected
	if (!this->detectedBuffer.loadFromFile("Sounds/enemydetected.wav")) {
		std::cout << "GAME::InitSounds::Couldnt load enemy detected sound from file" << "\n";
	}
	this->detectedSound.setBuffer(this->detectedBuffer);
	this->detectedSound.setVolume(30);
	this->detectedSound.setPitch(.7);
	this->detectedSound.play(); // la reproduzco solo una vez

	//game over horn
	if (!this->hornBuffer.loadFromFile("Sounds/inithorn.wav")) {
		std::cout << "GAME::InitSounds::Couldnt load alarm sound from file" << "\n";
	}
	this->hornSound.setBuffer(this->hornBuffer);
	this->hornSound.setVolume(10);



}

void Game::initWorldBackground()
{
	if (!this->worldBackgroundText.loadFromFile("Textures/galaxy.png")) {
		std::cout << "GAME::InitWorldBackground couldnt load textures" << "\n";
	}
	this->worldBackground.setTexture(worldBackgroundText);
}

void Game::initGUI()
{
	//load font
	this->font.loadFromFile("Fonts/vogue.ttf");
	this->pointsText.setFont(this->font);
	this->gameOverText.setFont(this->font);
	this->returnMenu.setFont(this->font);
	//init font
	//points text
	this->pointsText.setCharacterSize(28);
	this->pointsText.setFillColor(sf::Color::White);
	this->pointsText.setString("test");
	this->pointsText.setPosition(20.f,40.f);

	//game over text
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("Game Over!");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f 
	);
	this->returnMenu.setCharacterSize(35);
	this->returnMenu.setFillColor(sf::Color::Red);
	this->returnMenu.setString("Presione BackSpace para volver al menu...");
	this->returnMenu.setPosition(
		this->window->getSize().x / 2.f - this->returnMenu.getGlobalBounds().width / 2.f,
		550.f
	);


	//init player GUI
	//hp bar
	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}

void Game::initSystems()
{
	this->point = 0;
	this->endGame = false;
	
}

void Game::initPlayer()
{
	this->playerShip = new Player();
}

void Game::initEnemies()
{
	this->spawnTimerMax = 60.f * 5.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Game::initPowerUp()
{
	this->spawnTimerPowerUpMax = 60.f * 10.f;
	this->spawnTimerPowerUp = 0;
}

//constructor
Game::Game(sf::RenderWindow &_window)
{
	this->window = &_window;
	this->initTextures();
	this->initGUI();
	this->initWorldBackground();
	this->initSystems();
	this->initSounds();

	this->initPlayer();
	this->initEnemies();
	this->initPowerUp();
}
//destructor
Game::~Game()
{
	//delete this->window;
	delete this->playerShip;

	//delete textures
	for (auto& i : this->textures) {
		delete i.second;
	}
	//delete bullets
	for (auto* i : this->bullets) {
		delete i;
	}

	//delete enemies
	for (auto* i : this->enemies) {
		delete i;
	}
	for (auto* i : this->powerUps) {
		delete i;
	}
	
}

//accesor
const bool Game::isRunning() const
{
	return this->endGame;
}

//Public Functions
void Game::updateInput()
{
	//move player

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		this->playerShip->move(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		this->playerShip->move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		this->playerShip->move(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		this->playerShip->move(0.f, 1.f);
	}

	//release bullets
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->playerShip->canAttack()) {

		this->bulletSound.play();
		this->bullets.push_back(new Bullet(
			this->textures["BULLET"], //string
			this->playerShip->getPos().x + this->playerShip->getBounds().width / 2.f - 5.f, //bullet x position (-5 its a little correction on the sprite)
			this->playerShip->getPos().y, //bullet y position
			0.f, //direction on x
			-1.f,//direction on y
			5.f //bullet movement speed  
			)
			
		);
		
	}
}


void Game::updateBullet()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets) {
		bullet->update();

	//bullet culling (top of screen)  deletes bullets when arent visible
		if (bullet->getBounds().top + bullet->getBounds().height < 0) {
			//delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
		}

		++counter;

	}
}

void Game::updateEnemies()
{
	//enemies spawner
	this->spawnTimer += 3;
	if (this->spawnTimer >= this->spawnTimerMax) {
		this->spawnTimer = 0.f;
		this->enemies.push_back(new Enemy(this->textures["ENEMY"],rand() % 650 + 60.f, -100.f));
	}
	
	
	//update enemies
	unsigned counter = 0;
	for (auto* enemy : this->enemies) {
		enemy->update();

		//enemies culling (bottom of the screen)  deletes enemies when reaches max window y position
		if (enemy->getBounds().top > this->window->getSize().y) {
			//lose health
			this->playerShip->loseHp(this->enemies.at(counter)->getDamage());
			

			//delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
				
			
		}
		else if (enemy->getBounds().intersects(this->playerShip->getBounds())) {
			//check collision between enemy and player
			//lose health
			this->playerShip->loseHp(this->enemies.at(counter)->getDamage());
			

			//delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}

		++counter;

	}

	// cada 100 puntos conseguidos, disminuimos el respawn max timer para agregar mas dificultad
	if (this->point > 100 && this->point <= 200) {
		this->spawnTimerMax = 60.f * 3.f;
		this->alarmSound.play();
	}
	else if (this->point > 200 && this->point <= 300) {
		this->spawnTimerMax = 60.f * 2.5;
		this->hornSound.play();
	}
	else if (this->point > 300 && this->point <= 400) {
		this->spawnTimerMax = 60.f * 2.f;
	}
	else if (this->point > 400 && this->point <= 500) {
		this->spawnTimerMax = 60.f * 1.5;
	}
	else if (this->point > 500 ) {
		this->spawnTimerMax = 60.f * 0.5;
	}
}



void Game::updatePowerUp()
{
	this->spawnTimerPowerUp += 1;
	if (this->spawnTimerPowerUp >= this->spawnTimerPowerUpMax) {
		this->spawnTimerPowerUp = 0;
		this->powerUps.push_back(new PowerUp(this->textures["POWERUP"], rand() % 700 + 50.f, rand() % 250 + 300.f));
	}

	//colision between player and powerup
	for (size_t i = 0; i < this->powerUps.size(); i++) {
		if (this->powerUps[i]->getBounds().intersects(this->playerShip->getBounds())) {
			
			if (this->powerUps[i]->getType() == 1) {
				this->playerShip->gainHp(this->powerUps[i]->getHpHeal());
				this->healthSound.play();
				if (this->playerShip->getHp() > this->playerShip->getHpMax()) { //heal only if hp is minor than max hp
					this->playerShip->setHp(this->playerShip->getHpMax());
					
				}
			}
			else if (this->powerUps[i]->getType() == 2) {
				this->chargeSound.play();
				if (this->playerShip->getAttackCooldownMax() > 5.f) {
					this->playerShip->reduceAttackCooldown();
					this->bulletSound.setPitch(std::rand()% 2 + .8);

				}
			}


			delete this->powerUps.at(i);
			this->powerUps.erase(this->powerUps.begin() + i);

		}
	}
	

}

void Game::updateCombat()
{
	//collision between enemies and bullets
	for (int i = 0; i < this->enemies.size(); i++) {
		bool enemy_deleted=false;
		for (size_t j = 0; j < this->bullets.size() && !enemy_deleted ; j++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[j]->getBounds())) {
				

				this->enemies.at(i)->loseHp(this->playerShip->getAttackDamage());

				if (this->enemies.at(i)->getHp() <= 0) {
					//gain points
					this->point += this->enemies[i]->getPoints();
					//delete enemy
					delete this->enemies[i];
					this->enemies.erase(this->enemies.begin() + i);
					enemy_deleted = true;
				}
					
				delete this->bullets[j];
				this->bullets.erase(this->bullets.begin() + j);
					
			}
		}
	}
}

void Game::updateGUI()
{
	std::stringstream ss;
	ss << "Points: " << this->point << "\n";

	this->pointsText.setString(ss.str());

	//update player hp bar
	
	float hpPercent;
	hpPercent = (static_cast<float>(this->playerShip->getHp()) / this->playerShip->getHpMax());

	this->playerHpBar.setSize(sf::Vector2f(300.f *  hpPercent, this->playerHpBar.getSize().y));

	if (this->playerShip->getHp() <= 0) {
		this->endGame = true;
	}


}

void Game::updateWorldBackground()
{
	if (this->endGame) {
		this->worldBackground.setColor(sf::Color(255, 255, 255, 100));
	}
}


void Game::updateCollision()
{	
	//update collision relative to the window screen sides
	//left side
	if (this->playerShip->getBounds().left < 0.f) {
		this->playerShip->setPosition(0.f, this->playerShip->getBounds().top);
	}
	//right side
	else if (this->playerShip->getBounds().left + this->playerShip->getBounds().width > this->window->getSize().x) {
		this->playerShip->setPosition(this->window->getSize().x - this->playerShip->getBounds().width, this->playerShip->getBounds().top);
	}
	//top
	if (this->playerShip->getBounds().top < 0.f) {
		this->playerShip->setPosition( this->playerShip->getBounds().left,0.f);
	}
	//bottom
	else if (this->playerShip->getBounds().top + this->playerShip->getBounds().height > this->window->getSize().y) {
		this->playerShip->setPosition(this->playerShip->getBounds().left, this->window->getSize().y - this->playerShip->getBounds().height);
	}
}

bool Game::run()
{

	while (!this->endGame)
	{

		this->updatePollEvents();
		if (!endGame)
			this->update();
		this->draw();

	}

	return true;
}
void Game::updatePollEvents()
{
	sf::Event ev;


	while (this->window->pollEvent(ev)) {
		if (ev.Event::type == sf::Event::Closed) {
			this->window->close();
		}
		
	}
}


void Game::update()
{

	this->updateInput();

	this->playerShip->update();

	this->updateCollision();

	this->updateBullet();

	this->updateEnemies();

	this->updatePowerUp();

	this->updateCombat();

	this->updateGUI();
	
	this->updateWorldBackground();

}
void Game::drawGUI()
{
	this->window->draw(this->pointsText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);

}
void Game::drawWorldBackground()
{
	this->window->draw(this->worldBackground);
}
void Game::draw()
{
	this->window->clear();

	//Draw world background
	this->drawWorldBackground();

	//Draws all the stuff
	this->playerShip->draw(*this->window);

	for (auto* bullet : this->bullets) {
		bullet->draw(*this->window);
	}

	for (auto* enemy : this->enemies) {
		enemy->draw(*this->window);
	}

	for (auto* powerup : this->powerUps) {
		powerup->draw(*this->window);
	}



	//draw gui
	this->drawGUI();

	//Game over screen
	//espera a que el usuario presione enter para volver al menu anterior

	if (endGame) {
		this->window->draw(this->gameOverText);
		this->window->draw(this->returnMenu);
	}

	this->window->display();

}


