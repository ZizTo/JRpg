#include "game.h"
#include "settings.h"
#include "person.h"
#include <time.h>
#include <iostream>
#include <Windows.h>
#include <ctime>

Game::Game() :
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE),
	name1("font/GorgeousPixel.ttf", 48, 100.f, 540.f, sf::Color::Black),
	name2("font/GorgeousPixel.ttf", 48, 350.f, 540.f, sf::Color::Black),
	name3("font/GorgeousPixel.ttf", 48, 600.f, 540.f, sf::Color::Black),

	persName1("font/GorgeousPixel.ttf", 30, 50.f, 40.f, sf::Color::White),
	persName2("font/GorgeousPixel.ttf", 30, 50.f, 220.f, sf::Color::White),
	persName3("font/GorgeousPixel.ttf", 30, 50.f, 400.f, sf::Color::White),
	enemyName1("font/GorgeousPixel.ttf", 30, 650.f, 40.f, sf::Color::White),
	enemyName2("font/GorgeousPixel.ttf", 30, 650.f, 220.f, sf::Color::White),
	enemyName3("font/GorgeousPixel.ttf", 30, 650.f, 400.f, sf::Color::White),

	persHp1("font/GorgeousPixel.ttf", 30, 50.f, 80.f, sf::Color::White),
	persHp2("font/GorgeousPixel.ttf", 30, 50.f, 260.f, sf::Color::White),
	persHp3("font/GorgeousPixel.ttf", 30, 50.f, 440.f, sf::Color::White),
	enemyHp1("font/GorgeousPixel.ttf", 30, 650.f, 80.f, sf::Color::White),
	enemyHp2("font/GorgeousPixel.ttf", 30, 650.f, 260.f, sf::Color::White),
	enemyHp3("font/GorgeousPixel.ttf", 30, 650.f, 440.f, sf::Color::White)
{
}

void Game::play() {
	menu_screen.ObjCreate(MENU_PIC, 0.f, 0.f);

	Cave.ObjCreate("cave.png", 50.f, 170.f);
	CaveSel.ObjCreate("caveSel.png", 50.f, 170.f);
	TavernSel.ObjCreate("tavernSel.png", 300.f, 330.f);
	Tavern.ObjCreate("tavern.png", 300.f, 330.f);
	ShopSel.ObjCreate("shopSel.png", 600.f, 230.f);
	Shop.ObjCreate("shop.png", 600.f, 230.f);

	Knight.ObjCreate("knight.png", 50.f, 20.f);
	KnightSel.ObjCreate("knightSel.png", 50.f, 20.f);
	MagSel.ObjCreate("magSel.png", 375.f, 140.f);
	Mag.ObjCreate("mag.png", 375.f, 140.f);
	TankSel.ObjCreate("tankSel.png", 700.f, 70.f);
	Tank.ObjCreate("tank.png", 700.f, 70.f);

	PersChNone1.ObjCreate("persChNone.png", 100.f, 320.f);
	PersChKnight1.ObjCreate("persChKnight.png", 100.f, 320.f);
	PersChMag1.ObjCreate("persChMag.png", 100.f, 320.f);
	PersChTank1.ObjCreate("persChTank.png", 100.f, 320.f);

	PersChNone2.ObjCreate("persChNone.png", 350.f, 320.f);
	PersChKnight2.ObjCreate("persChKnight.png", 350.f, 320.f);
	PersChMag2.ObjCreate("persChMag.png", 350.f, 320.f);
	PersChTank2.ObjCreate("persChTank.png", 350.f, 320.f);

	PersChNone3.ObjCreate("persChNone.png", 600.f, 320.f);
	PersChKnight3.ObjCreate("persChKnight.png", 600.f, 320.f);
	PersChMag3.ObjCreate("persChMag.png", 600.f, 320.f);
	PersChTank3.ObjCreate("persChTank.png", 600.f, 320.f);

	while (window.isOpen()) {
		check_events();
		update();
		draw();
	}
}

void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
		else {
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::A)
				{
					Chmenu--;
					if (Chmenu < 0) Chmenu = 0;
				}
				else if (event.key.code == sf::Keyboard::D)
				{
					Chmenu++;
					if (Chmenu > 2) Chmenu = 2;
				}
				else if (game_state == TAVERN && event.key.code == sf::Keyboard::Space) {
					TakePerson(Chmenu);
				}
				else if (game_state == TAVERN && event.key.code == sf::Keyboard::BackSpace) {
					game_state = MENU;
					Chmenu = 0;
				}
				else if (game_state == MENU && event.key.code == sf::Keyboard::Space)
				{
					switch (Chmenu) {
					case 0:
						game_state = FIGHT;
						StartFight();
						Chmenu = 0;
						break;
					case 1:
						game_state = TAVERN;
						Chmenu = 0;
						break;
					case 2: 
						break;
					default:
						break;
					}
				}

				else if (game_state == FIGHT) {
					if (playerTurn == "choosingforattacking" && event.key.code == sf::Keyboard::Space) {
						playerTurn = "attacking";
					}
					else if (playerTurn == "choosingforstealing" && event.key.code == sf::Keyboard::Space) {
						playerTurn = "stealing";
					}
					else if (playerTurn == "choosingforteammate" && event.key.code == sf::Keyboard::Space) {
						playerTurn = "teammating";
					}
				}
			}
		}
	}
}

void Game::draw() {
	window.clear(sf::Color::Black);
	switch (game_state){
	case Game::MENU:

		window.draw(menu_screen.getSprite());
		switch (Chmenu)
		{
		case 0:
			window.draw(CaveSel.getSprite());
			window.draw(Tavern.getSprite());
			window.draw(Shop.getSprite());
			break;
		case 1:
			window.draw(Cave.getSprite());
			window.draw(TavernSel.getSprite());
			window.draw(Shop.getSprite());
			break;
		case 2:
			window.draw(Cave.getSprite());
			window.draw(Tavern.getSprite());
			window.draw(ShopSel.getSprite());
			break;
		}
		
		break;
	case Game::TAVERN:
		window.draw(menu_screen.getSprite());
		switch (Chmenu)
		{
		case 0:
			window.draw(KnightSel.getSprite());
			window.draw(Mag.getSprite());
			window.draw(Tank.getSprite());
			break;
		case 1:
			window.draw(Knight.getSprite());
			window.draw(MagSel.getSprite());
			window.draw(Tank.getSprite());
			break;
		case 2:
			window.draw(Knight.getSprite());
			window.draw(Mag.getSprite());
			window.draw(TankSel.getSprite());
			break;
		}

		switch (persCh[0].getClass())
		{
		default:
			window.draw(PersChNone1.getSprite());
			break;
		case Person::KNIGHT:
			window.draw(PersChKnight1.getSprite());
			break;
		case Person::MAG:
			window.draw(PersChMag1.getSprite());
			break;
		case Person::TANK:
			window.draw(PersChTank1.getSprite());
			break;
		}

		switch (persCh[1].getClass())
		{
		default:
			window.draw(PersChNone2.getSprite());
			break;
		case Person::KNIGHT:
			window.draw(PersChKnight2.getSprite());
			break;
		case Person::MAG:
			window.draw(PersChMag2.getSprite());
			break;
		case Person::TANK:
			window.draw(PersChTank2.getSprite());
			break;
		}

		switch (persCh[2].getClass())
		{
		default:
			window.draw(PersChNone3.getSprite());
			break;
		case Person::KNIGHT:
			window.draw(PersChKnight3.getSprite());
			break;
		case Person::MAG:
			window.draw(PersChMag3.getSprite());
			break;
		case Person::TANK:
			window.draw(PersChTank3.getSprite());
			break;
		}

		window.draw(name1.getText());
		window.draw(name2.getText());
		window.draw(name3.getText());

		break;

	case Game::FIGHT:
		for (int i = 0; i < 3; i++)
		{
			if (persCh[i].getHp() > 0)
			{
				if (Chmenu == i && playerTurn == "choosingforteammate")
				{
					window.draw(PersonObj[i][1].getSprite());
				}
				else {
					window.draw(PersonObj[i][0].getSprite());
				}
			}
		}
		for (int ii = 0; ii < 3; ii++)
		{
			if (enemyCh[ii].getHp() > 0)
			{
				if (Chmenu == ii && (playerTurn == "choosingforattacking" || playerTurn == "choosingforstealing")) {
					window.draw(EnemyObj[ii][1].getSprite());
				}
				else {
					window.draw(EnemyObj[ii][0].getSprite());
				}
			}
		}
		persName1.update(persCh[0].getName());
		persName2.update(persCh[1].getName());
		persName3.update(persCh[2].getName());
		persHp1.update("hp: " + std::to_string(persCh[0].getHp()));
		persHp2.update("hp: " + std::to_string(persCh[1].getHp()));
		persHp3.update("hp: " + std::to_string(persCh[2].getHp()));

		enemyName1.update(enemyCh[0].getName());
		enemyName2.update(enemyCh[1].getName());
		enemyName3.update(enemyCh[2].getName());
		enemyHp1.update("hp: " + std::to_string(enemyCh[0].getHp()));
		enemyHp2.update("hp: " + std::to_string(enemyCh[1].getHp()));
		enemyHp3.update("hp: " + std::to_string(enemyCh[2].getHp()));

		window.draw(persName1.getText());
		window.draw(persName2.getText());
		window.draw(persName3.getText());
		window.draw(persHp1.getText());
		window.draw(persHp2.getText());
		window.draw(persHp3.getText());
		window.draw(enemyName1.getText());
		window.draw(enemyName2.getText());
		window.draw(enemyName3.getText());
		window.draw(enemyHp1.getText());
		window.draw(enemyHp2.getText());
		window.draw(enemyHp3.getText());

		break;
	}

	window.display();
}

void Game::update() {

	switch (game_state)
	{
	case Game::MENU:
		break;
	case Game::TAVERN:
		break;
	case Game::FIGHT:
		if (timer.IstimerEnd() == true) {
			if (playerTurn == "player")
			{
				std::cout << "player turn\n";
				for (int i = 0; i < 3; i++)
				{
					persDoTurn[i] = false;
				}
				playerTurn = "hero";
			}
			else if (playerTurn == "hero") {
				enemiesDied = 0;
				for (int z = 0; z < 3; z++)
				{
					if (persCh[z].getHp() <= 0) { persCh[z].setHp(0); enemiesDied++; } //Text update
				}
				if (enemiesDied >= 3)
				{
					game_state = MENU;
				}
				playersDied = 0;
				for (int z = 0; z < 3; z++)
				{
					if (persCh[z].getHp() <= 0) { persCh[z].setHp(0); playersDied++; } //Text update
				}
				if (playersDied >= 3)
				{
					game_state = MENU;
				}
				if (persCh[0].getHp() > 0 && persDoTurn[0] != true) {
					persTurn = 0;
					std::cout << persCh[0].getName() << " turn\n";
					playerTurn = "spelling";
					persDoTurn[0] = true;
				}
				else if (persCh[1].getHp() > 0 && persDoTurn[1] != true)
				{
					persTurn = 1;
					std::cout << persCh[1].getName() << " turn\n";
					playerTurn = "spelling";
					persDoTurn[1] = true;
				}
				else if (persCh[2].getHp() > 0 && persDoTurn[2] != true)
				{
					persTurn = 2;
					std::cout << persCh[2].getName() << " turn\n";
					playerTurn = "spelling";
					persDoTurn[2] = true;
				}
				else { playerTurn = "enemy"; }
			}
			else if (playerTurn == "spelling")
			{
				std::cout << persCh[persTurn].getName() << " turn\n";
				std::cout << "0 - atack, 1 - spell on you (10 mana), 2 - spell on teammate (15 mana), 3 - spell on you (20 mana)\n";
				std::cin >> spell;
				switch (spell)
				{
				case 0:
					playerTurn = "choosingforattacking";
					break;
				case 1:
					playerTurn = "healing";
					break;
				case 2:
					playerTurn = "choosingforteammate";
					break;
				case 3:
					playerTurn = "choosingforstealing";
					break;
				default:
					break;
				}
			}
			else if (playerTurn == "attacking")
			{
				persCh[persTurn].AtackEnemy(enemyCh[Chmenu]);
				std::cout << enemyCh[Chmenu].getName() << " have only " << std::to_string(enemyCh[Chmenu].getHp()) << " hp" << std::endl;
				playerTurn = "hero";
				timer.StartTimer(3000, 100);
			}
			else if (playerTurn == "healing")
			{
				persCh[persTurn].FirstSpell();
				playerTurn = "hero";
				timer.StartTimer(3000, 100);
			}
			else if (playerTurn == "teammating")
			{
				persCh[persTurn].SecondSpell(persCh[Chmenu]);
				playerTurn = "hero";
				timer.StartTimer(3000, 100);
			}
			else if (playerTurn == "stealing")
			{
				persCh[persTurn].ThirdSpell(enemyCh[Chmenu]);
				playerTurn = "hero";
				timer.StartTimer(3000, 100);

			}
			else if (playerTurn == "enemy")
			{
				for (int i = 0; i < 3; i++)
				{
					if (enemyCh[i].getHp() > 0)
					{
						int a = rand() % 4;
						int b = 0;
						switch (a)
						{
						case 0:
							b = rand() % 3;
							while (persCh[b].getHp() <= 0) {
								b = rand() % 3;
							}
							enemyCh[i].AtackEnemy(persCh[b]);
							break;
						case 1:
							if (enemyCh[i].getMana() >= 10)
							{
								enemyCh[i].FirstSpell();
							}
							else
							{
								b = rand() % 3;
								while (persCh[b].getHp() <= 0) {
									b = rand() % 3;
								}
								enemyCh[i].AtackEnemy(persCh[b]);
							}

							break;
						case 2:
							if (enemyCh[i].getMana() >= 15)
							{
								b = rand() % 3;
								while (b == i) {
									b = rand() % 3;
								}
								enemyCh[i].SecondSpell(enemyCh[b]);
							}
							else
							{
								b = rand() % 3;
								while (persCh[b].getHp() <= 0) {
									b = rand() % 3;
								}
								enemyCh[i].AtackEnemy(persCh[b]);
							}
							break;
						case 3:
							b = rand() % 3;
							while (persCh[b].getHp() <= 0) {
								b = rand() % 3;
							}
							if (enemyCh[i].getMana() >= 20)
							{
								enemyCh[i].ThirdSpell(persCh[b]);
							}
							else {
								enemyCh[i].AtackEnemy(persCh[b]);
							}

							break;
						}
						enemiesDied = 0;
						for (int z = 0; z < 3; z++)
						{
							if (persCh[z].getHp() <= 0) { persCh[z].setHp(0); enemiesDied++; } //Text update
						}
						if (enemiesDied >= 3)
						{
							game_state = MENU;
						}
						playersDied = 0;
						for (int z = 0; z < 3; z++)
						{
							if (persCh[z].getHp() <= 0) { persCh[z].setHp(0); playersDied++; } //Text update
						}
						if (playersDied >= 3)
						{
							game_state = MENU;
						}
						timer.StartTimer(3000, 100);
					}
				}
			}
		}
	}
}

void Game::TakePerson(int chose) {
	std::string name;
	std::cout << "name of your hero: ";
	std::cin >> name;
	int place;
	std::cout << "\nplace: ";
	std::cin >> place;
	std::cout << "\n";
	place--;
	switch (chose)
	{
	case 0:
		persCh[place] = Person(Person::PersonClass::KNIGHT, name, 200, 25, 100);
		PersonObj[place][0].ObjCreate("knight.png", 300.f, 20.f + place * 180.f);
		PersonObj[place][1].ObjCreate("knightSel.png", 300.f, 20.f + place * 180.f);
		break;
	case 1:
		persCh[place] = Person(Person::PersonClass::MAG, name, 180, 10, 300);
		PersonObj[place][0].ObjCreate("mag.png", 300.f, 20.f + place * 180.f);
		PersonObj[place][1].ObjCreate("magSel.png", 300.f, 20.f + place * 180.f);
		break;
	case 2:
		persCh[place] = Person(Person::PersonClass::TANK, name, 500, 5, 80);
		PersonObj[place][0].ObjCreate("tank.png", 300.f, 20.f + place * 180.f);
		PersonObj[place][1].ObjCreate("tankSel.png", 300.f, 20.f + place * 180.f);
		break;
	}
	switch (place)
	{
	case 0:
		name1.update(name);
		break;
	case 1:
		name2.update(name);
		break;
	case 2:
		name3.update(name);
		break;
	}
	for (int i = 0; i < 3; i++)
	{
		std::cout << persCh[i].getName() << "\n";
	}
}

void Game::animPlay(Person::PersonClass pclass, sf::Vector2f pos) {
	if (pclass == Person::KNIGHT) {
		KnightAnim* new_knight = new KnightAnim(pos);
		knightsAnim.push_back(new_knight);
	}
}

void Game::StartFight() {
	playerTurn = "prepare";

	srand(time(0));
	rand();

	for (int i = 0; i < 3; i++)
	{
		int a;
		a = rand() % 3;
		switch (a)
		{
		case 0:
			enemyCh[i] = Person(Person::PersonClass::KNIGHT, "Enemy Knight", 200, 25, 100);
			EnemyObj[i][0].ObjCreate("knightEnemy.png", 500.f, 20.f + i * 180.f);
			EnemyObj[i][1].ObjCreate("knightEnemySel.png", 500.f, 20.f + i * 180.f);
			break;
		case 1:
			enemyCh[i] = Person(Person::PersonClass::MAG, "Enemy Mag", 180, 10, 300);
			EnemyObj[i][0].ObjCreate("magEnemy.png", 500.f, 20.f + i * 180.f);
			EnemyObj[i][1].ObjCreate("magEnemySel.png", 500.f, 20.f + i * 180.f);
			break;
		case 2:
			enemyCh[i] = Person(Person::PersonClass::TANK, "Enemy Tank", 500, 5, 80);
			EnemyObj[i][0].ObjCreate("tankEnemy.png", 500.f, 20.f + i * 180.f);
			EnemyObj[i][1].ObjCreate("tankEnemySel.png", 500.f, 20.f + i * 180.f);
			break;
		}
	}

	playerTurn = "player";
}
