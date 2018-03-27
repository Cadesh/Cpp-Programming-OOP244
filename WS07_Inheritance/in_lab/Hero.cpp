//-----------------------------------------------------------------
// WS07 LAB - DERIVED CLASS
// STUDENT: Andre R
// COURSE: OOP 244
// DATE: 20 APR 2018
// HERO.CPP
//----------------------------------------------------------------

#include "Hero.h"

namespace sict {

	Hero::Hero() {
		this->setHero("", 0, 0);
	}
	Hero::Hero(const char *pName, const int pHealth, const int pAttck) {
		this->setHero(pName, pHealth, pAttck);
	}

	void Hero::setHero(const char *pName, const int pHealth, const int pAttck) {

		if ((pName == nullptr) || (strcmp(pName, "") == 0) || (pHealth < 1) || (pAttck < 1)) { //invalid values
			strcpy(this->_Name, "");
			this->_Attck = 0;
			this->_Health = 0;
		}
		else {
			strcpy(this->_Name, pName);
			this->_Attck = pAttck;
			this->_Health = pHealth;
		}
	}

	void Hero::operator-= (int attack) {
		if (attack > 0) {
			this->_Health -= attack;
			//cout << this->_Name << " " << this->_Health << endl;
		}
	}
	bool Hero::isAlive() const {
		bool healthy = false;
		if (this->_Health > 0) {
			healthy = true;
		}
		return healthy;
	}
	int Hero::attackStrength() const {
		return this->_Attck;
	}

	ostream& operator<<(ostream& os, const Hero& hero) {
		if (strcmp(hero._Name, "") == 0) {
			os << "No hero";
		}
		else {
			os << hero._Name;
		}
		return os;
	}

	const char* Hero::getName() {
		return this->_Name;
	}

	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero lFirst = first;
		Hero lSecon = second;
		int rounds = 0;
		const Hero* champion;

		//cout << lFirst.attackStrength();

		for (int i = 1; i < (max_rounds+1); i++) {
			lFirst -= lSecon.attackStrength();
			lSecon -= lFirst.attackStrength();
			if ((!(lFirst.isAlive())) || (!(lSecon.isAlive()))) {
				cout << "Ancient Battle! ";
				if (lFirst.isAlive()) {
					cout << lFirst.getName() << " vs " << lSecon.getName();
					cout << " : Winner is " << lFirst.getName();
					champion = &first;
				}
				else {
					cout << lSecon.getName() << " vs " << lFirst.getName();
					cout << " : Winner is " << lSecon.getName(); 
					champion = &second;
				}
				cout << " in " << i << " rounds." << endl;
				i = max_rounds;
			} //if
		} //for
		return *champion;
	}

} //end namespace
