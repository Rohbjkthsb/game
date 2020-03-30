#include "Dino.h"

Dino::Dino()
{
	velocity = sf::Vector2f(2, 0);
	gravity = sf::Vector2f(0, 2);
	position = sf::Vector2f(0, 410);

	dinoTexture.loadFromFile("Sprites/Dino/Dino1.png");
	dinoTexture.setSmooth(true);
	dinoSprite.setTexture(dinoTexture);
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

void Dino::Jump()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ground)
	{
		velocity.y = -32;
		jump = true;
		ground = false;
	}
}

void Dino::update()
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

	dinoSprite.setPosition(position);

	if (ground)
		velocity = sf::Vector2f(velocity.x, 0);
}

Dino::~Dino() {}