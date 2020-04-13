#include "Hurdle.h"

Hurdle::Hurdle()
{
	k = rand() % 9;

	switch (k)
	{
	case 0:
		hurdleTexture.loadFromFile("Sprites/Game/One_Cactus_Short.PNG");
		position = sf::Vector2f(1280, 417);
		rect = sf::IntRect(0, 0, 15, 33);
		break;
	case 1:
		hurdleTexture.loadFromFile("Sprites/Game/One_Cactus_Long.PNG");
		position = sf::Vector2f(1280, 404);
		rect = sf::IntRect(0, 0, 23, 46);
		break;
	case 2:
		hurdleTexture.loadFromFile("Sprites/Game/Pterodactyl_D.PNG");
		position = sf::Vector2f(1280, 410);
		rect = sf::IntRect(0, 0, 42, 30);
		break;
	case 3:
		hurdleTexture.loadFromFile("Sprites/Game/Three_Cactus_Long.PNG");
		position = sf::Vector2f(1280, 404);
		rect = sf::IntRect(0, 0, 72, 46);
		break;
	case 4:
		hurdleTexture.loadFromFile("Sprites/Game/Four_Cactus.PNG");
		position = sf::Vector2f(1280, 403);
		rect = sf::IntRect(0, 0, 73, 47);
		break;
	case 5:
		hurdleTexture.loadFromFile("Sprites/Game/Three_Cactus_Short.PNG");
		position = sf::Vector2f(1280, 417);
		rect = sf::IntRect(0, 0, 49, 33);
		break;
	case 6:
		hurdleTexture.loadFromFile("Sprites/Game/Two_Cactus_Long.PNG");
		position = sf::Vector2f(1280, 404);
		rect = sf::IntRect(0, 0, 48, 46);
		break;
	case 7:
		hurdleTexture.loadFromFile("Sprites/Game/Three_Cactus_Short.PNG");
		position = sf::Vector2f(1280, 417);
		rect = sf::IntRect(0, 0, 32, 33);
		break;
	case 8:
		hurdleTexture.loadFromFile("Sprites/Game/Pterodactyl_D.PNG");
		position = sf::Vector2f(1280, 380);
		rect = sf::IntRect(0, 0, 42, 30);
		break;
	}

	hurdleSprite.setTexture(hurdleTexture);
	hurdleSprite.setTextureRect(rect);
	hurdleSprite.setPosition(position);
	stepCount = 0;
}

void Hurdle::draw(sf::RenderWindow *window)
{
	window->draw(hurdleSprite);
}

void Hurdle::update(float time)
{
	stepCount += 1 * time;
	if (stepCount > 60)
		stepCount = 0;

	if (k == 2 || k==8)
	{
		if(stepCount>30)
			hurdleTexture.loadFromFile("Sprites/Game/Pterodactyl_U.PNG");
		else
			hurdleTexture.loadFromFile("Sprites/Game/Pterodactyl_D.PNG");
	}



	position.x -= 10 * time;
	hurdleSprite.setPosition(position);
}

sf::IntRect Hurdle::getRect()
{
	return rect;
}

int Hurdle::getX()
{
	return position.x;
}

int Hurdle::getY()
{
	return position.y;
}

int Hurdle::getRectW()
{
	return rect.width;
}

int Hurdle::getRectH()
{
	return rect.height;
}

Hurdle::~Hurdle(){}
