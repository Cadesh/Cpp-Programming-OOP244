//-----------------------------------------------------------------
// WS07 LAB - DERIVED CLASS
// STUDENT: Andre R
// COURSE: OOP 244
// DATE: 20 APR 2018
// HERO.H
//----------------------------------------------------------------


#ifndef HERO_H
#define HERO_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>



using namespace std;

namespace sict {

	const int max_rounds = 100;
	const int max_name = 40;

	class Hero {

	protected:  //protected so the derived class can access them
		char _Name [max_name+1];
		int _Health; //health = hit points
		int _Attck;  //attack strenght

		void setHero(const char*, const int, const int);

	public:
		Hero();
		Hero(const char*, const int, const int);

		void operator-= (int attack);
		bool isAlive() const;
		int attackStrength() const;
		const char* getName();

		friend ostream& operator<<(ostream& os, const Hero& hero);
	};

	const Hero& operator*(const Hero& first, const Hero& second);
	
}

#endif