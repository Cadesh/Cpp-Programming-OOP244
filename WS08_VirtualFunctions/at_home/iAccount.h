// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: iAccount.h
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file defines the iAccount interface
///////////////////////////////////////////////////

#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__

#include <ostream>

namespace sict {

	class iAccount {
	public:
		// credit adds +ve amount to the balance
		virtual bool credit(double) = 0;
		// debit subtracts a +ve amount from the balance
		virtual bool debit(double) = 0;
		// month end adds month end costs
		virtual void monthEnd() = 0;
		// display inserts the account information into an ostream
		virtual void display(std::ostream&) const = 0;
	};
	// add prototype for Allocator function
	iAccount* CreateAccount(const char*, double);

} //end of namespace sict
#endif

