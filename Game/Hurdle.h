#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>

class Hurdle
{
public:
	Hurdle();
	~Hurdle();
	void draw(sf::RenderWindow *window);
	void update(int frames);
private:
	sf::Vector2f position;
	sf::Sprite hurdleSprite;
	sf::Texture hurdleTexture;
	sf::IntRect rect; 

	bool enemy_on_screen;
};