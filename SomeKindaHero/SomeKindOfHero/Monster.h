#ifndef MONSTER_STATS
#define MONSTER_STATS 
#include <iostream>
#include <iomanip>
#include <string>
#include "Weapon.h"

using namespace std;

class Monster {
public: 
	//Common Calls
	Monster();
	Monster(string monsterName, int monsterHealth, int monsterArmor, 
			 Weapon monsterWeapon, int attackDice, string resist);
	string to_string();

	//Set Calls
	void setMonsterName(string monsterName);
	void setMonsterHealth(int monsterHealth);
	void setMonsterArmor(int monsterArmor);
	void setMonsterWeapon(Weapon MonsterWeapon);
	void setAttackDice(int attackDice);
	void setResist(string resist);

	//Get Calls 
	string getMonsterName();
	int getMonsterHealth();
	int getMonsterArmor();
	Weapon getMonsterWeapon();
	int getAttackDice();
	string getResist();

protected:
	string mName;
	int mHealth;
	int mArmor; 
	Weapon mWeapon;
	int mAttack;
	string r;
};



Monster::Monster() {
	mName = "";
	mHealth = 0;
	mArmor = 0; 
	mWeapon = Weapon("", "", "", "", 0, 0);
	mAttack = mWeapon.getDMGDice();
	r = "none";
}

Monster::Monster(string monsterName, int monsterHealth, int monsterArmor,
	Weapon monsterWeapon, int attackDice, string resist) {
	mName = monsterName;
	mHealth = monsterHealth;
	mArmor = monsterArmor;
	mWeapon = monsterWeapon;
	mAttack = attackDice; 
	r = resist;
}

string Monster::to_string() {
	string output;
	output = getMonsterName() + "~\n"
		+ "	Health: " + std::to_string(mHealth) + "\n"
		+ "	Armor: " + std::to_string(mArmor) + "\n"
		+ "	Weapon: " + mWeapon.getWeaponName() + "\n"
		+ "	Resist: " + getResist() + "\n";

	return output;
}

//Setters
void Monster::setMonsterName(string monsterName) { mName = monsterName; }
void Monster::setMonsterHealth(int monsterHealth) { mHealth = monsterHealth; }
void Monster::setMonsterArmor(int monsterArmor) { mArmor = monsterArmor; }
void Monster::setMonsterWeapon(Weapon MonsterWeapon) { mWeapon = MonsterWeapon; }
void Monster::setAttackDice(int attackDice) { mAttack = attackDice; }
void Monster::setResist(string resist) { r = resist; }

//Getters 
string Monster::getMonsterName() { return mName; }
int Monster::getMonsterHealth() { return mHealth; }
int Monster::getMonsterArmor() { return mArmor; }
Weapon Monster::getMonsterWeapon() { return mWeapon; }
int Monster::getAttackDice() { return mAttack; }
string Monster::getResist() { return r; }



#endif