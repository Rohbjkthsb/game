#include "Player.h"

Player::Player()
{
	playerTexture.loadFromFile("Sprites/mario.png");
	playerTexture.setSmooth(true);
	playerSprite.setTexture(playerTexture);


}