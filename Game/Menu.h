#pragma once
#include "Button.h"
#include "Game.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Menu
{
public:
	Menu(size_t width, size_t height);
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

	Button* StartGameBtn;
	Button* AudioBtn;
	Button* ScoreBtn;
	Button* ConfigBtn;
	Button* QuitBtn;


	sf::Image icon;

	bool exit;
};
