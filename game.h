#pragma once
#include <list>
#include <string>
#include "SFML/Graphics.hpp"
#include "textures.h"
#include "person.h"
#include "text.h"
#include "Knight.h"
#include "timer.h"


class Game {
public:
	enum GameState { MENU, TAVERN, FIGHT };
	Game();
	void play();
protected:
	sf::Clock MenuTimeChange;
	sf::Time now;

	TextObject name1;
	TextObject name2;
	TextObject name3;

	TextObject persName1;
	TextObject persName2;
	TextObject persName3;
	TextObject enemyName1;
	TextObject enemyName2;
	TextObject enemyName3;

	TextObject persHp1;
	TextObject persHp2;
	TextObject persHp3;
	TextObject enemyHp1;
	TextObject enemyHp2;
	TextObject enemyHp3;


	sf::RenderWindow window;
	GameState game_state = MENU;
	obj menu_screen;
	obj Cave;
	obj CaveSel;
	obj Tavern;
	obj TavernSel;
	obj Shop;
	obj ShopSel;
	obj Knight;
	obj KnightSel;
	obj Mag;
	obj MagSel;
	obj Tank;
	obj TankSel;
	
	obj PersChNone1;
	obj PersChKnight1;
	obj PersChMag1;
	obj PersChTank1;

	obj PersChNone2;
	obj PersChKnight2;
	obj PersChMag2;
	obj PersChTank2;

	obj PersChNone3;
	obj PersChKnight3;
	obj PersChMag3;
	obj PersChTank3;


	obj PersFightNone1;
	obj PersFightKnight1;
	obj PersFightMag1;
	obj PersFightTank1;
			
	obj PersFightNone2;
	obj PersFightKnight2;
	obj PersFightMag2;
	obj PersFightTank2;
			
	obj PersFightNone3;
	obj PersFightKnight3;
	obj PersFightMag3;
	obj PersFightTank3;

	obj EnemyFightNone1;
	obj EnemyFightKnight1;
	obj EnemyFightMag1;
	obj EnemyFightTank1;
		
	obj EnemyFightNone2;
	obj EnemyFightKnight2;
	obj EnemyFightMag2;
	obj EnemyFightTank2;
		
	obj EnemyFightNone3;
	obj EnemyFightKnight3;
	obj EnemyFightMag3;
	obj EnemyFightTank3;


	std::list<KnightAnim*> knightsAnim;

	bool persDoTurn[3];

	int persTurn = -1;
	int spell = -1;

	Person persCh[3];
	Person enemyCh[3];
	obj PersonObj[3][2];
	obj EnemyObj[3][2];

	int Chmenu = 0;
	int Chfight = 0;

	int persons = 0;
	int personsCh = 0;

	int enemiesDied = 0;
	int playersDied = 0;

	Timer timer;

	std::string playerTurn = "prepare";

	void check_events();
	void update();
	void draw();
	void animPlay(Person::PersonClass, sf::Vector2f);
	void TakePerson(int);
	void StartFight();
};