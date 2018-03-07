/***********************************************************
// OOP244 Workshop 3: Classes and Privacy
// File CRA_Acount.h
// Version 1.0
// Description
// Workshop 03 - OOP244SEEL
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/
#ifndef NAMESPACE_CRA_ACCOUNT_H
#define NAMESPACE_CRA_ACCOUNT_H

#pragma once

namespace sict {

	const int max_name_length = 40;  //max size for name of the account holder
	const int min_sin = 100000000;   //minimum valid Social Insurance Mumber 
	const int max_sin = 999999999;   //maximum valid Social Insurance Number
	const int empty_sin = - 1;        //empty sin default value
	const int sin_length = 9;
	const int max_yrs = 4;

	class CRA_Account {

	public:
		//constructor
		CRA_Account();

		//ws public functions
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		void set(int year, double balance);
		

	private:
		char cFamilyName [max_name_length + 1];
		char cGivenName [max_name_length + 1];
		int cSIN;
		int aYears[max_yrs];
		float aBalance[max_yrs];

		//my private functions 
		bool isValidSIN(int) const;
		void cleanCRAAccount();
		bool hasRoomToStore();

	};

}

#endif