#include "Game.h"

Game::Game(sf::RenderWindow * _window, size_t _width, size_t _height)
{
	window = _window;
	windowWidth = _width;
	windowHeight = _height;
	window->create(sf::VideoMode(static_cast<int>(windowWidth), static_cast<int>(windowHeight)), "Dyno Chrome", sf::Style::Close);
	icon.loadFromFile("Sprites/Dino/Dino_Stand.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window->setFramerateLimit(60);

	groundTexture.loadFromFile("Sprites/Dino/ground.png");
	groundTexture.setSmooth(true);
	groundSprite.setTexture(groundTexture);
	groundSprite.setPosition(0,450);
	_groundSprite = groundSprite;
	_groundSprite.setPosition(1200, 450);
	frames = 0;
}

void Game::draw()
{
	window->clear(sf::Color::White);
	window->draw(groundSprite);
	window->draw(_groundSprite);
	dino->draw(window);
	hurdle->draw(window);
	window->display();

	if (groundSprite.getPosition().x < -1199) 
		groundSprite.setPosition(1200, 450);
	if (_groundSprite.getPosition().x < -1199)
		_groundSprite.setPosition(1200, 450);

	if (dino->checkDinoCenter()) {
		groundSprite.move(-4.f, 0.f);
		_groundSprite.move(-4.f, 0.f);
	}
}

void Game::update()
{
	dino->Jump();
	dino->update();
	hurdle->update(frames);
	frames = ((frames + 1) % 60) + 1;
}

void Game::Run()
{
	exit = false;
	dino = new Dino();
	hurdle = new Hurdle();

	while (!exit)
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				exit = true;
				break;
			}
		}

		draw();
		update();
	}
}

Game::~Game(){}