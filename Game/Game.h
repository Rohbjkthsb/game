#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Dino.h"
#include "Hurdle.h"
#include "Cloud.h"

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
	sf::Clock clock;

	Dino* dino;
	std::vector<Cloud*> clouds;
	std::vector<Hurdle*> hurdles;

	void draw();
	void update();
	void updateClouds();
	void addCloud();
	void updateHurdles();
	void addHurdle();
	void checkLose();
	bool checkCollision(int dx, int dy, int dw, int dh, int hx, int hy, int hw, int hh);

	size_t windowHeight;
	size_t windowWidth;

	bool exit;
	bool gameOver;

	float time;
	float cloudTimer;
	int randCloud; 

	float hurdleTimer;
	int randHurdle;
};
