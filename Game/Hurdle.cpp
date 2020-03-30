#include "Hurdle.h"

Hurdle::Hurdle()
{
	position = sf::Vector2f(1280, 603);

	hurdleTexture.loadFromFile("Sprites/Hurdle1.png");
	hurdleTexture.setSmooth(true);
	hurdleSprite.setTexture(hurdleTexture);
	hurdleSprite.setPosition(position);
	srand(time(NULL));
	enemy_on_screen = false;
}

void Hurdle::draw(sf::RenderWindow *window)
{
	window->draw(hurdleSprite);
}

void Hurdle::update(int frames)
{
	int k = rand() % 4;

	if (frames % 6 == 0 && !enemy_on_screen)
	{
		switch (k)
		{
		case 0:
			
			break;

		case 1:
		
			break;

		case 2:
			
			break;

		case 3:
			
			break;
		}
		enemy_on_screen = true;
	}

	hurdleSprite.setTextureRect(rect);

	if (enemy_on_screen)
	{
		position.x = position.x - 20;
		hurdleSprite.setPosition(position);

		if (position.x <= -50)
		{
			enemy_on_screen = false;
			hurdleSprite.setPosition(1280, 603
			);
		}
	}
	position = sf::Vector2f(hurdleSprite.getPosition());
}

Hurdle::~Hurdle(){}
