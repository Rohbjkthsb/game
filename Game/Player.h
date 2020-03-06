#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Player
{
public:
	Player();
	~Player();
	sf::Sprite playerSprite;

private:
	

	sf::Texture playerTexture;
	
};

