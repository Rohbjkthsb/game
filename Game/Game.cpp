#include "Game.h"

Game::Game(sf::RenderWindow * window, size_t windowWidth, size_t windowHeight)
{
	this->window = window;
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
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

	font.loadFromFile("Fonts/Dino.ttf");
	pointsScoring.setFont(font);
	points = 0;
	pointsScoring.setString(std::to_string(points));
	pointsScoring.setCharacterSize(16);
	pointsScoring.setFillColor(sf::Color::Black);
	pointsScoring.setPosition(10, 10);

	cloudTimer = 0;
	randCloud = 0;
	
	hurdleTimer = 0;
	randHurdle = 0;
}

void Game::draw()
{
	window->display();
	window->clear(sf::Color::White);

	window->draw(groundSprite);
	window->draw(_groundSprite);
	window->draw(pointsScoring);

	dino->draw(window);

	for (size_t i = 0; i < clouds.size(); i++) {
		clouds[i]->draw(window);
	}

	for (size_t i = 0; i < hurdles.size(); i++) {
		hurdles[i]->draw(window);
	}

	if (!gameOver)
	{
		if (groundSprite.getPosition().x < -1270)
			groundSprite.setPosition(1280, 450);
		if (_groundSprite.getPosition().x < -1270)
			_groundSprite.setPosition(1280, 450);
		if (dino->checkDinoCenter()) {
			groundSprite.move(-10.f * time, 0.f);
			_groundSprite.move(-10.f * time, 0.f);
		}
	}
}

void Game::update()
{
	dino->control(time);
	dino->update(time);

	updateClouds();
	updateHurdles();

	points += 50 * time;
	pointsScoring.setString(std::to_string(points));

	checkLose();
}

void Game::Run()
{
	exit = false;
	gameOver = false;
	dino = new Dino();
	sf::Vector2f mouse = sf::Vector2f(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);

	while (!exit)
	{
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 16000;

		if (!gameOver)
			update();
		else 
		{
			retryBtn = new Button(sf::Vector2f(window->getSize().x / 2 - 75, window->getSize().y / 2 - 75), sf::Vector2i(150, 150), "Sprites/Game/Return_Button.PNG", "Sprites/Game/Return_Button.PNG");
			window->draw(*retryBtn->GetSpritePointer());
		}

		draw();

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				exit = true;
				break;
			}
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				if (retryBtn->GetSpritePointer()->getGlobalBounds().contains(mouse))
				{
					dino->reDino();
					hurdles.clear();
					clouds.clear();
					delete retryBtn;
					points = 0;
					gameOver = false;
				}
			}
		}
	}
}


void Game::updateClouds()
{
	cloudTimer += 1 * time;

	for (size_t i = 0; i < clouds.size(); i++) {
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

	for (size_t i = 0; i < hurdles.size(); i++)
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
	for (size_t i = 0; i < hurdles.size(); i++)
	{
		bool lose = checkCollision(dino->getX(), dino->getY(), dino->getRectW(), dino->getRectH(), hurdles[i]->getX(), hurdles[i]->getY(), hurdles[i]->getRectW(), hurdles[i]->getRectH());
		if (lose)
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
	for (size_t i = 0; i < hurdles.size(); i++) {
		delete hurdles[i];
	}
	for (size_t i = 0; i < clouds.size(); i++) {
		delete clouds[i];
	}
}

