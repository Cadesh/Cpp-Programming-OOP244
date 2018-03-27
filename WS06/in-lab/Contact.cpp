//-----------------------------------------------------------------
// WS06 CLASS WITH A RESOURCE
// STUDENT: Andre R
// COURSE: OOP 244
// DATE: 13 APR 2018
//----------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict {

	//----------------------------------------------------------------
	Contact::Contact() { //Default constructor
		this->setEmpty();
	} 
	//----------------------------------------------------------------
	Contact::Contact(const char* pName, const long long * pPhones, const int phoneQuant) {
		
		if (pName == nullptr || (strcmp(pName, "") == 0)) { //invalid name
			this->setEmpty();
			return;
		}
		this->setAll(pName, pPhones, phoneQuant);
	}

	//----------------------------------------------------------------
	void Contact::setAll(const char * pName, const long long * pPhones, const int phoneQuant) {
		int validPhonesQuant = 0;

		//int size = strlen(pName);
		//cout << size << endl;
		strncpy(this->_name, pName, NAMESIZE - 1); //copies only the max size allowed
		this->_name[19] = 0;

		//set the phones 
		// check the quantity of valid phones
		for (int i = 0; i < phoneQuant; i++) {
			//cout << pPhones[i] << endl;
			if (isValidPhone(pPhones[i])) {
			//	cout << pPhones[i] << endl;
				validPhonesQuant++;
			} 
		}
		this->_phoneQuant = validPhonesQuant;

		//resizes the phone array
		this->_phoneNumbers = new long long[validPhonesQuant];

		//now puts the phones on the array
		int countIndex = 0;
		for (int i = 0; i < phoneQuant; i++) {
			//cout << pPhones[i] << endl;
			if (isValidPhone(pPhones[i])) {
				//cout << pPhones[i] << endl;
				this->_phoneNumbers[countIndex] = pPhones[i];
				//cout << this->_phoneNumbers[countIndex] << endl;
				countIndex++;
			}
		}


	}
	//----------------------------------------------------------------
	int Contact::countDigits(const long long &pNumber) const {
		//calculates the number of digits
		int digits = 0;
		long long lNumber = pNumber;
		while (lNumber != 0) { lNumber /= 10; digits++; }
		return digits;
		//I got this idea from https://stackoverflow.com/questions/1489830/efficient-way-to-determine-number-of-digits-in-an-integer
	}

	//----------------------------------------------------------------
	bool Contact::isValidPhone(const long long &pPhone) const { 

		if (pPhone == 0) { return false; }  //phone cant be = 0

		//calculates the number of digits
		int digits = this->countDigits(pPhone);

		//I got this idea from https://stackoverflow.com/questions/1489830/efficient-way-to-determine-number-of-digits-in-an-integer

		if ((digits != 11) && (digits != 12)) { return false; } //phone can only have 11 or 12 digits

		//put the phone in an char array and check the valid values
		if (digits == 11) {
			char phone[12]; // indexes   0 - 1 2 3 - 4 5 6 7 8 9 10
			sprintf(phone, "%llu", pPhone);
			//phone[11] = 0;
			//exactly seven digits for the number(cannot start with zero);
			//phone index 5 cant be 0
			if (phone[4] == '0') { return false; }
			// exactly three digits for the area code(cannot start with zero)
			//phone index 2 cant be 0
			if (phone[1] == '0') { return false; }
			// 1 - one to two digits for the country code(cannot be zero)
			if ((phone[0] == '0')) { return false; }
		} 
		if (digits == 12) {
			char phone[13]; // indexes  0 1 - 2 3 4 - 5 6 7 8 9 10 11
			sprintf(phone, "%llu", pPhone);
			//phone[12] = 0;
			//exactly seven digits for the number(cannot start with zero);
			//phone index 5 cant be 0
			if (phone[5] == '0') { return false; }
			// exactly three digits for the area code(cannot start with zero)
			//phone index 2 cant be 0
			if (phone[2] == '0') { return false; }
			// 1 - one to two digits for the country code(cannot be zero)
			if ((phone[0] == '0') && (phone[1] == '0')) { return false; }
		}
		return true;
	}

	//----------------------------------------------------------------
	void Contact::setEmpty() {

		strcpy(this->_name, "");
		this->_phoneQuant = 0;
		this->_phoneNumbers = nullptr;
	}
	//----------------------------------------------------------------
	Contact::~Contact() {
		this->setEmpty();
	}
	//----------------------------------------------------------------
	bool Contact::isEmpty() const {
		if (strcmp(this->_name, "") == 0) { //equal values
			return true;
		}
		return false;
	}
	//----------------------------------------------------------------
	void Contact::display() const {
		//empty contact
		if (this->isEmpty() == true) {
			cout << "Empty contact!" << endl;
			return;
		}
	
		//print the contact
		cout << this->_name << endl;
		//phone loop
		for (int i = 0; i < this->_phoneQuant; i++) {
			//char phone[13]; // 0 1 2 3 4 5 6 7 8 9 10 11 12 
			//sprintf(phone, "%d", this->_phoneNumbers[i]);
			this->printPhoneToString(this->_phoneNumbers[i]);
		}
	}
	//----------------------------------------------------------------

	void Contact::printPhoneToString(const long long& pPhone) const {

		//get the number of digits 
		int digits = this->countDigits(pPhone);

		if (digits == 11) {
			char retPhone[18];
			char phone[12]; // indexes   0 - 1 2 3 - 4 5 6 7 8 9 10
			sprintf(phone, "%llu", pPhone);
			retPhone[0] = '(';
			retPhone[1] = '+';
			retPhone[2] = phone[0];
			retPhone[3] = ')';
			retPhone[4] = ' ';

			retPhone[5] = phone[1];
			retPhone[6] = phone[2];
			retPhone[7] = phone[3];
			retPhone[8] = ' ';

			retPhone[9] = phone[4];
			retPhone[10] = phone[5];
			retPhone[11] = phone[6];
			retPhone[12] = '-';
			retPhone[13] = phone[7];
			retPhone[14] = phone[8];
			retPhone[15] = phone[9];
			retPhone[16] = phone[10];
			retPhone[17] = 0;
			cout << retPhone << endl;
		}
		if (digits == 12) {
			char retPhone[19];
			char phone[13]; // indexes  0 1 - 2 3 4 - 5 6 7 8 9 10 11
			sprintf(phone, "%llu", pPhone);
			sprintf(phone, "%llu", pPhone);
			retPhone[0] = '(';
			retPhone[1] = '+';
			retPhone[2] = phone[0];
			retPhone[3] = phone[1];
			retPhone[4] = ')';
			retPhone[5] = ' ';

			retPhone[6] = phone[2];
			retPhone[7] = phone[3];
			retPhone[8] = phone[4];
			retPhone[9] = ' ';

			retPhone[10] = phone[5];
			retPhone[11] = phone[6];
			retPhone[12] = phone[7];
			retPhone[13] = '-';
			retPhone[14] = phone[8];
			retPhone[15] = phone[9];
			retPhone[16] = phone[10];
			retPhone[17] = phone[11];
			retPhone[18] = 0;
			cout << retPhone << endl;
		}
	}
	//----------------------------------------------------------------

} //end of namespace sict