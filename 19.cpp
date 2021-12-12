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

	//geter
	int getHp() { return h_hp; }
	int getDmg() { return h_dmg; }
	int getClass() { return h_class; }
	string getName() { return h_name; }

	//=======FUNCTIONS=========
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

	void Appearence() {
		if (h_class == 0) { cout << "On the field appeared knight " << h_name << " with " << h_hp << " heal points and " << h_dmg << " damage" << endl; }
		if (h_class == 1) { cout << "On the field appeared mag " << h_name << " with " << h_hp << " heal points and " << h_dmg << " damage" << endl; }
	}

	void Win() {
		cout << h_name << " WIN!";
	}

	void Atack() { cout << h_name << " atack! He atack " << h_dmg << " damage. "; }
	void GetDamage() { cout << h_name << " have " << h_hp << " heal points. "; }
};

int main() {
	//New heroes
	Hero arkadi;
	arkadi.setName("Arkadi");
	arkadi.setHp(1000);
	arkadi.setDmg(50);
	arkadi.setClass(0);
	
	Hero valera;
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
		 
		
		//Arcadi atack
		valera.setHp(valera.getHp() - arkadi.getDmg());
		valera.Atack();
		arkadi.GetDamage();
		if (valera.getHp() <= 0) { arkadi.Win(); break; }
		arkadi.FirstSpell();

		cout << endl;
		
		//Valera atack
		arkadi.setHp(arkadi.getHp() - valera.getDmg());
		arkadi.Atack();
		valera.GetDamage();
		if (arkadi.getHp() <= 0) { valera.Win(); break; }
		valera.FirstSpell();

		//endturn
		Sleep(6000);
		cout << endl << endl;
	}
}