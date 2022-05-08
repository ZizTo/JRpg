#pragma once
#include "SFML/Graphics.hpp"

class KnightAnim {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	static std::string knight_anim_files[];
	size_t frame = 0;
	size_t frame_delay = 42;
	sf::Vector2f position;
	bool del = false;
	sf::Clock clock;
public:
	KnightAnim(sf::Vector2f pos);
	void update();
	void draw(sf::RenderWindow&);
	bool getDel();
};