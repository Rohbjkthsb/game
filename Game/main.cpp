#include "Menu.h"

int main()
{
	sf::RenderWindow* window = new sf::RenderWindow();
	Menu menu(window, 1280, 720);
	menu.Run();
	return 0;
}