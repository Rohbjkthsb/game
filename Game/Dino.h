#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Dino
{
public:
	Dino();
	~Dino();
	void draw(sf::RenderWindow *window);
	bool checkDinoCenter();
	void control(float time);
	void update(float time);
	void reDino();
	int getX();
	int getY();
	int getRectW();
	int getRectH();

private:
	std::vector<sf::Texture> textures;

	sf::Texture dinoStand;
	sf::Texture dino_Run_R;
	sf::Texture dino_Run_L;
	sf::Texture dino_RunDown_R;
	sf::Texture dino_RunDown_L;

	sf::Clock clock;

	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f gravity;

	sf::Sprite dinoSprite;
	sf::Texture dinoTexture;
	sf::IntRect rect;

	float stepCount;

	bool ground = true;
};

