#include "Dino.h"

Dino::Dino()
{
	velocity = sf::Vector2f(2, 0);
	gravity = sf::Vector2f(0, 2);
	position = sf::Vector2f(0, 407);
	rect = sf::IntRect(0, 0, 40, 43);

	dinoTexture.loadFromFile("Sprites/Game/Dino_Stand.png");
	dinoTexture.setSmooth(true);
	dinoSprite.setTexture(dinoTexture);
	dinoSprite.setTextureRect(rect);
	dinoSprite.setPosition(position);

}

void Dino::draw(sf::RenderWindow *window)
{
	window->draw(dinoSprite);
}

bool Dino::checkDinoCenter()
{
	if (position.x > 100) {
		velocity.x = 0;
		return true;
	}
	else
		return false;
}

void Dino::Control(int frames)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ground)
	{
		velocity.y = -25;
		jump = true;
		ground = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && ground)
	{
		if ((frames / 15) % 2 == 0)
			dinoTexture.loadFromFile("Sprites/Game/Dino_RunDown_R.png");
		else if ((frames / 15) % 2 == 1)
			dinoTexture.loadFromFile("Sprites/Game/Dino_RunDown_L.png");
		rect = sf::IntRect(0, 0, 55, 26);
		position.y = 424;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S) && ground)
	{
		if ((frames / 15) % 2 == 0)
			dinoTexture.loadFromFile("Sprites/Game/Dino_Run_R.png");
		else if ((frames / 15) % 2 == 1)
			dinoTexture.loadFromFile("Sprites/Game/Dino_Run_L.png");
		rect = sf::IntRect(0, 0, 40, 43);
		position.y = 407;
	}
}

void Dino::update(int frames)
{
	position += velocity;
	if (!ground)
	{
		velocity += gravity;
		if (position.y >= 410)
		{
			position.y = 410;
			ground = true;
			jump = false;
			velocity.y = 0;
		}
	}

	dinoSprite.setTextureRect(rect);
	dinoSprite.setPosition(position);

	if (ground) {
		velocity = sf::Vector2f(velocity.x, 0);
	}
}

Dino::~Dino() {}