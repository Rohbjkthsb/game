#include "Game.h"

Game::Game(sf::RenderWindow * _window, size_t _width, size_t _height)
{

	window = _window;
	windowWidth = _width;
	windowHeight = _height;
	window->create(sf::VideoMode(static_cast<int>(windowWidth), static_cast<int>(windowHeight)), "SFML", sf::Style::Close);
	window->setFramerateLimit(60);


	backgroundTexture.loadFromFile("Sprites/back.jpg");
	backgroundTexture.setSmooth(true);
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(sf::Vector2f(window->getSize().x / 1080, window->getSize().y / 1365));
	backgroundSprite.setScale(sf::Vector2f((float)window->getSize().x / (float)backgroundTexture.getSize().x, (float)window->getSize().y / (float)backgroundTexture.getSize().y));

	backgroundTexture2.loadFromFile("Sprites/back.jpg");
	backgroundTexture2.setSmooth(true);
	backgroundSprite2.setTexture(backgroundTexture2);
	backgroundSprite2.setScale(sf::Vector2f(window->getSize().x / 1080, window->getSize().y / 1365));
	backgroundSprite2.setScale(sf::Vector2f((float)window->getSize().x / (float)backgroundTexture2.getSize().x, (float)window->getSize().y / (float)backgroundTexture2.getSize().y));
	backgroundSprite2.setPosition(1280, 0);

	music.openFromFile("Music/menu.wav");
	music.play();
	music.setLoop(true);
	music.setVolume(60);

	
}

void Game::processEvents()
{


	sf::Event event;
	sf::Vector2f mouse = sf::Vector2f(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			exit = true;
			break;
		}
		
	}
}

void Game::draw()
{
	bool dynoCenter = true;


	window->clear(sf::Color::White);

	window->draw(backgroundSprite);
	if (backgroundSprite.getPosition().x < -1279) {
		backgroundSprite.setPosition(1280, 0);
	}
	if (dynoCenter == true) {
		backgroundSprite.move(-4.f, 0.f);
	}

	window->draw(backgroundSprite2);
	if (backgroundSprite2.getPosition().x < -1279) {
		backgroundSprite2.setPosition(1280, 0);
	}
	if (dynoCenter == true) {
		backgroundSprite2.move(-4.f, 0.f);
	}

	window->draw(player->playerSprite);
	
	window->display();
}

void Game::Run()
{
	

	exit = false;
	player = new Player();
	world = new World();

	while (!exit)
	{
		draw();
		processEvents();
	}
}