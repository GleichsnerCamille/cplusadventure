#ifndef PLAYER_STATS
#define PLAYER_STATS 
#include <iostream>
#include <iomanip>
#include <string>
#include "Weapon.h"

using namespace std;

class Player {
public:
	//Common Calls
	Player();
	Player(string PlayerName, string PlayerClass,  int PlayerHealth, int PlayerArmor,
		Weapon PlayerWeapon, int attackDice, int blockCon);
	string to_string();
	
	//Set Calls
	void setPlayerName(string PlayerName);
	void setPlayerHealth(int PlayerHealth);
	void setPlayerArmor(int PlayerArmor);
	void setPlayerWeapon(Weapon PlayerWeapon);
	void setAttackDice(int attackDice);
	void setClass(string playerClass);
	void setBlock(int blockCon);

	//Get Calls 
	string getPlayerName();
	int getPlayerHealth();
	int getPlayerArmor();
	Weapon getPlayerWeapon();
	int getAttackDice();
	string getClass();
	int getBlock();

protected:
	string pName;
	int pHealth;
	int pArmor;
	Weapon pWeapon;
	int pAttack;
	string pClass;
	int block;
};



Player::Player() {
	pName = "";
	pHealth = 0;
	pArmor = 0;
	pWeapon = Weapon("", "", "", "", 0, 0);
	pAttack = pWeapon.getDMGDice();
	pClass = "none";
}

Player::Player(string PlayerName, string PlayerClass, int PlayerHealth, int PlayerArmor,
	Weapon PlayerWeapon, int attackDice, int blockCon) {
	pName = PlayerName;
	pHealth = PlayerHealth;
	pArmor = PlayerArmor;
	pWeapon = PlayerWeapon;
	pAttack = attackDice;
	pClass = PlayerClass;
}

string Player::to_string() {
	string output;
	output = getPlayerName() + "~\n"
		+ "	Health: " + std::to_string(pHealth) + "\n"
		+ "	Armor: " + std::to_string(pArmor) + "\n"
		+ "	Weapon: " + pWeapon.getWeaponName() + "\n"
		+ "	Class: " + getClass() + "\n";

	return output;
}

//Setters
void Player::setPlayerName(string PlayerName) { pName = PlayerName; }
void Player::setPlayerHealth(int PlayerHealth) { pHealth = PlayerHealth; }
void Player::setPlayerArmor(int PlayerArmor) { pArmor = PlayerArmor; }
void Player::setPlayerWeapon(Weapon PlayerWeapon) { pWeapon = PlayerWeapon; }
void Player::setAttackDice(int attackDice) { pAttack = attackDice; }
void Player::setClass(string PlayerClass) { pClass = PlayerClass; }
void Player::setBlock(int blockCon) { block = blockCon; }

//Getters 
string Player::getPlayerName() { return pName; }
int Player::getPlayerHealth() { return pHealth; }
int Player::getPlayerArmor() { return pArmor; }
Weapon Player::getPlayerWeapon() { return pWeapon; }
int Player::getAttackDice() { return pAttack; }
string Player::getClass() { return pClass; }
int Player::getBlock() { return block;  }



#endif