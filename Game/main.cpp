#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char** argv) {
	//sf::Window window(sf::VideoMode(800, 600),"my window");
	//while (true);
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
	
	window.setFramerateLimit(60);

	//sf::CircleShape shape(20.f);
	//shape.setFillColor(sf::Color::Green);
	sf::Texture texture;
	if (!texture.loadFromFile("sprites\\1.png")) {
		std::cout << "sprite error";
	}


	sf::Sprite sprite(texture);

	sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	sprite.setScale(0.5f, 0.5f);

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
					sprite.move(-10, 0);
					break;
				case sf::Keyboard::Key::Right:
					sprite.move(10, 0);
					break;
				case sf::Keyboard::Key::Up:
					sprite.move(0, -10);
					break;
				case sf::Keyboard::Key::Down:
					sprite.move(0, 10);
					break;
				}
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				sprite.setPosition(event.mouseButton.x, event.mouseButton.y);
			}

		}
		sprite.move(1.f, 0.f);

		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}