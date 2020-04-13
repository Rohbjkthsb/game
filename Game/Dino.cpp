#include "Dino.h"

Dino::Dino()
{
	velocity = sf::Vector2f(2, 0);
	gravity = sf::Vector2f(0, 2.2);
	position = sf::Vector2f(0, 407);
	rect = sf::IntRect(0, 0, 40, 43);

	dinoTexture.loadFromFile("Sprites/Game/Dino_Stand.PNG");  textures.push_back(dinoTexture);
	dinoTexture.setSmooth(true);
	dinoSprite.setTexture(dinoTexture);
	dinoSprite.setTextureRect(rect);
	dinoSprite.setPosition(position);

	dino_Run_R.loadFromFile("Sprites/Game/Dino_Run_R.PNG"); textures.push_back(dino_Run_R);
	dino_Run_L.loadFromFile("Sprites/Game/Dino_Run_L.PNG"); textures.push_back(dino_Run_L);
	dino_RunDown_R.loadFromFile("Sprites/Game/Dino_RunDown_R.PNG"); textures.push_back(dino_RunDown_R);
	dino_RunDown_L.loadFromFile("Sprites/Game/Dino_RunDown_L.PNG"); textures.push_back(dino_RunDown_L);

	stepCount = 0;
}

void Dino::draw(sf::RenderWindow *window)
{
	window->draw(dinoSprite);
}

bool Dino::checkDinoCenter()
{
	if (position.x > 100) 
		velocity.x = 0;
	else
		return false;
	return true;
}

void Dino::control(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ground && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		dinoSprite.setTexture(textures[0]);
		velocity.y = -25;
		ground = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && ground)
	{
		if (stepCount < 8)
			dinoSprite.setTexture(textures[3]);
		else
			dinoSprite.setTexture(textures[4]);
		position.y = 424;
		rect = sf::IntRect(0, 0, 55, 26);
	}

	else if (ground)
	{
		if (stepCount < 8)
			dinoSprite.setTexture(textures[1]);
		else
			dinoSprite.setTexture(textures[2]);
		position.y = 407;
		rect = sf::IntRect(0, 0, 40, 43);
	}
}

void Dino::update(float time)
{
	stepCount += 1 * time;
	if (stepCount > 16)
		stepCount = 0;

	position += velocity * time;

	if (!ground)
	{
		velocity += gravity * time;
		if (position.y >= 408)
		{
			position.y = 407;
			ground = true;
			velocity.y = 0;
			stepCount = 0;
		}
	}

	dinoSprite.setPosition(position);
	dinoSprite.setTextureRect(rect);

	if (ground)
		velocity = sf::Vector2f(velocity.x, 0);
}

void Dino::reDino()
{
	position.x = 0;
	velocity.x = 2;
}

int Dino::getX()
{
	return position.x;
}

int Dino::getY()
{
	return position.y;
}

int Dino::getRectW()
{
	return rect.width;
}

int Dino::getRectH()
{
	return rect.height;
}

Dino::~Dino() {}