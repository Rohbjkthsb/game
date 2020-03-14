#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Player
{
public:
	Player();
	~Player();
	void Jump();
	sf::Sprite playerSprite;

private:
	int Speed;
	
	sf::Texture playerTexture;
	
};

