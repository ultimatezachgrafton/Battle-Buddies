// Item.h header file defines the Item class and its sub classes.

#pragma once
#include <iostream>
#include <string>

class Item
{
protected:
	std::string itemName;
	int hpChange;
	int attackChange;
	int defenseChange;
	int speedChange;
	int specialChange;
	int itemRarity;

public:
	//------------------------------------------------------------------//
	//Constructors            											//
	//------------------------------------------------------------------//
	Item() {}//default constructor

	Item(std::string aItemName, int hp, int atkC, int defC, int spdC, int splC, int rarity) //constructor with initializers
	{
		itemName = aItemName;
		hpChange = hp;
		attackChange = atkC;
		defenseChange = defC;
		speedChange = spdC;
		specialChange = splC;
		itemRarity = rarity;
	}

	~Item() {} //destructor
			   //------------------------------------------------------------------//
			   //Setters and Getters												//
			   //------------------------------------------------------------------//
	void setName(std::string aName) { itemName = aName; }
	void setHP(int hp) { hpChange = hp; }
	void setAtk(int atkC) { attackChange = atkC; }
	void setDef(int defC) { defenseChange = defC; }
	void setSpd(int spdC) { speedChange = spdC; }
	void setSpl(int splC) { specialChange = splC; }
	void setRarity(int rarity) { itemRarity = rarity; }

	std::string getName() const { return itemName; }
	int getHp() const { return hpChange; }
	int getAtk() const { return attackChange; }
	int getDef() const { return defenseChange; }
	int getSpd() const { return speedChange; }
	int getSpl() const { return specialChange; }
	int getRarity() const { return itemRarity; }

	void print();

}; // end of class Item

void Item::print()
{
	std::cout << "Item Name: " << getName() << "\n";
	std::cout << "hp: " << hpChange << "\n";
	std::cout << "attack: " << attackChange << "\n";
	std::cout << "defense: " << defenseChange << "\n";
	std::cout << "speed: " << speedChange << "\n";
	std::cout << "special: " << specialChange << "\n\n";
}

//*****************//
//POTION CLASS     //
//*****************//
class Potion : public Item
{
private:
	//inherited from base class
public:
	Potion() //default constructor, ADDS +25 TO PLAYER HP
	{
		itemName = "Potion";
		hpChange = 25;
		attackChange = 0;
		defenseChange = 0;
		speedChange = 0;
		specialChange = 0;
		itemRarity = 0;
	}

	~Potion() {} //destructor
};

//*****************//
//MID-POTION CLASS  //
//*****************//
class MidPotion : public Item
{
private:
	//inherited from base class
public:
	MidPotion() //default constructor, ADDS +50 TO PLAYER HP
	{
		itemName = "Midpotion";
		hpChange = 50;
		attackChange = 0;
		defenseChange = 0;
		speedChange = 0;
		specialChange = 0;
		itemRarity = 0;
	}

	~MidPotion() {} //destructor
};

//*****************//
//HIGH-POTION CLASS//
//*****************//
class HighPotion : public Item
{
private:
	//inherited from base class
public:
	HighPotion() //default constructor, ADDS +75 TO PLAYER HP
	{
		itemName = "Highpotion";
		hpChange = 75;
		attackChange = 0;
		defenseChange = 0;
		speedChange = 0;
		specialChange = 0;
		itemRarity = 0;
	}

	~HighPotion() {} //destructor
};

//*****************//
//HARDEN CLASS     //
//*****************//
class Harden : public Item
{
private:
	//Inherited from base class
public:
	Harden() //default constructor, ADDS +3 TO PLAYER DEFENSE
	{
		itemName = "Harden";
		hpChange = 0;
		attackChange = 0;
		defenseChange = 3;
		speedChange = 0;
		specialChange = 0;
		itemRarity = 0;
	}

	~Harden() {} //destructor
};

//*****************//
//REVIVE CLASS     //
//*****************//
class Revive : public Item
{
private:
	//Inherited from base class
public:
	Revive() //default constructor
	{
		itemName = "Revive";
		hpChange = 100;
		attackChange = 0;
		defenseChange = 0;
		speedChange = 0;
		specialChange = 0;
		itemRarity = 0;
	}

	~Revive() {} //destructor
};

//*****************//
//HYPER CLASS      //
//*****************//
class Hyper : public Item
{
private:
	//Inherited from base class
public:
	Hyper() //default constructor, ADDS +3 SPEED TO PLAYER SPEED STAT
	{
		itemName = "Hyper";
		hpChange = 0;
		attackChange = 0;
		defenseChange = 0;
		speedChange = 3;
		specialChange = 0;
		itemRarity = 0;
	}

	~Hyper() {} //destructor
};

//*****************//
//FIREBOMB CLASS   //
//*****************//
class FireBomb : public Item
{
private:
	//Inherited from base class
public:
	FireBomb() //default constructor, SUB -15 ATK DAMAGE FROM MONSTER'S HP
	{
		itemName = "Firebomb";
		hpChange = -15;
		attackChange = 0;
		defenseChange = 0;
		speedChange = 0;
		specialChange = 0;
		itemRarity = 0;
	}

	~FireBomb() {} //destructor 
};

//*****************//
//BERSERK CLASS    //
//*****************//
class Berserk : public Item
{
private:
	//Inherited from base class
public:
	Berserk() //default constructor, INCREASE PLAYER'S ATK DAMAGE BY 10
	{
		itemName = "Berserk";
		hpChange = 0;
		attackChange = 10;
		defenseChange = 0;
		speedChange = 0;
		specialChange = 0;
		itemRarity = 0;
	}

	~Berserk() {} //destructor	
};

//*****************//
//SMOKEBOMB CLASS  //
//*****************//
class SmokeBomb : public Item
{
private:
	//Inherited from base class
public:
	SmokeBomb() //default constructor, SUB -3 FROM MONSTER'S SPEED STAT
	{
		itemName = "Smokebomb";
		hpChange = 0;
		attackChange = 0;
		defenseChange = 0;
		speedChange = -3;
		specialChange = 0;
		itemRarity = 0;
	}

	~SmokeBomb() {} //destructor
};
