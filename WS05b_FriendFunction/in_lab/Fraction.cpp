/***********************************************************
// OOP244 Workshop 5b:  Helper Functions as Friends of a C++ Class.
// File Fraction.cpp
// Version 1.0
// Date 06 MAR 2018
// Author Andre R
// Description
// Workshop 05b - OOP244SEEL
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: insert header files
#include "Fraction.h"

#include <iostream>
#include <cstring>

using namespace std;

// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		initialize();
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int n, int d) {
		if ((d > 0) && ( n >= 0)) {
			this->numerator = n;
			this->denominator = d;
			reduce();
		}
		else {
			initialize();
		}
	}

	void Fraction::initialize() {
		this->numerator = 0;
		this->denominator = -1;
	}

	// TODO: implement the max query
	int Fraction::max() const {
		if (this->denominator > this->numerator) {
			return this->denominator;
		}
		else {
			return this->numerator;
		}
	}
	// TODO: implement the min query
	int Fraction::min() const {
		if (this->denominator > this->numerator) {
			return this->numerator;
		}
		else {
			return this->denominator;
		}
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int lGcd = this->gcd();

		this->denominator = this->denominator / lGcd;
		this->numerator = this->numerator / lGcd;
	}
	// TODO: implement the display query
	void Fraction::display() const {
		if (this->denominator == 1) {
			cout << this->numerator;
		}
		else  if ((this->denominator <=0) || (this->numerator < 0)) {
			cout << "no fraction stored";
		}
		else {

			cout << this->numerator << "/" << this->denominator;
		}
	
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		if (this->denominator == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	// TODO: implement the + operator
/*	Fraction Fraction::operator + (const Fraction& rhs) const {
		Fraction lFrac;
		
		if (!(this->isEmpty() && rhs.isEmpty())) {
			lFrac.numerator = (this->numerator * rhs.denominator) + (this->denominator * rhs.numerator);
			lFrac.denominator = (this->denominator * rhs.denominator);
		}
		else {
			// lFrac was initialized with the default constructor;
		}
		return lFrac;
	} */
	//---------------------------------------------------------------
	Fraction Fraction::operator * (const Fraction& rhs) const {
		Fraction lFrac;

		if (!(this->isEmpty() && rhs.isEmpty())) {
			lFrac.numerator = (this->numerator * rhs.numerator);
			lFrac.denominator = (this->denominator * rhs.denominator);
			lFrac.reduce();
		}
		else {
			// lFrac was initialized with the deafult constructor;
		}
		return lFrac;
	}
	//---------------------------------------------------------------
	bool Fraction::operator == (const Fraction& rhs) const {
		if (!(this->isEmpty() && rhs.isEmpty())) {
			if (this->calculate() == rhs.calculate()) {
				return true;
			}
		}
		return false;
	}
	//---------------------------------------------------------------

	bool Fraction::operator != (const Fraction& rhs) const {
		if (!(this->isEmpty() && rhs.isEmpty())) {
			return (!(this->operator==(rhs)));
		} 
		return false;
	}
	//---------------------------------------------------------------

	Fraction& Fraction::operator += (const Fraction& rhs) {
		Fraction lFrac;
		if (!(this->isEmpty() && rhs.isEmpty())) {
			lFrac = operator+(rhs, *this);
			lFrac.reduce();
			*this = lFrac;
		}
		else {
			this->initialize();
		}
		return *this;
	}
	//---------------------------------------------------------------

	double Fraction::calculate() const {
		return (this->numerator / this->denominator);
	}
	//---------------------------------------------------------------


	//HELPER FRIENDLY 
	Fraction operator+ (const Fraction& rhs, const Fraction& lhs)  {
		Fraction lFrac;

		if (!(lhs.isEmpty() && rhs.isEmpty())) {
			lFrac.numerator = (lhs.numerator * rhs.denominator) + (lhs.denominator * rhs.numerator);
			lFrac.denominator = (lhs.denominator * rhs.denominator);
		}
		else {
			// lFrac was initialized with the default constructor;
		}
		return lFrac;
	}


}   //END OF NAMESPACE SICT



