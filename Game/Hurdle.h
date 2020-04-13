#pragma once
#include <SFML/Graphics.hpp>

class Hurdle
{
public:
	Hurdle();
	~Hurdle();
	void draw(sf::RenderWindow *window);
	void update(float time);
	sf::IntRect getRect();
	int getX();
	int getY();
	int getRectW();
	int getRectH();

private:
	std::vector<sf::Texture> textures;

	int k;
	float stepCount;

	sf::IntRect rect;
	sf::Vector2f position;
	sf::Sprite hurdleSprite;
	sf::Texture hurdleTexture;
};