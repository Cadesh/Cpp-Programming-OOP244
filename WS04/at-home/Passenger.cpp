// TODO: add file header comments here
/***********************************************************
// OOP244 Workshop 4: Constructors At Home
// File Passenger.cpp
// Version 1.0
// Date 16 FEB 2018
// Author Andre Rosa - 115997173
// Description
// Workshop 04 at Home - OOP244SEEL
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: add your headers here
#include <iostream>
#include <cstring>
//#include <iomanip>
//#include <math.h>      
#include "Passenger.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		this->passengerName[0] = '\0';
		this->destination[0] = '\0';
		this->dayDeparture = 0;
		this->monthDeparture = 0;
		this->yearDeparture = 0;
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char *name, const char *destiny) {

		bool isValid = true;

		if (!isValidName(name)) { //validated name
			isValid = false;
		}
		if (!isValidDestiny(destiny)) { //validated name
			isValid = false;
		}

		if (isValid == true) {
			Passenger(name, destiny, 2017, 7, 1);
			//strncpy(this->passengerName, name,MAX);
			//strncpy(this->destination, destiny, MAX);
			//this->dayDeparture = 1;
			//this->monthDeparture = 7;
			//this->yearDeparture = 2017;
		}
		else {
			this->passengerName[0] = '\0';
		}
		return;
	}
	//CONTRUCTOR with 5 paramters
	Passenger::Passenger(const char *name, const char *destiny, int year, int month, int day) {

		bool isValid = true; 
		
		if (!isValidName(name)) { //validated name
			isValid = false;
		} else
		if (!isValidDestiny(destiny)) { //validated name
			isValid = false;
		} else
		if ((year < 2017) || (year > 2020)) { //validate year
			isValid = false;
		} else
		if ((month < 1) || (month > 12)) { //validate month
			isValid = false;
		} else
		if ((day < 1) || (day > 31)) {  //validate day
			isValid = false;
		}

		if (isValid == true) {
			strncpy(this->passengerName, name, MAX);
			strncpy(this->destination, destiny, MAX);
			this->dayDeparture = day;
			this->monthDeparture = month;
			this->yearDeparture = year;
		}
		else {
			this->passengerName[0] = '\0';
		}
		return;

	}

	const char* Passenger::name() const {
		
		return this->passengerName;
	}

	bool Passenger::canTravelWith(const Passenger& cPsg) const {
		bool sameDestiny = false;
		bool sameDay = false;
		bool sameMonth = false;
		bool sameYear = false;

		if (strcmp(cPsg.destination, this->destination) == 0) {
			sameDestiny = true;
		}
		if (cPsg.dayDeparture == this->dayDeparture) {
			sameDay = true;
		}
		if (cPsg.monthDeparture == this->monthDeparture) {
			sameMonth = true;
		}
		if (cPsg.yearDeparture == this->yearDeparture) {
			sameYear = true;
		}

		if (sameYear && sameDay && sameMonth && sameDestiny) {
			return true;
		}
		else {
			return false;
		}


	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		bool state = false;
		if (strcmp(this->passengerName, "") == 0) {  //if they are equal return is 0
			state = true;
		}
		return state;
	}

	// TODO: implement display query here
	void Passenger::display() const {
		if ((strcmp(this->passengerName, "") == 0) || (strcmp(this->destination, "") == 0)) {
			cout << "No passenger!" << endl;
		}
		else {
			cout << this->passengerName << " - " << this->destination
				<< " on " << this->yearDeparture << "/";
	   
			if (this->monthDeparture < 10) {
				cout << "0" << this->monthDeparture << "/";  //to print months like 01, 02
			}
			else {
				cout << this->monthDeparture << "/";
			}
				
			if (this->dayDeparture < 10) {
				cout << "0" << this->dayDeparture << endl;
			}
			else {
				cout << this->dayDeparture << endl;
			}
		}


	}

	bool Passenger::isValidName(const char *name) {

		if (name == nullptr) {
			return false;
		}
		if (strcmp(name, "") == 0) {
			return false;
		}
		return true;
	}

	bool Passenger::isValidDestiny(const char *destiny) {

		if (destiny == nullptr) {
			return false;
		}
		if (strcmp(destiny, "") == 0) {
			return false;
		}
		return true;
	}
}