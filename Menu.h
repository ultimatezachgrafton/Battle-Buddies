// Menu header file defines the Battle Buddies RPG fighting program

#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h> // srand() and rand()
#include "Player.h"
#include "Monster.h"
#include "Item.h"

class Menu {
private:
	int select = 0;
	bool flag = true;
	int difficulty = 2;
	Player *playarr[2];
	Monster monstarr[5];
	int playerPool;  // Number of player characters in party
	int monsterPool; // Number of monsters in fight
	int deadCount = 0;
	int playerDeadCount = 0;

public:
	Menu() { mainMenu(); }
	void mainMenu();
	void battleStart();
	void characterSelect();
	void setMonster();
	void fight();
	void turn(Player& p, Monster m);  // function for rotating between player and monster turns
	void deathCheck(Player &p);
	void deathCheck(Monster &m);
	void deathCheck(Monster &m, Player &p);

	//-----------Getters / Setters-------------//

	void setDifficulty(int x) { difficulty = x; }
	void setPlayerPool(int x) { playerPool = x; }
	void setMonsterPool(int x) { monsterPool = x; }
	void setPlayarr(Player *x, Player *y, Player *z) { playarr[0] = x; playarr[1] = y; }
	void setMonstarr() {}
	void setMonstarr(Monster a) { monstarr[0] = a; }
	void setMonstarr(Monster a, Monster b) { monstarr[0] = a; monstarr[1] = b; }
	void setMonstarr(Monster a, Monster b, Monster c) { monstarr[0] = a; monstarr[1] = b; monstarr[2] = c; }
	void setMonstarr(Monster a, Monster b, Monster c, Monster d) { monstarr[0] = a; monstarr[1] = b; monstarr[2] = c; monstarr[3] = d; }
	void setMonstarr(Monster a, Monster b, Monster c, Monster d, Monster e) { monstarr[0] = a; monstarr[1] = b; monstarr[2] = c; monstarr[3] = d; monstarr[4] = e; }
	void setDeadCount(int x) { deadCount = x; }
	void setPlayerDeadCount(int x) { playerDeadCount = x; }
	void incrementDead() { deadCount++; }
	void incrementPlayerDead() { playerDeadCount++; }

	int getDifficulty() { return difficulty; }
	int getPlayterPool() { return playerPool; }
	int getMonsterPool() { return monsterPool; }
	int getDeadCount() { return deadCount; }
	int getPlayerDeadCount() { return playerDeadCount; }

};

void Menu::mainMenu() {
	while (flag == true) {
        std::cout << string(200, '\n');
		std::cout << "Buddy Battles\n\n\n";
		std::cout << "MENU" << std::endl;
		while (select < 1 || select > 4) {
			std::cout << "1) New Game" << std::endl;
			std::cout << "2) Exit" << std::endl;

			std::cin >> select;

			if (select < 1 || select > 2) {
				std::cout << "That is not a valid input" << std::endl;
			}
			if (select == 1) {
				battleStart();
			}

			if (select == 2) {
				flag = false;
			}
		}
	}
}

void Menu::battleStart() {
	std::cout << string(200, '\n');
	int select = 0;

	std::cout << "Please select a dificulty:" << std::endl;
	std::cout << "1) Easy" << std::endl;
	std::cout << "2) Normal" << std::endl;
	std::cout << "3) Hard" << std::endl;

	while (select > 3 || select < 1) {
		cin >> select;
		if (select > 3 || select < 1) {
			std::cout << "That is not a valid input" << std::endl;
		}
		if (select == 1) {
			difficulty = 1;
		}
		if (select == 2) {
			difficulty = 2;
		}
		if (select == 3) {
			difficulty = 3;
		}

	}
	characterSelect();
}

void Menu::characterSelect() {
	std::cout << string(200, '\n');

	select = 0;
	std::cout << "Select two warriors to fight:" << std::endl << std::endl;

	for (int i = 0; i < 2; i++) {
		while (select > 6 || select < 1) {

			std::cout << "1) Soup Kitchen Volunteer" << std::endl;
			std::cout << "2) Robot Surfer" << std::endl;
			std::cout << "3) Nerd" << std::endl;
			std::cout << "4) Chad" << std::endl;
			std::cout << "5) Dramatic Child" << std::endl;
			std::cout << "6) Double Pirate" << std::endl;

			std::cin >> select;

			if (select > 6 || select < 1) {
				std::cout << "Try again." << std::endl;
			}
			if (select == 1) {
				std::cin.ignore();
				playarr[i] = new Mercenary;
			}
			if (select == 2) {
				std::cin.ignore();
				playarr[i] = new Knight;
			}
			if (select == 3) {
				std::cin.ignore();
				playarr[i] = new Mage;
			}
			if (select == 4) {
				std::cin.ignore();
				playarr[i] = new Paladin;
			}
			if (select == 5) {
				std::cin.ignore();
				playarr[i] = new Rogue;
			}
			if (select == 6) {
				std::cin.ignore();
				playarr[i] = new Wizard;
			}
		}
		select = 0;
		std::cout << string(200, '\n');
	}
	playerPool = 2;
	fight();
}

void Menu::fight() {
	bool turnDone = false;

	while (playerPool > 0 || monsterPool > 0) {
		int temp = 0;

		setMonster();

		std::cout << std::string(200, '\n');
		std::cout << "You are attacked by: " << std::endl;

		for (int i = 0; i < monsterPool; i++) {
			std::cout << monstarr[i].printAvatar() << std::endl;
			std::cout << "[1] " << monstarr[i].getName() << std::endl;
		}

		system("pause");
		std::cout << std::string(200, '\n');
		while (playerPool > 0 && monsterPool > 0) {

			for (int i = 100; i >= 0; i--) {  //turn timer vs speed

				for (int j = 0; j < playerPool; j++) { //*playarr speed test
					if (playarr[j]->getSpd() == i && playarr[j]->getDead() == false) {
						select = 0;



						while (turnDone == false) {
							playarr[j]->printAvatar();
							std::cout << playarr[j]->getName() << std::endl;
							std::cout << "HP: " << playarr[j]->getHp() << std::endl << std::endl;
							std::cout << "1) ATTACK" << std::endl;
							std::cout << "2) DEFEND" << std::endl;
							std::cout << "3) SPECIAL <" << playarr[j]->getSpclC() << " / 100>" << std::endl;
							std::cout << "4) ITEM" << std::endl;
							//std::cout << "5) SAVE / QUIT" << std::endl;

							std::cin >> select;

							if (select == 1) {  //ATTACK
								select = 0;

								std::cout << "Choose a target" << std::endl << std::endl;

								for (int i = 0; i < monsterPool; i++) {   //glitch comes back here
									std::cout << i + 1 << ") " << monstarr[i].getName() << "  HP: " << monstarr[i].getHp() << std::endl;
									temp++;
								}

								for (int i = 0; i < playerPool; i++) {
									std::cout << i + monsterPool + 1 << ") " << playarr[i]->getName() << "  HP: " << playarr[i]->getHp() << std::endl;
									temp++;
								}

								while (select < 1 || select > temp) {
									std::cin >> select;

									if (select >= 1 && select <= temp) {
										if (select <= monsterPool) {
											playarr[j]->attacking(monstarr[select - 1]);
											if(monstarr[select - 1].getDead() == false) {
                                                deathCheck(monstarr[select - 1], *playarr[j]);
											}
										}
                                        if(select > monsterPool) {
                                            playarr[j]->attacking(*playarr[select - 1- monsterPool]);
                                            if(playarr[select - 1 - monsterPool]->getDead() == false) {
                                                deathCheck(*playarr[select - 1 - monsterPool]);
                                            }

                                        }
									}
									if (select < 1 || select > temp) {
										std::cout << "Please select a target";
									}
								}
								playarr[j]->incrementSpecial();
								temp = 0;
								select = 0;
								turnDone = true;
							}

							if (select == 2) {  //DEFEND
								playarr[j]->passTurn();

								std::cout << playarr[j]->getName() << " defended and gained some health\n\n";
								system("pause");
								select = 0;
								turnDone = true;
							}

							if (select == 3) {  //SPECIAL
								select = 0;

								for (int i = 0; i < monsterPool; i++) {
									std::cout << i + 1 << ") " << monstarr[i].getName() << "  HP: " << monstarr[i].getHp() << std::endl;
									temp++;
								}

								for (int i = 0; i < playerPool; i++) {
									std::cout << i + monsterPool + 1 << ") " << playarr[i]->getName() << "  HP: " << playarr[i]->getHp() << std::endl;
									temp++;
								}

								while (select < 1 || select > temp) {
									std::cin >> select;

									if (select >= 1 && select <= temp) {
										if (select <= monsterPool) {
											Player *ptemp = playarr[j];
											playarr[j]->special(monstarr[select - 1]);
											if(monstarr[select - 1].getDead() == false) {
                                                deathCheck(monstarr[select - 1], *playarr[j]);
											}
											else {
                                                monstarr[select - 1].setHp(0);
											}

											std::cout << std::string(200, '\n');
										}
										else {
                                            std::cout << (select - 1 - monsterPool) << endl;
											playarr[j]->special(*playarr[select - 1 - monsterPool]);
											if(playarr[select - 1 - monsterPool]->getDead() == false) {
                                                deathCheck(*playarr[select - 1 - monsterPool]);
											}
											else {
                                                playarr[select - 1 - monsterPool]->setHp(0);
											}

										}
									}
									if (select < 1 || select > temp) {
										std::cout << "Please select a target";
									}
								}

								temp = 0;
								select = 0;
								turnDone = true;
								std::cin.clear();
							}

							if (select == 4) {  //ITEM
								select = 0;

								std::cout << "Choose a target" << std::endl << std::endl;

								for (int i = 0; i < monsterPool; i++) {
									std::cout << i + 1 << ") " << monstarr[i].getName() << "  HP: " << monstarr[i].getHp() << std::endl;
									temp++;
								}

								for (int i = 0; i < playerPool; i++) {
									std::cout << i + monsterPool + 1 << ") " << playarr[i]->getName() << "  HP: " << playarr[i]->getHp() << std::endl;
									temp++;
								}

								while (select < 1 || select > temp) {
									std::cin >> select;

									if (select >= 1 && select <= temp) {
										if (select <= monsterPool) {
											playarr[j]->useItem(monstarr[select-1]);
											if(monstarr[select - 1].getDead() == false) {
                                                deathCheck(monstarr[select - 1]);
											}

										}
										else {
											playarr[j]->useItem(*playarr[select - 1 - monsterPool]);
											if(playarr[select - 1 - monsterPool]->getDead() == false) {
                                                deathCheck(*playarr[select - 1 - monsterPool]);
											}
										}
									}
									if (select < 1 || select > temp) {
										std::cout << "Please select a target";
									}
								}

								temp = 0;
								select = 0;
								turnDone = true;
								std::cin.clear();
							}
							std::cout << std::string(200, '\n');
						}
						turnDone = false;

						for (int i = 0; i < monsterPool; i++) {
							if (deadCount == monsterPool) {
								std::cout << "You win!" << std::endl;
								difficulty++;
								std::cout << "Difficulty set  to " << getDifficulty() << std::endl;
								setDeadCount(0);
								system("pause");
								fight();
							}
						}
					}
				}
				for (int i = 0; i < playerPool; i++) {   //lose check after player turn
					if (playerDeadCount == playerPool) {
						std::cout << "You Lose!" << std::endl;
						system("pause");
						playerDeadCount = 0;
						mainMenu();
					}
				}


				for (int k = 0; k < monsterPool; k++) { //monstarr speed test
					if (monstarr[k].getSpd() == i) {
						if (monstarr[k].getDead() == false) {
							monstarr[k].printAvatar();
							std::cout << monstarr[k].getName() << " Attacks!" << std::endl << std::endl;

                            bool turnTemp = false;
                            while(turnTemp == false) {
							int playerPool = rand() % 3;
                                if(playarr[playerPool]->getDead() == false) {
                                    turn(*playarr[playerPool], monstarr[k]);
                                    turnTemp = true;
                                }
                            }



						}
					}
				}
				for (int i = 0; i < playerPool; i++) {  //lose check after monster turn
					if (playerDeadCount == playerPool) {
						std::cout << "You Lose!" << std::endl;
						system("pause");
						playerDeadCount = 0;
						mainMenu();
					}
				}
			}
		}
	}
}

void Menu::setMonster() {
	srand(time(NULL));
	int ratingPool;

	switch (difficulty) {
	case 1:
		ratingPool = rand() % 10;

		if (ratingPool == 0 || ratingPool == 1) {
			Slime a, b, c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 2 || ratingPool == 3) {
			Slime a, b;
			Imp c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 4 || ratingPool == 5) {
			Spider a, b;
			setMonstarr(a, b);
			monsterPool = 2;
		}
		if (ratingPool == 6 || ratingPool == 7) {
			Spider a;
			Imp b;
			Slime c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 8 || ratingPool == 9) {
			Ghoul a;
			setMonstarr(a);
			monsterPool = 1;
		}
		break;
	case 2:
    ratingPool = 10 + (rand() % 10);
		if (ratingPool == 10 || ratingPool == 11) {
			Imp a, b, c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 12 || ratingPool == 13) {
			Imp a, b;
			Spider c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 14 || ratingPool == 15) {
			Ghoul a, b;
			setMonstarr(a, b);
			monsterPool = 2;
		}
		if (ratingPool == 16 || ratingPool == 17) {
			Imp a;
			Spider b;
			Ghoul c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 18 || ratingPool == 19) {
			Skeleton a;
			setMonstarr(a);
			monsterPool = 1;
		}
		break;
	case 3:
    ratingPool = 20 +  (rand() % 10);
		if (ratingPool == 20 || ratingPool == 21) {
			Spider a, b, c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 22 || ratingPool == 23) {
			Spider a, b;
			Ghoul c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 24 || ratingPool == 25) {
			Skeleton a, b;
			setMonstarr(a, b);
			monsterPool = 2;
		}
		if (ratingPool == 26 || ratingPool == 27) {
			Spider a;
			Ghoul b;
			Skeleton c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 28 || ratingPool == 29) {
			Zombie a;
			setMonstarr(a);
			monsterPool = 1;
		}
		break;
	case 4:
    ratingPool = 30 + (rand() % 10);
		if (ratingPool == 30 || ratingPool == 31) {
			Ghoul a, b, c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 32 || ratingPool == 33) {
			Ghoul a, b;
			Skeleton c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 34 || ratingPool == 35) {
			Zombie a, b;
			setMonstarr(a, b);
			monsterPool = 2;
		}
		if (ratingPool == 36 || ratingPool == 37) {
			Ghoul a;
			Skeleton b;
			Zombie c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 38 || ratingPool == 39) {
			Goblin a;
			setMonstarr(a);
			monsterPool = 1;
		}
		break;
	case 5:
    ratingPool = 40 + (rand() % 10);
		if (ratingPool == 40 || ratingPool == 41) {
			Skeleton a, b, c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 42 || ratingPool == 43) {
			Skeleton a, b;
			Zombie c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 44 || ratingPool == 45) {
			Goblin a, b;
			setMonstarr(a, b);
			monsterPool = 2;
		}
		if (ratingPool == 46 || ratingPool == 47) {
			Skeleton a;
			Zombie b;
			Goblin c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 48 || ratingPool == 49) {
			Thief a;
			setMonstarr(a);
			monsterPool = 1;
		}
		break;
	case 6:
    ratingPool = 50 + (rand() % 10);
		if (ratingPool == 50 || ratingPool == 51) {
			Zombie a, b, c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 52 || ratingPool == 53) {
			Zombie a, b;
			Goblin c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 54 || ratingPool == 55) {
			Thief a, b;
			setMonstarr(a, b);
			monsterPool = 2;
		}
		if (ratingPool == 56 || ratingPool == 57) {
			Zombie a;
			Goblin b;
			Thief c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 58 || ratingPool == 59) {
			Assassin a;
			setMonstarr(a);
			monsterPool = 1;
		}
		break;
	case 7:
    ratingPool = 60 + (rand() % 10);
		if (ratingPool == 60 || ratingPool == 61) {
			Goblin a, b, c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 62 || ratingPool == 63) {
			Goblin a, b;
			Thief c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 64 || ratingPool == 65) {
			Assassin a, b;
			setMonstarr(a, b);
			monsterPool = 2;
		}
		if (ratingPool == 66 || ratingPool == 67) {
			Goblin a;
			Thief b;
			Assassin c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 68 || ratingPool == 69) {
			Berserker a;
			setMonstarr(a);
			monsterPool = 1;
		}
		break;
	case 8:
    ratingPool = 70 + (rand() % 10);
		if (ratingPool == 70 || ratingPool == 71) {
			Thief a, b, c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 72 || ratingPool == 73) {
			Thief a, b;
			Assassin c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 74 || ratingPool == 75) {
			Berserker a, b;
			setMonstarr(a, b);
			monsterPool = 2;
		}
		if (ratingPool == 76 || ratingPool == 77) {
			Thief a;
			Assassin b;
			Berserker c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 78 || ratingPool == 79) {
			DarkFanatic a;
			setMonstarr(a);
			monsterPool = 1;
		}
		break;
	case 9:
    ratingPool = 80 + (rand() % 10);
		if (ratingPool == 80 || ratingPool == 81) {
			Assassin a, b, c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 82 || ratingPool == 83) {
			Assassin a, b;
			Berserker c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 84 || ratingPool == 85) {
			DarkFanatic a, b;
			setMonstarr(a, b);
			monsterPool = 2;
		}
		if (ratingPool == 86 || ratingPool == 87) {
			Assassin a;
			Berserker b;
			DarkFanatic c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 88 || ratingPool == 89) {
			DarkWarrior a;
			setMonstarr(a);
			monsterPool = 1;
		}
		break;
	case 10:
    ratingPool = 90 + (rand() % 10);
		if (ratingPool == 90 || ratingPool == 91) {
			Berserker a, b, c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 92 || ratingPool == 93) {
			Berserker a, b;
			DarkFanatic c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 94 || ratingPool == 95) {
			DarkWarrior a, b;
			setMonstarr(a, b);
			monsterPool = 2;
		}
		if (ratingPool == 96 || ratingPool == 97) {
			Berserker a;
			DarkFanatic b;
			DarkWarrior c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 98 || ratingPool == 99) {
			DarkKnight a;
			setMonstarr(a);
			monsterPool = 1;
		}
		break;
	case 11:
    ratingPool = 100 + (rand() % 10);
		if (ratingPool == 100 || ratingPool == 101) {
			DarkFanatic a, b, c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 102 || ratingPool == 103) {
			DarkFanatic a, b;
			DarkWarrior c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 104 || ratingPool == 105) {
			DarkKnight a, b;
			setMonstarr(a, b);
			monsterPool = 2;
		}
		if (ratingPool == 106 || ratingPool == 107) {
			DarkFanatic a;
			DarkWarrior b;
			DarkKnight c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 108 || ratingPool == 109) {
			Singh a;
			setMonstarr(a);
			monsterPool = 1;
		}
		break;
	case 12:
    ratingPool = 110 + (rand() % 10);
		if (ratingPool == 110 || ratingPool == 111) {
			DarkWarrior a, b, c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 112 || ratingPool == 113) {
			DarkWarrior a, b;
			DarkKnight c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 114 || ratingPool == 115) {
			Singh a, b;
			setMonstarr(a, b);
			monsterPool = 2;
		}
		if (ratingPool == 116 || ratingPool == 117) {
			DarkWarrior a;
			DarkKnight b;
			Singh c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 118 || ratingPool == 119) {
			Singh a, b;
			DarkKnight c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		break;
	case 13:
    ratingPool = 120 + (rand() % 10);
		if (ratingPool == 120 || ratingPool == 121) {
			DarkKnight a, b, c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 122 || ratingPool == 123) {
			DarkKnight a, b;
			Singh c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 124 || ratingPool == 125) {
			Singh a, b;
			DarkKnight c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 126 || ratingPool == 127) {
			DarkKnight a;
			Singh b, c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 128 || ratingPool == 129) {
			Singh a, b;
			DarkKnight c, d;
			setMonstarr(a, b, c, d);
			monsterPool = 4;
		}
		break;
	case 14:
    ratingPool = 130 + (rand() % 10);
		if (ratingPool == 130 || ratingPool == 131) {
			Singh a, b, c;
			setMonstarr(a, b, c);
			monsterPool = 3;
		}
		if (ratingPool == 132 || ratingPool == 133) {
			Singh a, b;
			DarkKnight c, d;
			setMonstarr(a, b, c, d);
			monsterPool = 4;
		}
		if (ratingPool == 134 || ratingPool == 135) {
			Singh a, b;
			DarkKnight c;
			DarkWarrior d;
			setMonstarr(a, b, c, d);
			monsterPool = 4;
		}
		if (ratingPool == 136 || ratingPool == 137) {
			Singh a, b;
			DarkKnight c, d;
			DarkWarrior e;
			setMonstarr(a, b, c, d, e);
			monsterPool = 5;
		}
		if (ratingPool == 138 || ratingPool == 139) {
			Singh a, b, c;
			DarkKnight d;
			Slime e;
			setMonstarr(a, b, c, d, e);
			monsterPool = 5;
		}
		break;
	}
}

void Menu::turn(Player& p, Monster m) {
	// monster targets random player as decided in Menu
	if (m.getDead() == false) {
		if (m.getSpclM() < 100) { // if special meter is not full, monster uses regular attack
			std::cout << m.getName() << " attacks " << p.getName() << std::endl << std::endl;
			// damage calculated as monster's atk minus player's def
			int dmg = m.getAtk() - p.getDef();
			if (dmg <= 0) {
				std::cout << p.getName() << " blocks!\n";
				p.block(m);
			}
			else {
				p.setHp(p.getHp() - dmg);
				std::cout << p.getName() << " takes " << dmg << " damage!\n\n";
			}
			deathCheck(p);
		}
		else { // if special charge is full, monster uses special attack
			   // damage calculated as monster's damage * 1.5; no defense factored in
			int dmg = m.getAtk() * 1.5;
			std::cout << m.getName() << " uses " << m.getSpclN() << "!\n";
			int t = p.getHp() - dmg;
			p.setHp(t);
			std::cout << p.getName() << " takes " << dmg << " damage!\n";
			m.setSpclC(0);
			deathCheck(p);
		}


		m.setSpclC(m.getSpclM() + m.getSpclC());

		std::cout << std::string(200, '\n');

	}
}

void Menu::deathCheck(Player &p) {
    if(p.getHp() <= 0) {
        std::cout << "***************************" << std::endl;
        std::cout << p.getName() << " has died" << std::endl;
        std::cout << "***************************" << std::endl;
        p.setDead(true);
        incrementPlayerDead();
    }

    system("pause");
}

void Menu::deathCheck(Monster &m) {
	if (m.getHp() <= 0) {
        std::cout << "***************************" << std::endl;
		std::cout << m.getName() << " has died" << std::endl;
        std::cout << "***************************" << std::endl;
		m.setDead(true);
		incrementPlayerDead();
	}

	system("pause");
}

void Menu::deathCheck(Monster &m, Player &p) {
	if (m.getHp() <= 0) {
        std::cout << "***************************" << std::endl;
		std::cout << m.getName() << " has died" << std::endl;
        std::cout << "***************************" << std::endl;
		m.setDead(true);
		incrementDead();

		Item* xItem = nullptr;
		Item yItem;
		int randNum;

		vector<Item*> listOfItems; //create vector for holding all types of items
		listOfItems.push_back(new Potion); //populate vector with all types of items
		listOfItems.push_back(new MidPotion);
		listOfItems.push_back(new HighPotion);
		listOfItems.push_back(new Harden);
		listOfItems.push_back(new Revive);
		listOfItems.push_back(new Hyper);
		listOfItems.push_back(new FireBomb);
		listOfItems.push_back(new Berserk);
		listOfItems.push_back(new SmokeBomb);

		srand(time(NULL)); //seed rand() with time
		randNum = rand() % 8 + 0; //randomizing the numbers 0 through 8 (0-8 represents vector index for listOfItems)

		xItem = listOfItems.at(randNum); //assign vector element to x

		yItem = *xItem; // dereference and assign item object
		p.addToInventory(yItem);
		listOfItems.clear(); // clear vector elements to deallocate memory
	}

	system("pause");
}
