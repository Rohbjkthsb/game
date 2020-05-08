#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Dino.h"
#include "Hurdle.h"
#include "Cloud.h"
#include "Button.h"

class Game
{
public:
	Game(sf::RenderWindow * window, size_t windowWidth, size_t windowHeight);
	~Game();
	void Run();

private:
	sf::RenderWindow* window;
	sf::Image icon;
	sf::Texture groundTexture;
	sf::Sprite groundSprite;
	sf::Sprite _groundSprite;
	sf::Clock clock;
	sf::Text pointsScoring;
	sf::Font font;

	Button* retryBtn;
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
	int points;
	int randCloud;

	float hurdleTimer;
	int randHurdle;
};
