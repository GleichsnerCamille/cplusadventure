#ifndef WEAPON_STATS
#define WEAPON_STATS 
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


class Weapon {
	public: 
		//Common Calls
		Weapon();
		Weapon(string weaponName, string weaponType, string weaponClass, 
			string dmgType, int range, int dmgDice);
		string to_string();


		//Set Calls 
		void setWeaponName(string weaponName);
		void setWeaponType(string weaponType);
		void setWeaponClass(string weaponClass);
		void setDMGType(string dmgType);
		void setRange(int range);
		void setDMGDice(int dmgDice);

		//Get Calls
		string getWeaponName();
		string getWeaponType();
		string getWeaponClass();
		string getDMGType();
		int getRange();
		int getDMGDice();
		
protected: 
	string wName;
	string wType;
	string wClass; 
	string dType;
	int r; 
	int dDice; 

};

Weapon::Weapon() {
	wName = "";
	wType = "";
	wClass = "";
	dType = "";
	r = 0;
	dDice = 0; 
}

Weapon::Weapon(string weaponName, string weaponType, string weaponClass,
				string dmgType, int range, int dmgDice) {
	wName = weaponName; 
	wType = weaponType; 
	wClass = weaponClass; 
	dType = dmgType; 
	r = range;
	dDice = dmgDice;
}

string Weapon::to_string() {
	string output;
	output = getWeaponName() + "~\n"
		+ "	Weapon Type: " + getWeaponType() + "\n"
		+ "	Weapon Class: " + getWeaponClass() + "\n"
		+ "	Damage Type: " + getDMGType() + "\n"
		+ "	Range: " + std::to_string(r) + " feet\n"
		+ "	Damage Dice: d" + std::to_string(dDice) + "\n";

	return output;
}

//Setters 
void Weapon::setWeaponName(string weaponName) { wName = weaponName; }
void Weapon::setWeaponType(string weaponType) { wType = weaponType; }
void Weapon::setWeaponClass(string weaponClass) { wClass = weaponClass; }
void Weapon::setDMGType(string dmgType) { dType = dmgType; }
void Weapon::setRange(int range) { r = range; }
void Weapon::setDMGDice(int dmgDice) { dDice = dmgDice; }

//Getters
string Weapon::getWeaponName() { return wName; }
string Weapon::getWeaponType() { return wType; }
string Weapon::getWeaponClass() { return wClass; }
string Weapon::getDMGType() { return dType;  }
int Weapon::getRange() { return r; }
int Weapon::getDMGDice() { return dDice; }







#endif 
