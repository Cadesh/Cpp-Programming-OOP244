///////////////////////////////////////////
//
//   OOP244 WS08 LAB - Virtual Functions
//   Student: Andre R
//   Date: 27 MAR 2018
//
///////////////////////////////////////////

#include "SavingsAccount.h" 
#include "ChequingAccount.h" 

namespace sict {

	// Allocator function
	//---------------------------------------------------------------
	iAccount* CreateAccount(const char* c, double balance) {

		Account * lAcc = nullptr;
		if (c[0] == 'S') { //SAVINGS
			lAcc = new SavingsAccount(balance, INTEREST_RATE);
		}
		if (c[0] == 'C') { //CHECKING
			lAcc = new ChequingAccount(balance, TRANSACTION_FEE, MONTHLY_FEE);
		}
		return lAcc;
	}
	//--------------------------------------------------------------

} //end of namespace sict
