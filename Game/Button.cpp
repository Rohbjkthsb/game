#include "Button.h"

Button::Button(sf::Vector2f _position, sf::Vector2i _size, std::string _pressTexture_src, std::string _unpressTexture_src)
{
	position = _position;
	size = _size;

	pressTexture.loadFromFile(_pressTexture_src);
	unpressTexture.loadFromFile(_unpressTexture_src);

	pressSprite.setTexture(pressTexture);
	unpressSprite.setTexture(unpressTexture);

	pressSprite.setScale(sf::Vector2f((float)size.x / (float)pressTexture.getSize().x, (float)size.y / (float)pressTexture.getSize().y));
	unpressSprite.setScale(sf::Vector2f((float)size.x / (float)pressTexture.getSize().x, (float)size.y / (float)pressTexture.getSize().y));

	pressSprite.setPosition(position);
	unpressSprite.setPosition(position);
}

Button::~Button()
{
}

bool Button::Check(sf::Vector2i _mousePosition)
{
	if (_mousePosition.x > position.x && _mousePosition.x < position.x + size.x)
	{
		if (_mousePosition.y > position.y  && _mousePosition.y < position.y + size.y)
		{
			return true;
		}
		else return false;
	}
	else return false;
}

bool Button::getPress()
{
	return press;
}

void Button::Update(sf::Vector2i _mousePosition, bool _buttonPressed)
{
	if (Check(_mousePosition) && _buttonPressed) press = true;
	else press = false;
}

sf::Sprite* Button::GetSpritePointer()
{
	if (press) return &pressSprite;
	else return &unpressSprite;
}