// TODO: add file header comments here
/***********************************************************
// OOP244 Workshop 4: Constructors
// File Passenger.cpp
// Version 1.0
// Date 13 FEB 2018
// Author Andre Rosa - 115997173
// Description
// Workshop 04 - OOP244SEEL
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

using namespace std;

// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		strcpy(this->passengerName, "");
		strcpy(this->destination, "");

	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char *name, const char *destiny) {

		if ((name == nullptr) || (destiny == nullptr)) { 
			strcpy(this->passengerName, "");
			strcpy(this->destination, "");
			return; 
		}
		
		if ((strcmp(name, "") == 0) || (strcmp(destiny, "") == 0)) { 
			strcpy(this->passengerName, "");
			strcpy(this->destination, "");
			return;
		}

		strcpy(this->passengerName, name);
		strcpy(this->destination, destiny);

		return;
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
			cout << this->passengerName << " - " << this->destination << endl;
		}
		

	}

}
