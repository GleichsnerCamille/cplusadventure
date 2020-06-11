#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <Lmcons.h>
#include <fstream>
#include <algorithm>
#include "Weapon.h"
#include "Monster.h"
#include "Player.h"
#include "Combat.h"

#define sleep Sleep(1500);
#define rest Sleep(1000);
#define typing Sleep(100);
#define clear system("CLS");
#define endL cout << endl;

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//Weapon Declares
Weapon BattleAxe("Battle Axe", "Heavy", "Melee", "Slashing", 10, 12);
Weapon Spear("Spear", "Light", "Melee", "Piercing", 15, 10);
Weapon Sword("Sword", "Light", "Melee", "Slashing", 12, 10);
Weapon Warhammer("War Hammer", "Heavy", "Melee", "Blundeoning", 15, 12);
Weapon Bow("Hunter's Bow", "Light", "Ranged", "Piercing", 50, 8);
Weapon Staff("Wizard's Staff", "Magical", "Magic", "Burning", 20, 8);

//Monster Declares
Monster Skeleton("Skeleton", 10, 3, Bow, Bow.getDMGDice(), "Slashing");
Monster Goblin("Goblin", 12, 5, Sword, Sword.getDMGDice(), "Burning");
Monster Minotaur("Minotaur", 20, 6, Warhammer, Warhammer.getDMGDice(), "Piercing");
Monster Ghost("Ghost", 8, 17, Bow, Bow.getDMGDice(), "Blundeoning");
Monster mBarbarian("Barbarian", 35, 7, BattleAxe, BattleAxe.getDMGDice(), "Slashing");
Monster mWizard("Wizard", 23, 16, Staff, Staff.getDMGDice(), "Burning");
Monster LackofTime("Cor, of Ana", 40, 15, Spear, Spear.getDMGDice(), "Piercing");

//Player Declares
Player Soldier("Soldier", "Fighter", 25, 10, Sword, Sword.getDMGDice(), 0);
Player Barbarian("Barbarian", "Old World", 20, 15, Warhammer, Warhammer.getDMGDice(), 0);
Player Wizard("Wizard", "Spell Caster", 15, 13, Staff, Staff.getDMGDice(), 0);
Player Rogue("Rogue", "Lawless", 10, 18, Spear, Spear.getDMGDice(), 0);
Player Bard("Bard", "Fool", 20, 12, Spear, Spear.getDMGDice(), 0);

//Gameplay Calls
Player thePlayer("","",0,0,Sword, Sword.getDMGDice(), 0);



//Table of Contents 
void type(string word); 
void loading();
void intro();
string getUser();
string upper(string word);
void gameStart();
void gameOver();
void roomB1(Player thePlayer);
void roomB2(Player thePlayer);
void roomB3(Player thePlayer);
void roomC1(Player thePlayer);
void roomC2(Player thePlayer);
void roomC3(Player thePlayer);
void roomC4(Player thePlayer);
void roomD1(Player thePlayer);
void roomD2(Player thePlayer);
void roomD3(Player thePlayer);
void roomE1(Player thePlayer);
void roomE2(Player thePlayer);
void roomE3(Player thePlayer);
void roomF1(Player thePlayer);
void roomF2(Player thePlayer);
void roomF3(Player thePlayer);
void gameEnd(Player thePlayer);


//exit game
void gameOver() { 
	clear
	cout << ("\n\n						Game Over\n\n\n"); sleep
	exit(0);
}

//Typing aesthetic 
void type(string word) {
	for (int i = 0; i < word.length(); i++) {
		cout << word[i]; typing
	}
}

//Loading aesthetic 
void loading() {
	string load = "LOADING...";
	for (int e = 0; e < 3; e++) {
		type(load);
		rest clear
	}
}

//Uppercase the answer
string upper(string word) {
	transform(word.begin(), word.end(), word.begin(), toupper);
	return word;
}

//Color change 
void color(int value) {
	SetConsoleTextAttribute(hConsole, value);
}

//Get Windows Username
string getUser() {
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);
	return username;
}

//Random Number
int rollD(int dice) {
	int result; 
	result = rand() % dice + 1; 
	return result; 
}

//Intro of the Game 
void intro() {
	string inMenu;
	color(2);
	loading();
	type("USER DETECTED... "); sleep endL
	cout << "LOAD: USER INFORMATION"; typing endL
	type("BOOT SYSTEM MOCK UP #176"); sleep clear
	type("HELLO "); sleep
	type(getUser()); sleep endL
	type("PLEASE ENTER THE TERM START TO BEGIN: "); typing
	cin >> inMenu;
	inMenu = upper(inMenu);
	if (inMenu == "START") {
			clear sleep 
			gameStart();
	}
}

//Start of game
void gameStart() {
	int input = 1;
	type("Its cold. So...."); clear sleep
	type("Cold."); sleep  sleep clear 
	type("And Dark. Oh... perhaps you should open your eyes? \nYes: 1\nNo: 2\n\n");
	cin >> input;
	if (input == 1) {
		type("\n\nThat's the spirit! Now..."); endL sleep 
	}
	else if (input == 2) {
		type("\n\nOh.... uhm.. well hey!"); endL
		type("If you are just gonna be moody don't bother playing!"); sleep endL 
		type("Ok fine.You keep your eyes closed!"); sleep endL
		type("Happy? And you die.\n\n\n\nJerk."); sleep 
		gameOver();
	}
	
	type("You see a simple room actually, a small stone brick room with..."); sleep endL
		type("A pool of water in the middle? Considering its the only thing here"); rest endL
		type("you move yourself towards the water to sip and revive your strength."); sleep endL
		type("You notice something... your reflection. You are... who are you?:"); sleep endL
		cout << "1: The Soldier - Wields a short sword and a decent balance of protection and strength." << endl;
		cout << "2: The Barbarian - Witness old world strength and march into battle with the Battle Axe." << endl;
		cout << "3: The Wizard - A higher difficulty of surivival, but magical none the less." << endl; 
		cout << "4: The Rogue - Ready to stab? Of course you are!" << endl; 
		cout << "5: The Bard - Why are you here? Nobody asked for a lute?" << endl; endL
		cin >> input;

			switch(input) {
			case 1: thePlayer = Soldier; break; 
			case 2: thePlayer = Barbarian; break;
			case 3: thePlayer = Wizard; break;
			case 4: thePlayer = Rogue; break;
			case 5: thePlayer = Bard; break;
			default: break;
			}
			endL endL

			
			cout << "Ah the " + thePlayer.getPlayerName() + ", of course. Well...\n"
			+ "are you ready to journey to move beyond the door at the end"
			+ "\nof the room,  " + thePlayer.getPlayerName() + "?" << endl;
			cout << "1: yes\n2: no\n\n";
			cin >> input;
			if (input == 1) {
				type("\nVery well... let the journey begin..."); clear
				roomB2(thePlayer);
			}
			else if (input == 2) {
				type("Okay... you lay back down and nap.. I guess"); sleep
				gameOver();
			}
}

//Room B1
void roomB1(Player thePlayer) {
	Player aPlayer = thePlayer;
	int input;

	type("You yank open the wooden door and pass through, the door slamming and locking"); endL
		type("behind you. The room is marble and in the center is a small chest"); endL
		type("Would you like to open the chestS?"); endL
		cout << "1: yes" << endl;
		cout << "2: no\n" << endl;
		cin >> input; 
		if (input == 1) {
			type("\nYou fling open the chest and find an orb that glows a bright red");
			type("As you touch the orb, the orb burns brighter and fades away");
			type("You feel your strength grow!");
			aPlayer.setAttackDice(aPlayer.getAttackDice() + 2);
			aPlayer.setPlayerArmor(aPlayer.getPlayerArmor() + 2);
		}
		else if (input == 2) {
			type("\nYou ignore the chest"); endL
		}

		sleep
			type("\n With only another wooden door to exit this room it is time to journey on."); endL
			roomC1(aPlayer);
}


//Room B2
void roomB2(Player thePlayer) {
	Monster aSkeleton("Skeleton", 10, 3, Bow, Bow.getDMGDice(), "Slashing");
	Player aPlayer = thePlayer;

 	type("Before you is a soft glow torches that softly spring of life"); endL
		type("The walls are cavernous, and there is a stench in the air"); endL
		type("But peace is ever fleeting as an arrow whizzes past you, hitting the door"); endL
		type("behind you, which has closed on it's own. What seems to be attacking you"); endL
		type("is a skeleton held together by magics, and wielding a bow. Time to fight"); endL
	
	Combat B2(aPlayer, aSkeleton, "", "");
	int input;
	int exit = 0;
	string item;
	do {
		cout << B2.to_string() << endl;
		type("What would you like to do?: "); endL
			cout << "	1: Attack Enemy" << endl;
		cout << "	2: Block" << endl;
		cin >> input; clear

			switch (input) {
			case 1: B2.PlayerAttack(rollD(20) + 3, rollD(Soldier.getAttackDice())); break;
			case 2: B2.getPlayer().setBlock(1); break;
			default: break;
			}

		B2.MonsterAttack(rollD(20) + 3, rollD(Skeleton.getAttackDice()));
		B2.getPlayer().setBlock(0);

		if (B2.getPlayer().getPlayerHealth() <= 0) {
			gameOver();
		}

	} while (B2.getMonster().getMonsterHealth() <= 0);
	
	sleep clear
		type("That could have been bad... you should be more careful"); endL
		type("You see two doors, one that is a cracked wood to your left"); endL
		type("and a second gilded door to your right. Which would you like to take?"); endL;
		cout << "1: Left" << endl;
		cout << "2: Right\n" << endl;
		cin >> input;
		switch (input) {
		case 1: roomB1(aPlayer); break;
		case 2: roomB2(aPlayer); break;
		default: break; 
		}
}


void roomB3(Player thePlayer) {
	Monster aGhost("Ghost", 8, 17, Bow, Bow.getDMGDice(), "Blundeoning");
	Player aPlayer = thePlayer;
	
	type("You yank open the wooden door and pass through, the door slamming and locking"); endL
		type("behind you. There is a silence that hangs in the air as you realize you are in a nearly"); endL
		type("Identical room, only there is a trail of a soft glowing goo throughout the room."); endL
		type("A ghoulish noise from behind reveals your fear of yet another attack has come true."); endL
		
	Combat B2(aPlayer, aGhost, "", "");
	int input;
	int exit = 0;
	string item;
	do {
		cout << B2.to_string() << endl;
		type("What would you like to do?: "); endL
			cout << "	1: Attack Enemy" << endl;
		cout << "	2: Block" << endl;
		cin >> input; clear

			switch (input) {
			case 1: B2.PlayerAttack(rollD(20) + 3, rollD(Soldier.getAttackDice())); break;
			case 2: B2.getPlayer().setBlock(1); break;
			default: break;
			}

		B2.MonsterAttack(rollD(20) + 3, rollD(Skeleton.getAttackDice()));
		B2.getPlayer().setBlock(0);

		if (B2.getPlayer().getPlayerHealth() <= 0) {
			gameOver();
		}

	} while (B2.getMonster().getMonsterHealth() <= 0);

	sleep
		sleep
		type("\n Gosh, it seems like this whole place may be itchy to fight."); endL
		type("With only another door to exit this room it is time to journey on."); endL
	

}
void roomC1(Player thePlayer) {
	Player aPlayer = thePlayer;
	Monster aGoblin("Goblin", 12, 5, Sword, Sword.getDMGDice(), "Burning");
	clear
		type("The door once again closes behind you, and the lights wheeze on. Inside it appears to be a cellar"); endL;
	type("You see before you a small humanoid character clutching to a bag of golden coins. It's skin a gentle red"); endL;
	type("but it's eyes are a harsh onyx. It spots you, bears its sharp teeth and lunges toward you."); endL;

	Combat B2(aPlayer, aGoblin, "", "");
	int input;
	int exit = 0;
	string item;
	do {
		cout << B2.to_string() << endl;
		type("What would you like to do?: "); endL
			cout << "	1: Attack Enemy" << endl;
		cout << "	2: Block" << endl;
		cin >> input; clear

			switch (input) {
			case 1: B2.PlayerAttack(rollD(20) + 3, rollD(Soldier.getAttackDice())); break;
			case 2: B2.getPlayer().setBlock(1); break;
			default: break;
			}

		B2.MonsterAttack(rollD(20) + 3, rollD(Skeleton.getAttackDice()));
		B2.getPlayer().setBlock(0);

		if (B2.getPlayer().getPlayerHealth() <= 0) {
			gameOver();
		}

	} while (B2.getMonster().getMonsterHealth() <= 0);

	sleep
		sleep
		type("\nThe creature falls limp to the gorund."); endL
		type("With only another door to exit this room it is time to journey on."); endL
		roomC2(aPlayer);

}

void roomC2(Player thePlayer) {
	Player aPlayer = thePlayer;
	clear
	type("Another locked door behing you, but as you enter this new room a rush of gentle light falls over you"); endL;
	type("and you feel your health increase once more as the light turns blue."); endL
		type("With only another door to exit this room it is time to journey on."); endL
		aPlayer.setPlayerHealth(aPlayer.getPlayerHealth() + 25);
	roomD1(aPlayer);
}


void roomC3(Player thePlayer) {
	Player aPlayer = thePlayer;
	clear
		type("Another locked door behing you, but as you enter this new room a rush of gentle light falls over you"); endL;
	type("and you feel your health increase once more as the light turns blue."); endL
		type("With only another door to exit this room it is time to journey on."); endL
		aPlayer.setPlayerHealth(aPlayer.getPlayerHealth() + 25);
	roomD2(aPlayer);
}

void roomD1(Player thePlayer) {
	clear
	Player aPlayer = thePlayer;
	type("In this room there is only a large steel door with what appears to be a complicated puzzle."); endL
		type("Next to the door are three levers but it appears there are four lights that remain off."); endL
		type("The levers each have a depection of an animal behind them:"); endL
		cout << "Lever 1: Monkey" << endl;
		cout << "Lever 2: Octopus" << endl;
		cout << "Lever 3: Newt" << endl; endL
			type("Scratched into the wall above is a riddle which reads:"); endL color(3);
		type("\n			Always old, sometimes new."); endL rest
			type("\n			Never sad, sometimes blue."); endL rest
			type("\n			Never empty, sometimes full."); endL rest
			type("\n			Never pushes, always pulls."); endL rest color(2);
			type("\nYou must pull the right levers in the right order, with four levers pulled"); endL
			int m, o, O, n;
			color(2);
			do {
				cout << "\nPlease enter one lever at a time using the following numbers for input:" << endl;
				cout << "1: Monkey" << endl;
				cout << "2: Octopus" << endl;
				cout << "3: Newt" << endl; endL
					cout << "Lever 1: "; cin >> m; endL
					cout << "Lever 2: "; cin >> o; endL
					cout << "Lever 3: "; cin >> O; endL
					cout << "Lever4 : "; cin >> n; endL
			} while(m != 1 || o != 2 || O != 2 || n != 3);

		gameEnd(aPlayer);
}

void roomD2(Player thePlayer) {
	clear
	Player aPlayer = thePlayer;
	int input;

	type("You yank open the wooden door and pass through, the door slamming and locking"); endL
		type("behind you. The room is marble and in the center is a small chest"); endL
		type("Would you like to open the chestS?"); endL
		cout << "1: yes" << endl;
	cout << "2: no\n" << endl;
	cin >> input;
	if (input == 1) {
		type("\nYou fling open the chest and find an orb that glows a bright red");
		type("As you touch the orb, the orb burns brighter and fades away");
		type("You feel your strength grow!");
		aPlayer.setAttackDice(aPlayer.getAttackDice() + 2);
		aPlayer.setPlayerArmor(aPlayer.getPlayerArmor() + 2);
	}
	else if (input == 2) {
		type("\nYou ignore the chest"); endL
	}

	sleep
		type("\n With only another wooden door to exit this room it is time to journey on."); endL
		roomD1(aPlayer);
}

void gameEnd(Player thePlayer) {
	Player aPlayer = thePlayer;
	Monster aBarbarian("Barbarian", 35, 7, BattleAxe, BattleAxe.getDMGDice(), "Slashing");
	clear
	type("The lights over the door spring to life and the doors flings open."); endL
		type("Before you is a forst, freedom from this place. But it appears there is "); endL
		type("One last fight before you are allowed to leave. An angry looking Barbarian of"); endL
		type("no specific clan markings sits before you. He lets out a sigh and lifts his axe. "); endL

		Combat B2(aPlayer, aBarbarian, "", "");
	int input;
	int exit = 0;
	string item;
	do {
		cout << B2.to_string() << endl;
		type("What would you like to do?: "); endL
			cout << "	1: Attack Enemy" << endl;
		cout << "	2: Block" << endl;
		cin >> input; clear

			switch (input) {
			case 1: B2.PlayerAttack(rollD(20) + 3, rollD(Soldier.getAttackDice())); break;
			case 2: B2.getPlayer().setBlock(1); break;
			default: break;
			}

		B2.MonsterAttack(rollD(20) + 3, rollD(Skeleton.getAttackDice()));
		B2.getPlayer().setBlock(0);

		if (B2.getPlayer().getPlayerHealth() <= 0) {
			gameOver();
		}

	} while (B2.getMonster().getMonsterHealth() <= 0);

	type("\nThe barbarian falls to your feet and you have won");
	gameOver();
}

void combatEnter(Player aPlayer, Monster aMonster) {                                                                                                         

	Combat testC(thePlayer, Skeleton, "", "");

	int check;
	int input;
	int exit = 0;
	string item;
	do {
		cout << testC.to_string() << endl;
		type("What would you like to do?: "); endL
		cout << "	1: Attack Enemy" << endl;
		cout << "	2: Block" << endl; 
		cin >> input; clear 

		switch (input) {
		case 1: testC.PlayerAttack(rollD(20) + 3, rollD(Soldier.getAttackDice())); break;
		case 2: testC.getPlayer().setBlock(1); break;
		default: break;
		}

		testC.MonsterAttack(rollD(20) + 3, rollD(Skeleton.getAttackDice()));
		testC.getPlayer().setBlock(0);
		

	} while (exit != 1);


}



void main() {
	intro();
}