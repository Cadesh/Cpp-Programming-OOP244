/***********************************************************
// OOP244 Workshop 4: Constructors at Home
// File Passenger.h
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
// TODO: add file header comments here


// TODO: add header file guard here
#ifndef NAMESPACE_PASSENGER_H
#define NAMESPACE_PASSENGER_H

#pragma once

// TODO: declare your namespace here
namespace sict{

	const int MAX = 32;

	// TODO: define the Passenger class here
	class Passenger {
	
	public:
		Passenger(); //Default constructor
		Passenger(const char *name, const char *destiny);
		Passenger(const char *name, const char *destiny, int year, int month, int day);


		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;

	private:
		char passengerName[MAX];
		char destination[MAX];
		int yearDeparture;
		int monthDeparture;
		int dayDeparture;

		bool isValidName(const char *name);
		bool isValidDestiny(const char *destiny);

	}; //End of class Passenger

} //END OF NAMESPACE SICT


#endif