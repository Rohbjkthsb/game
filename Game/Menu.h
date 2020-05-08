#pragma once
#include "Game.h"
#include "Button.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Menu
{
public:
	Menu(size_t windowWidth, size_t windowHeight);
	~Menu();
	void Run();

private:
	Game* game;

	void draw();
	void processEvents();

	sf::RenderWindow* window;
	size_t windowHeight;
	size_t windowWidth;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Music music;
	sf::Image icon;

	Button* StartGameBtn;
	Button* AudioBtn;
	Button* ScoreBtn;
	Button* ConfigBtn;
	Button* QuitBtn;


	bool exit;
};
