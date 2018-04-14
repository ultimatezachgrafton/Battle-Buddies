// Monster.h header file defines the Monster class and its sub classes.

#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Menu.h"
#include "Player.h"
#include "Item.h"
using namespace std;

// spider uses spiderweb to drop SPD, etc

class Monster {
private:
    string name;
    int rating; //difficulty rating
    bool dead = false;

	string specialName;
	int	specialMeter,
		specialCharge,
		attack,
		defense,
		speed,
		hp;

public:
    Monster() {
		hp = 0;
		attack = 0;
		defense = 0;
		speed = 0;
		specialCharge = 0;
		specialMeter = 0;
		specialName = "";
    }
    Monster(int h, int atk, int def, int spd, int spcC, int spclM, string spclN) {
		hp = h;
		attack = atk;
		defense = def;
		speed = spd;
		specialMeter = spclM;
		specialCharge = spcC;
		specialName = spclN;
    }

	string printAvatar() {

		char a1[11] = "  \\\\  // "; //dead
		char a2[11] = "   \\\\//  ";
		char a3[11] = "    /\\    ";
		char a4[11] = "   //\\\\  ";
		char a5[11] = "  //  \\\\ ";

		char h1[11] = "  _____   "; //monster
		char h2[11] = " / \\  / \\ ";
		char h3[11] = " | @  @ | ";
		char h4[11] = " \\  /\\  / ";
		char h5[11] = "  ||||||  ";

		if (dead == true) {
				cout << a1 << endl;
				cout << a2 << endl;
				cout << a3 << endl;
				cout << a4 << endl;
				cout << a5 << endl;
			}

		if (dead == false) {
				cout << h1 << endl;
				cout << h2 << endl;
				cout << h3 << endl;
				cout << h4 << endl;
				cout << h5 << endl;
			}
		return " ";
	}

    //--------------Setters / Getters------------//
    void setName(string x) {name = x; }
    void setRating(int x) {rating = x; }
	void setHp(int h) { hp = h; return; }
	void setAtk(int atk) { attack = atk; return; }
	void setDef(int def) { defense = def; return; }
	void setSpd(int spd) { speed = spd; return; }
	void setSpclM(int spclM) { specialMeter = spclM; return; }
	void setSpclC(int spclC) { specialCharge = spclC; return; }
	void setSpclN(string spclN) { specialName = spclN; return; }

	void setDead(bool x) {
	    if(dead == false) {
            name = name + "(DEAD)";
	    }
        dead = x;
        hp = 0;
        }

	string getName() { return name; }
	int getSpclM() { return specialMeter; }
	int getHp() { return hp; }
	int getAtk() { return attack; }
	int getDef() { return defense; }
	int getSpd() { return speed; }
	int getSpclC() { return specialCharge; }
	string getSpclN() { return specialName; }
	bool getDead() { return dead; }

};

class Slime: public Monster {
private:
    const int monsterNum = 1;
public:
    Slime():Monster(35,15,15,4,15,0,"squirt") {
		setName("Slime");
		setRating(5);
    }

};

class Imp: public Monster {
private:
    const int monsterNum = 2;
public:
    Imp():Monster(40,20,15,5,15,0,"hard blow") {
    setName("Imp");
    setRating(10);
    }

};

class Spider: public Monster {
private:
    const int monsterNum = 3;
public:
    Spider():Monster(35,40,35,6,20,0,"spiderweb") {
    setName("Spider");
    setRating(15);
    }

};

class Ghoul: public Monster {
private:
    const int monsterNum = 4;
public:
    Ghoul():Monster(40,25,35,20,20, 0,"pustulate") {
    setName("Ghoul");
    setRating(20);
    }

};

class Skeleton: public Monster {
private:
    const int monsterNum = 5;
public:
    Skeleton():Monster(45,36,37,8,30,0,"bone throw") {
    setName("Skeleton");
    setRating(25);
    }

};

class Zombie: public Monster {
private:
    const int monsterNum = 6;
public:
    Zombie():Monster(46,37,38,1,30,0,"gnaw") {
    setName("Zombie");
    setRating(30);
    }

};

class Goblin: public Monster {
private:
    const int monsterNum = 7;
public:
    Goblin():Monster(50,48,49,50,35,0,"stabbity") {
    setName("Goblin");
    setRating(35);
    }

};

class Thief: public Monster {
private:
    const int monsterNum = 8;
public:
    Thief():Monster(68,69,40,81,40,0,"steal yo girl") {
    setName("Thief");
    setRating(40);
    }

};

class Assassin: public Monster {
private:
    const int monsterNum = 9;
public:
    Assassin():Monster(79,80,45,85,45,0,"garrote") {
    setName("Assassin");
    setRating(45);
    }

};

class Berserker: public Monster {
private:
    const int monsterNum = 10;
public:
    Berserker():Monster(100,111,112,113,50,0,"rampage") {
    setName("Berserker");
    setRating(50);
    }

};

class DarkFanatic: public Monster {
private:
    const int monsterNum = 11;
public:
    DarkFanatic():Monster(115,115,80,30,55,0,"dark ritual") {
    setName("Dark Fanatic");
    setRating(55);
    }

};

class DarkWarrior: public Monster {
private:
    const int monsterNum = 12;
public:
    DarkWarrior():Monster(150,120,120,55,60,0,"blood sacrifice") {
    setName("Dark Warrior");
    setRating(60);
    }

};

class DarkKnight: public Monster {
private:
    const int monsterNum = 13;
public:
    DarkKnight():Monster(165,100,150,16,70,0,"soul sacrifice") {
    setName("Dark Knight");
    setRating(65);
    }

};

class Singh : public Monster {
private:
    const int monsterNum = 14;
public:
    Singh():Monster(200, 200, 200, 200, 200, 200, "nyaa, see?") {
    setName("Mafia King");
    setRating(70);
    }

};
