#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include <string>

class Person {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	std::string name = ":)";
	int hp = 100;
	int dmg = 10;
	int mana = 100;
public:
	enum PersonClass { KNIGHT, MAG, TANK };
	PersonClass pclass = KNIGHT;
	Person(PersonClass npclass, std::string nname, int nhp, int ndmg, int nmana) :
		pclass{npclass}, name {nname}, hp {nhp}, dmg {ndmg}, mana {nmana}
	{}

	Person();
	void update();
	void draw(sf::RenderWindow& window);
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();

	int getHp();
	int getDmg();
	int getMana();
	PersonClass getClass();
	std::string getName();

	void setHp(int);
	void setDmg(int);
	void setMana(int);

	void AtackEnemy(Person);

	void FirstSpell();
	void SecondSpell(Person);
	void ThirdSpell(Person);
};