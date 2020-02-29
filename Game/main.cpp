#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char** argv) {
	//sf::Window window(sf::VideoMode(800, 600),"my window");
	//while (true);
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	
	window.setFramerateLimit(60);

	//sf::CircleShape shape(20.f);
	//shape.setFillColor(sf::Color::Green);
	sf::Texture textureChar;
	sf::Texture textureBack;
	if (!textureChar.loadFromFile("sprites\\1.png")) {
		std::cout << "sprite error";
	}
	if (!textureBack.loadFromFile("sprites\\back.jpg")) {
		std::cout << "sprite error";
	}


	sf::Sprite spriteChar(textureChar);
	sf::Sprite spriteBack(textureBack);
	sf::Sprite spriteBack2(textureBack);

	spriteChar.setOrigin(textureChar.getSize().x / 2, textureChar.getSize().y / 2);
	spriteChar.setScale(0.5f, 0.5f);
	spriteBack2.setPosition(1280, 0);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
				case sf::Keyboard::Key::Left:
					spriteChar.move(-10, 0);
					break;
				case sf::Keyboard::Key::Right:
					spriteChar.move(10, 0);
					break;
				case sf::Keyboard::Key::Up:
					spriteChar.move(0, -10);
					break;
				case sf::Keyboard::Key::Down:
					spriteChar.move(0, 10);
					break;
				}
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				spriteChar.setPosition(event.mouseButton.x, event.mouseButton.y);
			}

		}
		spriteBack.move(-1.f, 0.f);

		window.clear();

		window.draw(spriteBack);

		
		spriteBack2.move(-1.f, 0.f);
		window.draw(spriteBack2);

		window.draw(spriteChar);

		window.display();
	}

	return 0;
}