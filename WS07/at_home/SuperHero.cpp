//-----------------------------------------------------------------
// WS07 HOME - DERIVED CLASS
// STUDENT: ANDRE ROSA - 115997173
// COURSE: OOP 244
// DATE: 20 APR 2018
// SUPERHERO.CPP
//----------------------------------------------------------------

#include "Superhero.h"

namespace sict {

	//---------------------------------------------------------------------------------
	SuperHero::SuperHero(const char*pName, const int pHealth,
		const int pAttck, const int pSuper,const int pDefense) : 
		Hero(pName, pHealth, pAttck), _Super(pSuper), _Defense(pDefense){
	
	}
	//---------------------------------------------------------------------------------
	SuperHero::SuperHero() : Hero(), _Super(0), _Defense(0) {
	}
	//---------------------------------------------------------------------------------
	int SuperHero::attackStrength() const {
		return (this->_Attck + this->_Super);
	}
	//---------------------------------------------------------------------------------
	int SuperHero::defend() const {
		return this->_Defense;
	}
	//---------------------------------------------------------------------------------
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		SuperHero lFirst = first;
		SuperHero lSecon = second;
		int rounds = 0;
		const SuperHero* champion;

		//cout << lFirst.attackStrength();

		for (int i = 1; i < (max_rounds + 1); i++) {
			lFirst -= (lSecon.attackStrength() - lFirst.defend());
			lSecon -= (lFirst.attackStrength() - lSecon.defend());
			if ((!(lFirst.isAlive())) || (!(lSecon.isAlive()))) {
				cout << "Super Fight! ";
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

} //namespace