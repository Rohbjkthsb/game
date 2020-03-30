#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button
{
public:
	Button(sf::Vector2f _position, sf::Vector2i _size, std::string _pressTexture_src, std::string _unpressTexture_src);
	~Button();

	bool Check(sf::Vector2i mousePosition);
	bool getPress();
	void Update(sf::Vector2i mousePosition, bool buttonPressed);

	sf::Sprite* GetSpritePointer();

	sf::Vector2f position;
	sf::Vector2i size;

private:

	sf::Texture pressTexture;
	sf::Texture unpressTexture;

	sf::Sprite pressSprite;
	sf::Sprite unpressSprite;

	sf::Font font;

	bool press = false;
};

