#include "Game.h"

Game::Game(sf::RenderWindow * _window, size_t _width, size_t _height)
{
	window = _window;
	windowWidth = _width;
	windowHeight = _height;
	window->create(sf::VideoMode(static_cast<int>(windowWidth), static_cast<int>(windowHeight)), "Dino Chrome", sf::Style::Close);
	icon.loadFromFile("Sprites/Game/Dino_Stand.PNG");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window->setFramerateLimit(200);

	groundTexture.loadFromFile("Sprites/Game/ground.PNG");
	groundTexture.setSmooth(true);
	groundSprite.setTexture(groundTexture);
	_groundSprite = groundSprite;
	groundSprite.setPosition(0,450);
	_groundSprite.setPosition(1280, 450);

	cloudTimer = 0;
	randCloud = 0;

	hurdleTimer = 0;
	randHurdle = 0;
}

void Game::draw()
{
	window->clear(sf::Color::White);
	window->draw(groundSprite);
	window->draw(_groundSprite);
	dino->draw(window);

	for (int i = 0; i < clouds.size(); i++) {
		clouds[i]->draw(window);
	}

	for (int i = 0; i < hurdles.size(); i++) {
		hurdles[i]->draw(window);
	}

	if (groundSprite.getPosition().x < -1270)
		groundSprite.setPosition(1280, 450);
	if (_groundSprite.getPosition().x < -1270)
		_groundSprite.setPosition(1280, 450);

	if (dino->checkDinoCenter()) {
		groundSprite.move(-10.f * time, 0.f);
		_groundSprite.move(-10.f * time, 0.f);
	}

	window->display();
}

void Game::update()
{
	if (!gameOver)
	{
		dino->control(time);
		dino->update(time);
		checkLose();
		updateClouds();
		updateHurdles();
	}
}

void Game::Run()
{
	exit = false;
	gameOver = false;
	dino = new Dino();


	while (!exit)
	{
		time = clock.getElapsedTime().asMicroseconds(); 
		clock.restart(); 
		time = time / 16000;

		if (gameOver)
		{
			dino->reDino();
			hurdles.clear();
			clouds.clear();

			gameOver = false;
		}

		draw();
		update();

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				exit = true;
				break;
			}
		}
	}
}









void Game::updateClouds()
{
	cloudTimer += 1 * time;

	for (int i = 0; i < clouds.size(); i++) {
		clouds[i]->update(time);
		if (clouds[i]->getX() < -100) {
			delete clouds[i];
			clouds.erase(clouds.begin() + i);
		}
	}

	if (randCloud + 300 < cloudTimer) {
		addCloud();
	}
}

void Game::addCloud() 
{
	Cloud* cloud = new Cloud();
	clouds.push_back(cloud);
	randCloud = rand() % 75;
	cloudTimer = 0;
}

void Game::updateHurdles()
{
	hurdleTimer += 1 * time;

	for (int i = 0; i < hurdles.size(); i++) 
	{
		hurdles[i]->update(time);
		if (hurdles[i]->getX() < -100) {
			delete hurdles[i];
			hurdles.erase(hurdles.begin() + i);
		}
	}

	if (randHurdle + 50 < hurdleTimer) 
	{
		addHurdle();
	}
}

void Game::addHurdle () 
{
	Hurdle *hurdle = new Hurdle();
	hurdles.push_back(hurdle);
	randHurdle = rand() % 75;
	hurdleTimer = 0;
}

void Game::checkLose()
{
	for (int i = 0; i < hurdles.size(); i++)
	{
		if (checkCollision(dino->getX(), dino->getY(), dino->getRectW(), dino->getRectH(), hurdles[i]->getX(), hurdles[i]->getY(), hurdles[i]->getRectW(), hurdles[i]->getRectH()))
			gameOver = true;
	}
}

bool Game::checkCollision(int dx, int dy, int dw, int dh, int hx, int hy, int hw, int hh) 
{
	int xMin = dx;
	int xMax = dx + dw;
	int yMax = dy + dh;
	int yMin = dy;

	int _xMin = hx;
	int _xMax = hx + hw;
	int _yMax = hy + hh;
	int _yMin = hy;

	if (xMax < _xMin || xMin > _xMax) {
		return false;
	}
	if (yMax < _yMin || yMin > _yMax) {
		return false;
	}

	return true;
}

Game::~Game()
{
	delete dino;
	for (int i = 0; i < hurdles.size(); i++) {
		delete hurdles[i];
	}
	for (int i = 0; i < clouds.size(); i++) {
		delete clouds[i];
	}
}