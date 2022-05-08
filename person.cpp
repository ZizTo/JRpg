#include "person.h"
#include "settings.h"
#include <iostream>

Person::Person() {
	switch (pclass)
	{
	case Person::KNIGHT:
		hp = 200;
		dmg = 25;
		mana = 100;
		break;
	case Person::MAG:
		hp = 180;
		dmg = 10;
		mana = 300;
		break;
	case Person::TANK:
		hp = 500;
		dmg = 5;
		mana = 80;
		break;
	default:
		break;
	}
}
void Person::update() {
	
}

void Person::draw(sf::RenderWindow& window) { window.draw(sprite); }
sf::Vector2f Person::getPosition() { return sprite.getPosition(); }
int Person::getHp() { return hp; }
int Person::getDmg() { return dmg; }
int Person::getMana() { return mana; }
Person::PersonClass Person::getClass() { return pclass; }
std::string Person::getName() { return name; }
void Person::setHp(int nhp) { hp = nhp; }
void Person::setDmg(int ndmg) { dmg = ndmg; }
void Person::setMana(int nmana) { mana = nmana; }

void Person::AtackEnemy(Person enemy) {
	enemy.setHp(enemy.getHp() - dmg);
	std::cout << name << " atack " << enemy.getName() << " on " << dmg << " damage" << std::endl;
}

void Person::FirstSpell() {
	if (mana >= 10) {
		switch (pclass)
		{
		case Person::KNIGHT:
			dmg += 10;
			std::cout << name << " get 10 more damage";
			break;
		case Person::MAG:
			mana += 40;
			std::cout << name << " get 40 more mana";
			break;
		case Person::TANK:
			hp += 50;
			std::cout << name << " get 50 more heal points";
			break;
		}
		mana -= 10;
		
	}
}

void Person::SecondSpell(Person team) {
	if (mana >= 15) {
		switch (pclass)
		{
		case Person::KNIGHT:
			team.dmg += 8;
			std::cout << name << " give " << team.getName() << " 8 more damage";
			break;
		case Person::MAG:
			team.mana += 35;
			std::cout << name << " give " << team.getName() << " 35 more mana";
			break;
		case Person::TANK:
			team.hp += 40;
			std::cout << name << " give " << team.getName() << " 40 more heal points";
			break;
		}
		mana -= 15;
	}
}

void Person::ThirdSpell(Person enemy) {
	if (mana >= 20) {
		switch (pclass)
		{
		case Person::KNIGHT:
			enemy.dmg -= 4;
			dmg += 4;
			std::cout << name << " steal " << enemy.getName() << " 4 damage";
			break;
		case Person::MAG:
			enemy.hp -= 25;
			std::cout << name << " atack " << enemy.getName() << " on 20 heal points";
			break;
		case Person::TANK:
			enemy.hp -= 10;
			hp += 15;
			std::cout << name << " steal " << enemy.getName() << " 15 heal points";
			break;
		}
		mana -= 20;
	}
}