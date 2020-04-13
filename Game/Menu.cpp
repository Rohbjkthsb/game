#include "Menu.h"

Menu::Menu(size_t _width, size_t _height)
{
	window = new sf::RenderWindow();
	windowWidth = _width;
	windowHeight = _height;
	window->create(sf::VideoMode(static_cast<int>(windowWidth), static_cast<int>(windowHeight)), "Dino Chrome", sf::Style::Close);
	window->setFramerateLimit(60);
	icon.loadFromFile("Sprites/Game/Dino_Stand.PNG");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	backgroundTexture.loadFromFile("Sprites/Menu/back.PNG");
	backgroundTexture.setSmooth(true);
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(sf::Vector2f(window->getSize().x / 1080, window->getSize().y / 1365));
	backgroundSprite.setScale(sf::Vector2f((float)window->getSize().x / (float)backgroundTexture.getSize().x, (float)window->getSize().y / (float)backgroundTexture.getSize().y));

	StartGameBtn = new Button(sf::Vector2f(window->getSize().x / 2 - 75, window->getSize().y / 2 - 75), sf::Vector2i(150, 150), "Sprites/Menu/Press_Play_Button.PNG", "Sprites/Menu/Play_Button.PNG");
	AudioBtn = new Button(sf::Vector2f(window->getSize().x - 150, window->getSize().y-150), sf::Vector2i(150, 150), "Sprites/Menu/Audio_Off_Button.PNG", "Sprites/Menu/Audio_On_Button.PNG");
	ScoreBtn = new Button(sf::Vector2f(150, 0), sf::Vector2i(150, 150), "Sprites/Menu/Press_Score_Button.PNG", "Sprites/Menu/Score_Button.PNG");
	ConfigBtn = new Button(sf::Vector2f(0, 0), sf::Vector2i(150, 150), "Sprites/Menu/Press_Config_Button.PNG", "Sprites/Menu/Config_Button.PNG");
	QuitBtn = new Button(sf::Vector2f(0, window->getSize().y - 150), sf::Vector2i(150, 150), "Sprites/Menu/Press_Quit_Button.PNG", "Sprites/Menu/Quit_Button.PNG");
	
	music.openFromFile("Music/menu.wav");
	music.play();
	music.setLoop(true);
	music.setVolume(60);
	
}

void Menu::draw()
{
	window->clear(sf::Color::White);
	window->draw(backgroundSprite);

	window->draw(*StartGameBtn->GetSpritePointer());
	window->draw(*AudioBtn->GetSpritePointer());
	window->draw(*ScoreBtn->GetSpritePointer());
	window->draw(*ConfigBtn->GetSpritePointer());
	window->draw(*QuitBtn->GetSpritePointer());

	window->display();
}

void Menu::processEvents()
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

		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			StartGameBtn->Update(sf::Mouse::getPosition(*window), true);
			ScoreBtn->Update(sf::Mouse::getPosition(*window), true);
			ConfigBtn->Update(sf::Mouse::getPosition(*window), true);
			QuitBtn->Update(sf::Mouse::getPosition(*window), true);
		}

		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
		{
			if (StartGameBtn->GetSpritePointer()->getGlobalBounds().contains(mouse))
			{
				game = new Game(window, windowWidth, windowHeight);
				game->Run();
				exit = true;
				break;
			}

			else if (QuitBtn->GetSpritePointer()->getGlobalBounds().contains(mouse))
			{
				exit = true;
				break;
			}

			else if (AudioBtn->GetSpritePointer()->getGlobalBounds().contains(mouse))
			{
				if (AudioBtn->getPress() == false)
				{
					AudioBtn->Update(sf::Mouse::getPosition(*window), true);
					music.pause();
				}
				else
				{
					AudioBtn->Update(sf::Mouse::getPosition(*window), false);
					music.play();
				}
			}
		}
	}
}

void Menu::Run()
{
	exit = false;
	while (!exit)
	{
		draw();
		processEvents();
	}
}

Menu::~Menu(){}