/***********************************************************
// OOP244 Workshop 4: Constructors
// File Passenger.h
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
// TODO: add file header comments here


// TODO: add header file guard here
#ifndef NAMESPACE_PASSENGER_H
#define NAMESPACE_PASSENGER_H

#pragma once

// TODO: declare your namespace here
namespace sict{
	// TODO: define the Passenger class here
	class Passenger {
	
	public:
		Passenger(); //Default constructor
		Passenger(const char *name, const char *destiny);

		bool isEmpty() const;
		void display() const;

	private:
		char passengerName[32];
		char destination[32];

	}; //End of class Passenger

} //END OF NAMESPACE SICT


#endif