#include "Cloud.h"

Cloud::Cloud() 
{
	position = sf::Vector2f(1280, rand() % 50 + 300);

	cloudTexture.loadFromFile("Sprites/Game/Cloud.PNG");
	cloudTexture.setSmooth(true);
	cloudSprite.setTexture(cloudTexture);
	cloudSprite.setPosition(position);	
}

void Cloud::update(float time) {
	position.x -= 1 * time;
	cloudSprite.setPosition(position);
}

void Cloud::draw(sf::RenderWindow *window)
{
	window->draw(cloudSprite);
}

int Cloud::getX()
{
	return position.x;
}

Cloud::~Cloud(){}
