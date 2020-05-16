#include "Menu.h"

Menu::Menu(sf::RenderWindow * window, size_t windowWidth, size_t windowHeight)
{
	this->window = window;
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	window->create(sf::VideoMode(static_cast<int>(windowWidth), static_cast<int>(windowHeight)), "Dino Chrome", sf::Style::Close);
	window->setFramerateLimit(60);
	icon.loadFromFile("Sprites/Game/Dino_Stand.PNG");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	backgroundTexture.loadFromFile("Sprites/Game/ground.PNG");
	backgroundTexture.setSmooth(true);
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(0, 500);

	StartGameBtn = new Button(sf::Vector2f(window->getSize().x / 2 - 231, window->getSize().y / 2 - 74), sf::Vector2i(462, 74), "Sprites/Menu/Play_Button.PNG", "Sprites/Menu/Play_Button.PNG");
	AudioBtn = new Button(sf::Vector2f(window->getSize().x - 150, window->getSize().y - 150), sf::Vector2i(150, 150), "Sprites/Menu/Audio_Button_Off.PNG", "Sprites/Menu/Audio_Button_On.PNG");
	QuitBtn = new Button(sf::Vector2f(0, window->getSize().y - 150), sf::Vector2i(150, 150), "Sprites/Menu/Exit_Button_Press.PNG", "Sprites/Menu/Exit_Button.PNG");

	dinoTexture.loadFromFile("Sprites/Game/Dino_Stand.PNG");  
	dinoTextureRunR.loadFromFile("Sprites/Game/Dino_Run_R.PNG");
	dinoTextureRunL.loadFromFile("Sprites/Game/Dino_Run_L.PNG");
	dinoTexture.setSmooth(true);
	dinoTextureRunR.setSmooth(true);
	dinoTextureRunL.setSmooth(true);
	dinoSprite.setTexture(dinoTexture);
	dinoSprite.setPosition(sf::Vector2f(0, 457));

	font.loadFromFile("Fonts/Dino.TTF");
	gameName.setFont(font);
	gameName.setString("Dino Chrome");
	gameName.setCharacterSize(90);
	gameName.setFillColor(sf::Color::Black);
	gameName.setPosition(150, 100);
	
	music.openFromFile("Music/menu.wav");
	music.play();
	music.setLoop(true);
	music.setVolume(60);	
}

void Menu::draw()
{
	window->clear(sf::Color::White);
	window->draw(backgroundSprite);
	window->draw(dinoSprite);
	window->draw(*StartGameBtn->GetSpritePointer());
	window->draw(*AudioBtn->GetSpritePointer());
	window->draw(*QuitBtn->GetSpritePointer());
	window->draw(gameName);
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
			QuitBtn->Update(sf::Mouse::getPosition(*window), true);

		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
		{
			if (StartGameBtn->GetSpritePointer()->getGlobalBounds().contains(mouse))
			{
				game = new Game(window, windowWidth, windowHeight);
				music.stop();
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
		FakeDino();
		draw();
		processEvents();
	}
}

void Menu::FakeDino()
{
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	time = time / 16000;

	dinoSprite.move(4.f * time, 0);

	if (dinoSprite.getPosition().x > 1280)
		dinoSprite.setPosition(0, 457);

	stepCount += 1 * time;
	if (stepCount < 8)
		dinoSprite.setTexture(dinoTextureRunR);
	else
		dinoSprite.setTexture(dinoTextureRunL);
	if (stepCount > 16)
		stepCount = 0;
}

Menu::~Menu(){}