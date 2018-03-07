/***********************************************************
// OOP244 Workshop 3: Classes and Privacy
// File CRA_Acount.cpp
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

#include <iostream>
#include <cstring>
#include <iomanip>
#include <math.h>       
#include "CRA_Account.h"

using namespace std;

namespace sict{

	//------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------
	CRA_Account::CRA_Account() {

		cleanCRAAccount();
	}
	//------------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		//check valid sin
		if ((isValidSIN(sin) == true) && (strcmp(familyName, "")) && (strcmp(givenName, ""))){
			//stores valid values
			strcpy(this->cFamilyName, familyName);
			strcpy(this->cGivenName, givenName);
			this->cSIN = sin;
		}
		else { //stores invalid values
			cleanCRAAccount();
		}
		return;
	}
	//------------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------
	bool CRA_Account::isEmpty() const {
		bool empty = true; //empty by default

		if ((this->cSIN != empty_sin) && (strcmp(this->cFamilyName, "")) && (strcmp(this->cGivenName, ""))) {
			empty = false;
		}

		return empty;
	}
	//------------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------
	void CRA_Account::display() const {
		int i;
		//cout.precision(2);
		if (!this->isEmpty()) {
			cout << "Family Name: " << this->cFamilyName << endl;
			cout << "Given Name : " << this->cGivenName << endl;
			cout << "CRA Account: " << this->cSIN << endl;
			
			for (i = 0; i < max_yrs; i++) {
				if (this->aBalance[i] > 2) {
					cout << "Year (" << this->aYears[i] << ") balance owing: " << std::fixed << std::setprecision(2) << this->aBalance[i] << endl;
				}
				if (this->aBalance[i] < (-2)) {  
					cout << "Year (" << this->aYears[i] << ") refund due: " << std::fixed << std::setprecision(2) << (this->aBalance[i]*(-1)) << endl;
				}
				if ((this->aBalance[i] <= 2) && (this->aBalance[i] >= (-2))) {
					cout << "Year (" << this->aYears[i] << ") No balance owing or refund due!" << endl;
				}
			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}
		return;
	}
	//------------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------
	void CRA_Account::cleanCRAAccount() {

		strcpy(this->cFamilyName, "\0");
		strcpy(this->cGivenName, "\0");
		this->cSIN = empty_sin;

		for (int i = 0; i < max_yrs; i++)
		{
			this->aBalance[i] = 0;
		}
		for (int j = 0; j < max_yrs; j++)
		{
			this->aYears[j] = 0;
		}
	}
	//------------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------
	bool CRA_Account::isValidSIN(int sin) const {
		int lSin[sin_length];
		int iTemp = sin;
		int loc = 0;
		bool valid = false;
		int i;

		if ((sin >= min_sin) && (sin <= max_sin)) {

			//now test the rule 
			//1 - put the SIN digits in an array
			for (i = 0; i < sin_length; i++) {
				loc = pow(10 ,(8 - i));
				lSin[i] = (int)(iTemp / loc);
				iTemp = iTemp - (lSin[i] * loc);
				//cout << "value " << i << " " << lSin[i] << endl;
			}
			//2 - Now make the calculations
			int checkDigit = lSin[8]; //last digit
			int firstAlt = 0;  //used for the indexes 1,3,5,7
			int secondAlt = 0; //used for indexes 0,2,4,6,8
			
			for (i = 0; i < (sin_length-1); i++) {
				if ((i % 2) != 0) {
					lSin[i] = lSin[i] * 2;
					if (lSin[i] >= 10) { 
						secondAlt += 1;
						secondAlt += lSin[i] - 10;
					}
					else {
						secondAlt += lSin[i];
					}
				}
				else {
					firstAlt += lSin[i];
				}
			}
			
			firstAlt = firstAlt + secondAlt;  //add the two parts
			int next10 = ((int)(firstAlt / 10) + 1) * 10; //get next multiplier
		   // cout << "Validate " << firstAlt << " round next "<< next10 << endl;
			if ((next10 - firstAlt) == checkDigit) {  //subtract and verify the check digit
				valid = true;
			}
			else {
				valid = false;
			}
	    
		}
		return valid;
	}
  //------------------------------------------------------------------------------------------
  //------------------------------------------------------------------------------------------
	bool CRA_Account::hasRoomToStore() {
		bool hasFreeSlot = false;
		for (int i = 0; i < max_yrs; i++) {
			if (this->aYears[i] == 0) {
				hasFreeSlot = true;
			}
		}
		return hasFreeSlot;
	}
	//------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------
	void CRA_Account::set(int year, double balance) {
		int valIndex = -1;
		if (this->isValidSIN(this->cSIN) ) {
			//check the next valid slot
			for (int i = 0; i < max_yrs; i++){
				if (this->aYears[i] == 0) {
					valIndex = i;
					i = max_yrs;
				}
			}
		}

		//insert data in the next slot
		if (valIndex != -1) {
			this->aBalance[valIndex] = balance;
			this->aYears[valIndex] = year;
		}
		else {
			cout << "YEAR-BALANCE ARRAY IS FULL!" << endl;
		}
	}
	//------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------
}
// END OF NAMESPACE SICT