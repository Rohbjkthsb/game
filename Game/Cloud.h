#pragma once
#include <SFML/Graphics.hpp>

class Cloud
{
public:
	Cloud();
	~Cloud();
	void update(float time);
	void draw(sf::RenderWindow *window);
	int getX();

private:
	sf::Texture cloudTexture;
	sf::Sprite cloudSprite;
	sf::Vector2f position;
};