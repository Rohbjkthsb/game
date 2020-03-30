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
	void Jump();
	void update();

private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f gravity;
	sf::Sprite dinoSprite;
	sf::Texture dinoTexture;

	int t;
	
	bool jump = false;
	bool ground = true;
};

