// Player.h header file defines the Player class and its sub classes.
#pragma once
#include <iostream>
#include <string>
#include "Monster.h"
#include "Item.h"
#include <vector>
using namespace std;

class Player
{
private:
	string name;
	int	spcCharge,		// Special charge amount will range from 0 to 100; starts at 100 (full charge).
		attack,
		defense,
		speed,
		hp;
	bool isDead;
	vector<Item> inventory;			// Inventory for each character.
public:
	Player()			// Default constructor.
	{
		hp = 0;
		attack = 0;
		defense = 0;
		speed = 0;
		spcCharge = 0;
	}
	Player(int h, int atk, int def, int spd, int spcC)
	{
		hp = h;
		attack = atk;
		defense = def;
		speed = spd;
		spcCharge = spcC;
		isDead = false;			// All members are initialized.
	}

	void attacking(Monster& monst)
	{											//Also, access to monster HP might vary.
		monst.setHp(monst.getHp() - attack);	//Need to account for defense of monster... percentage ?
		cout << monst.getName() << " took " << attack << " damage" << endl;
		return;
	}
		// OVERLOADED ATTACKING FUNCTION THAT WILL ALLOW PLAYERS TO ATTACK PLAYERS

	void attacking(Player& play)
	{
		play.hp = play.hp - this->attack;
		cout << play.getName() << " took " << attack << " damage" << endl;
		return;
	}

	void block(Monster monst)				//Player blocks 2/3 of damage of enemy attack.
	{
		hp = hp - (.66 * monst.getAtk());	// factor in player defense.
		return;
	}
	void passTurn()
	{
		hp = hp * 1.15;		//HP increases by 15%
		return;
	}
	void incrementSpecial()										//Increments special charge by 25.
	{
		spcCharge = spcCharge + 25;
		return;
	}
	void addToInventory(Item i)									//Adds an item to the inventory of the character.
	{
		cout << "Adding " << i.getName() << " to inventory\n";
		inventory.push_back(i);
		return;
	}
	void useItem(Player& play)								//Called when an item is used.
	{
		//Make a way to choose an item from the inventory.
		//List the items in the inventory
		if (inventory.size() != 0)		//Check to see if the inventory is empty.
		{
			cout << "Choose an item to use from your invntory:" << endl;
			for (unsigned int ind = 0; ind < inventory.size(); ind++)			//Display items contained in inventory.
			{
				cout << ind + 1 << ") " << inventory[ind].getName() << endl;
			}
			//Allow user to choose.
			int choice;
			do
			{
				cout << "\n->";
				cin >> choice;
			} while (choice > inventory.size() || choice <= 0);

			cout << "\nUsing item: " << inventory[choice-1].getName() << endl;

			play.setHp(play.getHp() + inventory[choice - 1].getHp());

			play.setAtk(play.getAtk() + inventory[choice - 1].getAtk());

			play.setDef(play.getDef() + inventory[choice - 1].getDef());

			play.setSpd(play.getSpd() + inventory[choice - 1].getSpd());

			play.setSpclC(play.getSpclC() + inventory[choice - 1].getSpl());

			if (inventory[choice - 1].getName() == "Revive")					//***For revive item.
			{
				play.isDead = false;
			}
			inventory.erase(inventory.begin() + (choice - 1)); //erase item after player uses it
		}
		else			//If the player's inventory is empty...
		{
			cout << "Your inventory is currently empty!\n";
		}
		return;
	}
	void useItem(Monster& monst)								//Called when an item is used.
	{
		//Make a way to choose an item from the inventory.
		//List the items in the inventory
		if (inventory.size() != 0)		//Check to see if the inventory is empty.
		{
			cout << "Choose an item to use from your invntory:" << endl;
			for (unsigned int ind = 0; ind < inventory.size(); ind++)			//Display items contained in inventory.
			{
				cout << ind + 1 << ") " << inventory[ind].getName() << endl;
			}
			//Allow user to choose.
			int choice;
			do
			{
				cout << "\n->";
				cin >> choice;
			} while (choice > inventory.size() || choice <= 0);

			cout << "\nUsing item: " << inventory[choice - 1].getName() << endl;

			monst.setHp(monst.getHp() + inventory[choice - 1].getHp());

			monst.setAtk(monst.getAtk() + inventory[choice - 1].getAtk());

			monst.setDef(monst.getDef() + inventory[choice - 1].getDef());

			monst.setSpd(monst.getSpd() + inventory[choice - 1].getSpd());

			monst.setSpclC(monst.getSpclC() + inventory[choice - 1].getSpl());

			if (inventory[choice - 1].getName() == "Revive")					//***For revive item.
			{
				monst.setDead(false);
			}
			inventory.erase(inventory.begin() + (choice - 1)); //erase item after player uses it
		}
		else			//If the player's inventory is empty...
		{
			cout << "Your inventory is currently empty!\n";
		}
		return;
	}

	virtual void special(Monster&)				//Virtual function for player specials.
	{
		cout << "default special\n";
		return;
	}

	virtual void special(Player&)				//Virtual function for player specials.
	{
		cout << "default special\n";
		return;
	}

	virtual void printAvatar() {}

	//------------------------------------------------------------------//
	//Getters and setters												//
	//------------------------------------------------------------------//
	void setName()		// Called within each sub-class constructor.
	{
		printAvatar();
		cout << "What is this character's name?\n->";
		getline(cin, name);
		cin.clear();
		return;
	}
	//void copyName(string n) { name = n; return; }
	void setHp(int h) { hp = h; return; }
	void setAtk(int atk) { attack = atk; return; }
	void setDef(int def) { defense = def; return; }
	void setSpd(int spd) { speed = spd; return; }
	void setSpclC(int spclC) { spcCharge = spclC; return; }
	void setDead(bool x) {
    if(isDead == false) {
            name = name + "(DEAD)";
	    }
        isDead = x;
        hp = 0;
        }

	string getName() { return name; }
	int getHp() { return hp; }
	int getAtk() { return attack; }
	int getDef() { return defense; }
	int getSpd() { return speed; }
	int getSpclC() { return spcCharge; }
	int getDead() { return isDead; }
};

class Mercenary : public Player	  //------------------------------------------------------------------//Mercenary
{
public:
	Mercenary(): Player(150, 30, 10, 10, 100) //hp, atk, def, spd, spc, spcCharge
	{
		//Mercenary has increased health and attack.
		cout << "Soup Kitchen Volunteer\n\n";
		setName();
		system("pause");
	}
	void special(Monster& monst)
	{
		int choice = 0;
		if (getSpclC() >= 100)
		{
			do
			{
				cout << "Which special would you like to use?"	//**
					<< "\n1)Charge: 50 DMG"						//Pick a special to use.
					<< "\n2)Bandage: +50 HP" << endl;			//**
				cin >> choice;
			} while (choice != 1 && choice != 2);

			if (choice == 1)
			{
				cout << "Charge!" << endl;
				monst.setHp(monst.getHp() - 50);
				setSpclC(getSpclC() - 100);								//Update special charge.
			}
			else if (choice == 2)
			{
				cout << "Bandaging" << endl;
				setHp(getHp() + 50);
				setSpclC(getSpclC() - 100);								//Update special charge.
			}
		}
		else
		{
			cout << "Special has not charged up yet!\n";
		}

		return;
	}
	void special(Player& play)
	{
		int choice = 0;
		if (getSpclC() >= 100)
		{
			do
			{
				cout << "Which special would you like to use?"	//**
					<< "\n1)Charge: 50 DMG"						//Pick a special to use.
					<< "\n2)Bandage: +50 HP" << endl;			//**
				cin >> choice;
			} while (choice != 1 && choice != 2);

			if (choice == 1)
			{
				cout << "Charge!" << endl;
				play.setHp(play.getHp() - 50);
				setSpclC(getSpclC() - 100);								//Update special charge.
			}
			else if (choice == 2)
			{
				cout << "Bandaging" << endl;
				setHp(getHp() + 50);
				setSpclC(getSpclC() - 100);								//Update special charge.
			}
		}
		else
		{
			cout << "Special has not charged up yet!\n";
		}

		return;
	}

    void printAvatar() {

        string a1 = "  \\\\  // "; // dead
        string a2 = "   \\\\//  ";
        string a3 = "    /\\    ";
        string a4 = "   //\\\\  ";
        string a5 = "  //  \\\\ ";

        string b1 = "       O  "; // soup kitchen volunteer
        string b2 = "    0  |  ";
        string b3 = "  /( )\\|  ";
        string b4 = "( )/_\\    ";
        string b5 = "   | |    ";

        if (getDead() == true) {
            cout << a1 << endl;
            cout << a2 << endl;
            cout << a3 << endl;
            cout << a4 << endl;
            cout << a5 << endl;
        }

        if (getDead() == false) {
            cout << b1 << endl;
            cout << b2 << endl;
            cout << b3 << endl;
            cout << b4 << endl;
            cout << b5 << endl;
        }
    }
};
class Knight : public Player	   //------------------------------------------------------------------//Knight
{
public:
	Knight(): Player(100, 30, 50, 10, 100 )
	{
		//Knight has increased attack and defense.
		cout << "Robot Surfer\n\n";
		setName();
		system("pause");
	}
	void special(Monster& monst)
	{
		if (getSpclC() >= 100)
		{
			int choice;
			do
			{
				cout << "Which special would you like to use?"	//**
					<< "\n1)DEUS VULT: 75 DMG"					//Pick a special to use.
					<< "\n2)Prayer: +50 HP" << endl;			//**
				cin >> choice;
			} while (choice != 1 && choice != 2);

			if (choice == 1)
			{
				cout << "DEUS VULT!\n";
				monst.setHp(monst.getHp() - 75);		//Decrease monster health by 75.
				setSpclC(getSpclC() - 100);							//Special charge set to 0
			}
			else if (choice == 2)
			{
				cout << "Prayer\n";
				setHp(getHp() + 50);					//Heal player by 50 points
				setSpclC(getSpclC() - 100);							//Special charge set to 0.
			}
		}
		else
		{
			cout << "Special has not charged up yet!\n";
		}
		return;
	}
	void special(Player& play)
	{
		if (getSpclC() >= 100)
		{
			int choice;
			do
			{
				cout << "Which special would you like to use?"	//**
					<< "\n1)DEUS VULT: 75 DMG"					//Pick a special to use.
					<< "\n2)Prayer: +50 HP" << endl;			//**
				cin >> choice;
			} while (choice != 1 && choice != 2);

			if (choice == 1)
			{
				cout << "DEUS VULT!\n";
				play.setHp(play.getHp() - 75);		//Decrease monster health by 75.
				setSpclC(getSpclC() - 100);							//Special charge set to 0
			}
			else if (choice == 2)
			{
				cout << "Prayer\n";
				setHp(getHp() + 50);					//Heal player by 50 points
				setSpclC(getSpclC() - 100);							//Special charge set to 0.
			}
		}
		else
		{
			cout << "Special has not charged up yet!\n";
		}
		return;
	}

    void printAvatar() {

        string a1 = "  \\\\  // "; //dead
        string a2 = "   \\\\//  ";
        string a3 = "    /\\    ";
        string a4 = "   //\\\\  ";
        string a5 = "  //  \\\\ ";

        string c1 = "  _ []  | "; // robot surfer
        string c2 = " | |  ]\\| ";
        string c3 = " |_|/\\  | ";
        string c4 = "   ||||   ";
        string c5 = "   ^  ^   ";

        if (getDead() == true) {
            cout << a1 << endl;
            cout << a2 << endl;
            cout << a3 << endl;
            cout << a4 << endl;
            cout << a5 << endl;
        }

        if (getDead() == false) {
            cout << c1 << endl;
            cout << c2 << endl;
            cout << c3 << endl;
            cout << c4 << endl;
            cout << c5 << endl;
        }
    }
};
class Mage : public Player		   //------------------------------------------------------------------//Mage
{
public:
	Mage(): Player(180, 20, 10, 10, 100 )
	{
		//Mage has increased health and special attack.
		cout << "Double Pirate\n\n";
		setName();
		system("pause");
	}
	void special(Monster& monst)
	{
		int choice;
		if (getSpclC() >= 100)
		{
			do
			{
				cout << "Which special would you like to use?"
					<< "\n1)Frost Bolt: 75 DMG"				//Pick a special to use.
					<< "\n2)Heal: +50 HP" << endl;
				cin >> choice;
			} while (choice != 1 && choice != 2);

			if (choice == 1)
			{
				cout << "Frost Bolt!\n";
				monst.setHp(monst.getHp() - 75);		//Monster health is updated.
				setSpclC(getSpclC() - 100);							//Update special charge.
			}
			else if (choice == 2)
			{
				cout << "Healing 50 HP" << endl;
				setHp(getHp() + 50);				//Player health increased.
				setSpclC(getSpclC() - 100);						//Update special charge.
			}
		}
		else
		{
			cout << "Special has not charged up yet!\n";
		}
		return;
	}
	void special(Player& play)
	{
		int choice;
		if (getSpclC() >= 100)
		{
			do
			{
				cout << "Which special would you like to use?"
					<< "\n1)Frost Bolt: 75 DMG"				//Pick a special to use.
					<< "\n2)Heal: +50 HP" << endl;
				cin >> choice;
			} while (choice != 1 && choice != 2);

			if (choice == 1)
			{
				cout << "Frost Bolt!\n";
				play.setHp(play.getHp() - 75);		//Monster health is updated.
				setSpclC(getSpclC() - 100);							//Update special charge.
			}
			else if (choice == 2)
			{
				cout << "Healing 50 HP" << endl;
				setHp(getHp() + 50);				//Player health increased.
				setSpclC(getSpclC() - 100);						//Update special charge.
			}
		}
		else
		{
			cout << "Special has not charged up yet!\n";
		}
		return;
	}

    void printAvatar() {

string a1 = "  \\\\  // "; //dead
string a2 = "   \\\\//  ";
string a3 = "    /\\    ";
string a4 = "   //\\\\  ";
string a5 = "  //  \\\\ ";

string f1 = "    /\\  + "; // double pirate
string f2 = "   -xx- | ";
string f3 = "   /\\/\\_| ";
string f4 = "  /++++\\| ";
string f5 = " /++++++\\ ";

        if (getDead() == true) {
            cout << a1 << endl;
            cout << a2 << endl;
            cout << a3 << endl;
            cout << a4 << endl;
            cout << a5 << endl;
        }

        if (getDead() == false) {
            cout << f1 << endl;
            cout << f2 << endl;
            cout << f3 << endl;
            cout << f4 << endl;
            cout << f5 << endl;
        }
    }
};
class Paladin : public Player	   //------------------------------------------------------------------//Paladin
{
public:
	Paladin() : Player(100, 30, 10, 10, 100 )
	{
		//Paladin has increased attack and special attack.
		cout << "\nChad\n\n";
		setName();
		system("pause");
	}
	void special(Monster& monst)
	{
		int choose = 0;			//User's choice of special.
		if (getSpclC() >= 100)	//If special is charged up ( > 100)
		{
			do
			{
				cout << "Which special would you like to use?"
					<< "\n1)Crusader Strike: 75 DMG"				//Pick a special to use.
					<< "\n2)Blessing: +50 HP" << endl;
				cin >> choose;
			} while (choose != 1 && choose != 2);

			if (choose == 1)
			{
				cout << "Crusader Strike!" << endl;		//Crusader Strike deals 75 damage to enemy.
				monst.setHp(monst.getHp() - 75);		//Monster hp is updated.
				setSpclC(getSpclC() - 100);							//Reset special to 0.
			}
			else if (choose == 2)
			{
				cout << "Blessing" << endl;				//Blessing heals player by 50 hp.
				setHp(getHp() + 50);					//Player hp is updated.
				setSpclC(getSpclC() - 100);							//Reset special to 0.
			}
		}
		else
		{
			cout << "Special has not charged up yet!\n";
		}
		return;
	}
	void special(Player& play)
	{
		int choose = 0;			//User's choice of special.
		if (getSpclC() >= 100)	//If special is charged up ( > 100)
		{
			do
			{
				cout << "Which special would you like to use?"
					<< "\n1)Crusader Strike: 75 DMG"				//Pick a special to use.
					<< "\n2)Blessing: +50 HP" << endl;
				cin >> choose;
			} while (choose != 1 && choose != 2);

			if (choose == 1)
			{
				cout << "Crusader Strike!" << endl;		//Crusader Strike deals 75 damage to enemy.
				play.setHp(play.getHp() - 75);		//Monster hp is updated.
				setSpclC(getSpclC() - 100);							//Reset special to 0.
			}
			else if (choose == 2)
			{
				cout << "Blessing" << endl;				//Blessing heals player by 50 hp.
				setHp(getHp() + 50);					//Player hp is updated.
				setSpclC(getSpclC() - 100);							//Reset special to 0.
			}
		}
		else
		{
			cout << "Special has not charged up yet!\n";
		}
		return;
	}

    void printAvatar() {

        string a1 = "  \\\\  // "; // dead
        string a2 = "   \\\\//  ";
        string a3 = "    /\\    ";
        string a4 = "   //\\\\  ";
        string a5 = "  //  \\\\ ";

        string g1 = " ___<>  | "; // chad
		string g2 = " |+| +]\\| ";
        string g3 = " |+|/\\\\   ";
        string g4 = "   |  |   ";
        string g5 = "   ^  ^   ";

        if (getDead() == true) {
            cout << a1 << endl;
            cout << a2 << endl;
            cout << a3 << endl;
            cout << a4 << endl;
            cout << a5 << endl;
        }

        if (getDead() == false) {
            cout << g1 << endl;
            cout << g2 << endl;
            cout << g3 << endl;
            cout << g4 << endl;
            cout << g5 << endl;
        }
    }
};
class Rogue : public Player		    //------------------------------------------------------------------//Rogue
{
public:
	Rogue() : Player(150, 20, 10, 25, 100 )
	{
		//Increased health and speed.
		cout << "\nDramatic Child\n\n";
		setName();
		system("pause");
	}
	void special(Monster& monst)
	{
		int choose;
		if (getSpclC() >= 100)									//If special is charged up ( > 100).
		{
			do
			{
				cout << "Which special would you like to use?"		//Choose a special.
					<< "\n1)Assassination: 80 DMG"
					<< "\n2)Drink Booze: +25 HP" << endl;
				cin >> choose;
			} while (choose != 1 && choose != 2);

			if (choose == 1)										//Assasination deals 80 damage to monster.
			{
				cout << "Assasination!" << endl;
				monst.setHp(monst.getHp() - 80);
				setSpclC(getSpclC() - 100);										//Set special charge to 0.
			}
			else if (choose == 2)									//Booze heals 25 hp.
			{
				cout << "Drinking Booze" << endl;
				setHp(getHp() + 25);								//Add 25 points to HP
				setSpclC(getSpclC() - 100);										//Set special charge to 0.
			}
		}
		return;
	}
	void special(Player& play)
	{
		int choose;
		if (getSpclC() >= 100)									//If special is charged up ( > 100).
		{
			do
			{
				cout << "Which special would you like to use?"		//Choose a special.
					<< "\n1)Assassination: 80 DMG"
					<< "\n2)Drink Booze: +25 HP" << endl;
				cin >> choose;
			} while (choose != 1 && choose != 2);

			if (choose == 1)										//Assasination deals 80 damage to monster.
			{
				cout << "Assasination!" << endl;
				play.setHp(play.getHp() - 80);
				setSpclC(getSpclC() - 100);										//Set special charge to 0.
			}
			else if (choose == 2)									//Booze heals 25 hp.
			{
				cout << "Drinking Booze" << endl;
				setHp(getHp() + 25);								//Add 25 points to HP
				setSpclC(getSpclC() - 100);										//Set special charge to 0.
			}
		}
		return;
	}

    void printAvatar() {

        string a1 = "  \\\\  // "; // dead
        string a2 = "   \\\\//  ";
        string a3 = "    /\\    ";
        string a4 = "   //\\\\  ";
        string a5 = "  //  \\\\ ";

        string d1 = "   _-_   "; // dramatic child
        string d2 = "    O     ";
        string d3 = " \\/{ }\\/ ";
        string d4 = "   / \\    ";
        string d5 = "   | |    ";

        if (getDead() == true) {
            cout << a1 << endl;
            cout << a2 << endl;
            cout << a3 << endl;
            cout << a4 << endl;
            cout << a5 << endl;
        }

        if (getDead() == false) {
            cout << d1 << endl;
            cout << d2 << endl;
            cout << d3 << endl;
            cout << d4 << endl;
            cout << d5 << endl;
        }
    }
};
class Wizard : public Player	//------------------------------------------------------------------//Wizard
{
public:
	Wizard() : Player(100, 20, 25, 10, 100)
	{
		//Wizard has increased defense and special attack.
		cout << "Nerd\n\n";
		setName();
		system("pause");
	}
	void special(Monster& monst)
	{
		int choose = 0;			//User's choice of special.
		if (getSpclC() >= 100)	//If special is charged up (100)
		{
			do
			{
				cout << "Which special would you like to use?"
					<< "\n1)Lightning Bolt: 75 DMG"				//Pick a special to use.
					<< "\n2)Thunder: 100 DMG, -20 HP" << endl;
				cin >> choose;
			} while (choose != 1 && choose != 2);

			if (choose == 1)
			{
				cout << "Lightning bolt!" << endl;		//Lightning bolt does 75 damage (for example)
				monst.setHp(monst.getHp() - 75);		//Monster hp is updated.
				setSpclC(getSpclC() - 100);							//Reset special to 0.
			}
			else if (choose == 2)
			{
				cout << "Thunder!" << endl;				//Thunder does 100 damage but -20 to player using it.
				setHp(getHp() - 20);					//Player hp is updated.
				monst.setHp(monst.getHp() - 100);		//Monster hp is updated.
				setSpclC(getSpclC() - 100);							//Reset special to 0.
			}
		}
		else
		{
			cout << "Special has not charged up yet!\n";
		}
		return;
	}
	void special(Player& play)
	{
		int choose = 0;			//User's choice of special.
		if (getSpclC() >= 100)	//If special is charged up (100)
		{
			do
			{
				cout << "Which special would you like to use?"
					<< "\n1)Lightning Bolt: 75 DMG"				//Pick a special to use.
					<< "\n2)Thunder: 100 DMG, -20 HP" << endl;
				cin >> choose;
			} while (choose != 1 && choose != 2);

			if (choose == 1)
			{
				cout << "Lightning bolt!" << endl;		//Lightning bolt does 75 damage (for example)
				play.setHp(play.getHp() - 75);		//Monster hp is updated.
				setSpclC(getSpclC() - 100);							//Reset special to 0.
			}
			else if (choose == 2)
			{
				cout << "Thunder!" << endl;				//Thunder does 100 damage but -20 to player using it.
				setHp(getHp() - 20);					//Player hp is updated.
				play.setHp(play.getHp() - 100);		//Monster hp is updated.
				setSpclC(getSpclC() - 100);							//Reset special to 0.
			}
		}
		else
		{
			cout << "Special has not charged up yet!\n";
		}
		return;
	}

    void printAvatar() {

        string a1 = "  \\\\  // "; //dead
        string a2 = "   \\\\//  ";
        string a3 = "    /\\    ";
        string a4 = "   //\\\\  ";
        string a5 = "  //  \\\\ ";

        string e1 = "    /\\  o "; // nerd
        string e2 = "   -oo- | ";
        string e3 = "   /\\/\\_| ";
        string e4 = "  /    \\| ";
        string e5 = " /      \\ ";

        if (getDead() == true) {
            cout << a1 << endl;
            cout << a2 << endl;
            cout << a3 << endl;
            cout << a4 << endl;
            cout << a5 << endl;
        }

        if (getDead() == false) {
            cout << e1 << endl;
            cout << e2 << endl;
            cout << e3 << endl;
            cout << e4 << endl;
            cout << e5 << endl;
        }
    }
};
