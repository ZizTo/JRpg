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
public:
	//========TO GET ACCESS========
	//seter
	void setHp(int hp) { h_hp = hp; }
	void setDmg(int dmg) { h_dmg = dmg; }
	void setClass(int clas) { h_class = clas; }
	void setName(string name) { h_name = name; }
	
	//constructor
	Hero(string name, int hp, int dmg, int clas) {
		h_hp = hp;
		h_dmg = dmg;
		h_class = clas;
		h_name = name;
	}

	//geter
	int getHp() { return h_hp; }
	int getDmg() { return h_dmg; }
	int getClass() { return h_class; }
	string getName() { return h_name; }

	//=======SPELLS=========
	//Atack
	void Atack(Hero &enemy){ enemy.setHp(enemy.getHp() - h_dmg); }


	/*		First spell :
			0 - dmg increase
			1 - heal
	*/
	void FirstSpell() {
		if (h_class == 0) {
			h_dmg = round(h_dmg * 1.1);
		}
		if (h_class == 1) {
			h_hp += 200;
		}
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
};

int main() {
	//New heroes
	Hero arkadi("Arkadi", 500, 50, 0);
	
	Hero valera("Valera", 500, 100, 1);
	valera.setName("Valera");
	valera.setHp(500);
	valera.setDmg(100);
	valera.setClass(1);

	//Appearence
	arkadi.Appearence();
	valera.Appearence();
	cout << endl;
	//Game
	while (true) {
		//newturn
		 
		
		//Valera atack
		valera.Atack(arkadi);
		valera.AtackT();
		arkadi.GetDamage();
		valera.FirstSpell();

		cout << endl;
		
		//Arkadi atack
		arkadi.Atack(valera);
		arkadi.AtackT();
		valera.GetDamage();
		arkadi.FirstSpell();

		//endturn
		if (valera.getHp() <= 0) { arkadi.Win(); break; }
		if (arkadi.getHp() <= 0) { valera.Win(); break; }
		Sleep(6000);
		cout << endl << endl;
	}
}