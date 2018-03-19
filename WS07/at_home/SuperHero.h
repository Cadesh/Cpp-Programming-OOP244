//-----------------------------------------------------------------
// WS07 HOME - DERIVED CLASS
// COURSE: OOP 244
// DATE: 20 APR 2018
// SUPERHERO.H
//----------------------------------------------------------------


#ifndef SUPERHERO_H
#define SUPERHERO_H

#define _CRT_SECURE_NO_WARNINGS

#include "Hero.h"

using namespace std;

namespace sict {

	class SuperHero : public Hero {
	public:
		SuperHero();

		SuperHero(const char*pName, const int pHealth, const int pAttck, 
		          const int pSuper,	const int pDefense);

		int attackStrength() const;
		int defend() const;

	private:
		int _Super;
		int _Defense;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif