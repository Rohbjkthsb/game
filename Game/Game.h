#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "Player.h"

class Game
{
public:
	
	Game(sf::RenderWindow * _window, size_t _width, size_t _height);
	~Game();
	void Run();


private:
	Player* player;
	

	void draw();
	void processEvents();

	sf::RenderWindow* window;
	size_t windowHeight;
	size_t windowWidth;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Music music;

	bool exit;
};
