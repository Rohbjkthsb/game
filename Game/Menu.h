#pragma once
#include "Game.h"
#include "Button.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Menu
{
public:
	Menu(sf::RenderWindow * window, size_t windowWidth, size_t windowHeight);
	~Menu();
	void Run();

private:
	Game* game;

	void draw();
	void processEvents();
	void FakeDino();

	sf::RenderWindow* window;
	size_t windowHeight;
	size_t windowWidth;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Music music;
	sf::Image icon;
	sf::Sprite dinoSprite;
	sf::Texture dinoTexture;
	sf::Texture dinoTextureRunL;
	sf::Texture dinoTextureRunR;
	sf::Text gameName;
	sf::Clock clock;
	sf::Font font;

	Button* StartGameBtn;
	Button* AudioBtn;
	Button* QuitBtn;

	float time;
	float stepCount;
	bool exit;
};
