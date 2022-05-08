#include "settings.h"
#include "Knight.h"
#include "game.h"
#include <ctime>

std::string KnightAnim::knight_anim_files[] = {
	"0.png", "1.png", "2.png", "3.png", "4.png", "5.png", "6.png", "7.png", 
	"7.png", "6.png", "5.png", "4.png", "3.png", "2.png", "1.png", "0.png" 
};

KnightAnim::KnightAnim(sf::Vector2f pos) {
	texture.loadFromFile(IMAGES_FOLDER + "knightanim/" + knight_anim_files[0]);
	sprite.setTexture(texture);
	position = pos;
	sprite.setPosition(position);
}
void KnightAnim::update() {
	sf::Time now = clock.getElapsedTime();
	if (now.asMilliseconds() > frame_delay) {
		frame++;
		if (frame < 16) {
			clock.restart();
			texture.loadFromFile(IMAGES_FOLDER + knight_anim_files[frame]);
			sprite.setTexture(texture);
			sprite.setPosition(position);
		}
		else {
			del = true;
		}

	}
}
bool KnightAnim::getDel() { return del; }
void KnightAnim::draw(sf::RenderWindow& window) { window.draw(sprite); }