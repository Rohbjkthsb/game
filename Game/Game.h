#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "Player.h"
#include "World.h"


class Game
{
public:
	
	Game(sf::RenderWindow * _window, size_t _width, size_t _height);
	~Game();
	void Run();


private:
	Player* player;
	World* world;
	

	void draw();
	void processEvents();

	sf::RenderWindow* window;
	size_t windowHeight;
	size_t windowWidth;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture2;
	sf::Sprite backgroundSprite2;
	sf::Music music;

	bool exit;
};
