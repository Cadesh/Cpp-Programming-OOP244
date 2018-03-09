/***********************************************************
// OOP244 Workshop 5b:  Helper Functions as Friends of a C++ Class.
// File Fraction.h
// Version 1.0
// Date 06 MAR 2018
// Author Andre Rosa - 115997173
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

// TODO: add header file guard here
#ifndef NAMESPACE_FRACTION_H
#define NAMESPACE_FRACTION_H

#pragma once

// TODO: create namespace
namespace sict {

	// TODO: define the Fraction class
	class Fraction {
	private:
		// TODO: declare instance variables 
		int numerator;
		int denominator;

		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
		void initialize(); //set the private members to default values
		double calculate() const;

	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);

		bool isEmpty() const;
		void display() const;

		
		//Fraction operator + (const Fraction& rhs) const;
		friend Fraction operator+ (const Fraction& rhs, const Fraction& lhs);

		Fraction operator * (const Fraction& rhs) const;
		bool operator == (const Fraction& rhs) const;
		bool operator != (const Fraction& rhs) const;
		Fraction& operator += (const Fraction& rhs);
	
	};

	
}
#endif