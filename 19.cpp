//ZizTo
#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;


/*		Classes id:
		0 - Knight
		1 - Mag
*/
class Hero {
private:
	//========DATA=========
	string h_name;
	int h_hp;
	int h_dmg;
	int h_class;
	int h_xp;
	int h_mana;
	int h_maxhp;
	int h_maxdmg;
	int h_maxmana;
public:
	//========TO GET ACCESS========
	//seter
	void setHp(int hp) { h_hp = hp; }
	void setDmg(int dmg) { h_dmg = dmg; }
	void setClass(int clas) { h_class = clas; }
	void setName(string name) { h_name = name; }
	void setXp(int xp) { h_xp = xp; }
	void setMana(int mana) { h_mana = mana; }

	//constructor
	Hero(string name, int hp, int dmg, int clas, int xp, int mana) {
		h_maxhp = hp;
		h_maxdmg = dmg;
		h_class = clas;
		h_name = name;
		h_xp = xp;
		h_maxmana = mana;
	}

	//geter
	int getHp() { return h_hp; }
	int getDmg() { return h_dmg; }
	int getClass() { return h_class; }
	string getName() { return h_name; }
	int getXp() { return h_xp; }
	int getMana() { return h_mana; }

	//=======SPELLS=========
	//Atack
	void Atack(Hero& enemy) { enemy.setHp(enemy.getHp() - h_dmg); AtackT(); enemy.GetDamage(); }


	/*		First spell :
			0 - dmg increase
			1 - heal
	*/
	void HealSpell(int cost, Hero& enemy) {
		if (h_mana > 9) {
			h_hp += 100;
			h_mana -= cost;
		}
		else {
			Atack(enemy);
		};
	}
	void DmgIncrease(int cost, Hero& enemy) {
		if (h_mana > 9) {
			h_dmg = round(h_dmg * 1.1);
			h_mana -= cost;
		}
		else { 
			Atack(enemy);
		};
	}

	//=======TEXT======
	void Appearence() {
		if (h_class == 0) { cout << "On the field appeared knight " << h_name << " with " << h_hp << " heal points and " << h_dmg << " damage" << endl; }
		if (h_class == 1) { cout << "On the field appeared mag " << h_name << " with " << h_hp << " heal points and " << h_dmg << " damage" << endl; }
	}

	void Win() {
		cout << h_name << " WIN!";
	}

	void AtackT() { cout << h_name << " atack! He atack " << h_dmg << " damage. "; }
	void GetDamage() { cout << h_name << " have " << h_hp << " heal points. "; }

	//=======OTHER=======
	void start() { h_hp = h_maxhp; h_dmg = h_maxdmg; h_mana = h_maxmana; }

	void upgrade(int upgr) {
		switch (upgr)
		{
		case 1:
			h_maxhp += 50;
			break;
		case 2:
			h_maxdmg += 5;
			break;
		case 3:
			h_maxmana += 10;
			break;
		default:
			break;
		}
	}
};

int main() {
	//Create Hero
	string inname; int inclas; int dmg; int hp; int mana;
	cout << "Name your person and choose your class (0 - knight, 1 - mag)" << endl;
	cin >> inname >> inclas;
	if (inclas == 0)
	{
		hp = 500; dmg = 20; mana = 10;
	} 
	else if (inclas == 1) {
		hp = 300; dmg = 10; mana = 100;
	}
	Hero player(inname, hp, dmg, inclas, 0, mana);

	//Create enemy
	Hero enemy("Vasia", 500, 5, 1, 10, 30);

	while (true)
	{
		enemy.start();
		player.start();

		//Appearence
		player.Appearence();
		enemy.Appearence();
		cout << endl;

		while (true) {
			//New turn
			//Player atack
			cout << "Your turn! What you gona do? (0 - attack, 1 - heal (100hp, 10 mana), 2 - Demage Increase (+10%, 10 mana))" << endl;
			int button;
			cin >> button;

			switch (button)
			{
			case 0:
				player.Atack(enemy);
				break;
			case 1:
				player.HealSpell(10, enemy);
				break;
			case 2:
				player.DmgIncrease(10, enemy);
				break;
			default:
				break;
			}

			cout << endl;

			srand(time(0));
			//Enemy atack
			switch (rand() % 3)
			{
			case 0:
				enemy.Atack(player);
				break;
			case 2:
				enemy.DmgIncrease(10, player);
				break;
			case 1:
				enemy.HealSpell(10, player);
				break;
			default:
				break;
			}

			//endturn
			if (player.getHp() <= 0) { enemy.Win(); player.setXp(player.getXp() + enemy.getXp()); break; }
			if (enemy.getHp() <= 0) { player.Win(); break; }
			Sleep(6000);
			cout << endl << endl;
		}
		//Upgrade
		cout << "you can upgrade 1 - max hp, 2 - dmg, 3 - mana, 0 - stop upgrade. Cost 5 xp. You have: " << player.getXp() << "xp." << endl;
		int upgr = 1;
		cin >> upgr;
		while (upgr != 0) {
			player.upgrade(upgr);
			cin >> upgr;
		}
	}
	//Game
	
}