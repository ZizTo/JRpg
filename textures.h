#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include <string>

class obj {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
public:
	void ObjCreate(std::string FileName, float x, float y) {
		texture.loadFromFile(IMAGES_FOLDER + FileName);
		sprite.setTexture(texture);
		sprite.setPosition(x, y);
	}
	sf::Sprite getSprite() { return sprite; }
	sf::Vector2f getPos() { return position; }
};