///////////////////////////////////////////
//
//   OOP244 WS08 LAB - Virtual Functions
//   Student: Andre R
//   Date: 27 MAR 2018
//
///////////////////////////////////////////

#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	const double INTEREST_RATE = 0.05;

	// Allocator function
	//---------------------------------------------------------------
	iAccount* CreateAccount(const char* c, double balance) {

		Account * lAcc = nullptr;
		if (c[0] == 'S') {
			lAcc = new SavingsAccount(balance, INTEREST_RATE);
		}
		return lAcc;
	}
	//--------------------------------------------------------------

} //end of namespace sict
