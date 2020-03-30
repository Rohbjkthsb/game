#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "Dino.h"
#include "Hurdle.h"

class Game
{
public:
	
	Game(sf::RenderWindow * _window, size_t _width, size_t _height);
	~Game();
	void Run();

private:
	sf::RenderWindow* window;
	sf::Image icon;
	sf::Texture groundTexture;
	sf::Sprite groundSprite;
	sf::Sprite _groundSprite;

	Dino* dino;
	Hurdle* hurdle;

	void draw();
	void update();

	size_t windowHeight;
	size_t windowWidth;

	bool exit;

	int frames;
};
