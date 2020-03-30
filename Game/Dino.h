#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Dino
{
public:
	Dino();
	~Dino();
	void draw(sf::RenderWindow *window);
	bool checkDinoCenter();
	void Control(int frames);
	void update(int frames);

private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f gravity;
	sf::Sprite dinoSprite;
	sf::Texture dinoTexture;
	sf::IntRect rect;

	bool jump = false;
	bool ground = true;
};

