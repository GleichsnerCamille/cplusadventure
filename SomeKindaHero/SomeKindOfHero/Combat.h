#ifndef COMBAT_STATS
#define COMBAT_STATS 
#include <iostream>
#include <iomanip>
#include <string>
#include "Weapon.h"
#include "Player.h"
#include "Monster.h"


using namespace std; 

class Combat {
public: 
	//Common Calls 
	Combat();
	Combat(Player player, Monster monster,  string playerAction, string monsterAction);
	string to_string();
	void PlayerAttack(int attackRoll, int damageRoll);
	void MonsterAttack(int attackRoll, int damageRoll);

	//Set Calls 
	void setPlayer(Player player);
	void setMonster(Monster monster);
	void setPlayerAction(string playerAction);
	void setMonsterAction(string MonsterAction);

	//Get Calls 
	Player getPlayer();
	Monster getMonster();
	string getPlayerAction();
	string getMonsterAction();

protected:
	Player p; 
	Monster m; 
	string pAction;
	string mAction; 
};

Combat::Combat() {
	p = Player();
	m = Monster();
	pAction = "";
	mAction = "";
}

Combat::Combat(Player player, Monster monster,  string playerAction, string monsterAction) {
	p = player; 
	m = monster; 
	pAction = playerAction;
	mAction = monsterAction; 
}

string Combat::to_string() {
	string output;
	
	output = "\n" + m.getMonsterName() + ": "+ "		" + p.getPlayerName() +":\n"
		+ "	HP: " + std::to_string(m.getMonsterHealth())  + "			HP: " + std::to_string(p.getPlayerHealth()) + "\n"
		+ "	AP: " + std::to_string(m.getMonsterArmor()) +  "			AP: " + std::to_string(p.getPlayerArmor()) + "\n\n";

	return output;
}


void Combat::PlayerAttack(int attackRoll, int damageRoll) {
	int aRoll = attackRoll;
	int dRoll = damageRoll;

	if (m.getResist() == p.getPlayerWeapon().getDMGType()) {
		dRoll -= 2;
		if (dRoll < 0) {
			dRoll = 0;
		}
	}

	cout << "\nYou rolled a " + std::to_string(aRoll) + " to attack the " + m.getMonsterName() + "\n";
	if (aRoll == 20) {
		cout << "Your attack was a critical sucess! You deal " + std::to_string(dRoll * 2) + " damage!";
		int newHealth = m.getMonsterHealth() - (dRoll * 2);
		m.setMonsterHealth(newHealth);
	}
	else if (aRoll > m.getMonsterArmor()) {
		cout << "Your attack hit! You hit for " + std::to_string(dRoll) + " damage!" << endl;
		int newHealth = m.getMonsterHealth() - dRoll;
		m.setMonsterHealth(newHealth);
	}
	else if (aRoll == m.getMonsterArmor()) {
		dRoll -= 2;
		if (dRoll < 0) {
			dRoll = 0;
		}
		cout << "Your attack just barely hit! You hit for " + std::to_string(dRoll) << endl;
		int newHealth = m.getMonsterHealth() - dRoll;
		m.setMonsterHealth(newHealth);
	}
	else if (aRoll < m.getMonsterArmor()) {
		cout << "Your attack missed!" << endl; 
	}
}

void Combat::MonsterAttack(int attackRoll, int damageRoll) {
	int aRoll = attackRoll;
	int dRoll = damageRoll;

	if (p.getBlock() == 1) {
		dRoll = dRoll - 4; }

		if (dRoll < 0) {
			dRoll = 0;
		}
	

	cout << "\n" + m.getMonsterName() + " rolled " + std::to_string(aRoll) + " to attack you!" + "\n";
	if (aRoll == 20) {
		cout << m.getMonsterName() + "'s attack was a critical sucess! It deals " + std::to_string(dRoll * 2) + " damage!";
		int newHealth = p.getPlayerHealth() - (dRoll * 2);
		p.setPlayerHealth(newHealth);
	}
	else if (aRoll > p.getPlayerArmor()) {
		cout << m.getMonsterName() + "'s attack hit! It hit for " + std::to_string(dRoll) + " damage!" << endl;
		int newHealth = p.getPlayerHealth() - dRoll;
		p.setPlayerHealth(newHealth);
	}
	else if (aRoll == p.getPlayerArmor()) {
		dRoll -= 2;
		if (dRoll < 0) {
			dRoll = 0;
		}
		cout << m.getMonsterName() + "'s attack just barely hit! It hit for " + std::to_string(dRoll) << endl;
		int newHealth = p.getPlayerHealth() - dRoll;
		p.setPlayerHealth(newHealth);
	}
	else if (aRoll < m.getMonsterArmor()) {
		cout << m.getMonsterName() + "'s attack missed!" << endl;
	}
}





//Setters
void Combat::setPlayer(Player player) { p = player; }
void Combat::setMonster(Monster monster) { m = monster; }
void Combat::setPlayerAction(string playerAction) { pAction = playerAction; }
void Combat::setMonsterAction(string monsterAction) { mAction = monsterAction; }

//Getters
Player Combat::getPlayer() { return p; }
Monster Combat::getMonster() { return m; }
string Combat::getPlayerAction() { return pAction; }
string Combat::getMonsterAction() { return mAction; }

#endif
