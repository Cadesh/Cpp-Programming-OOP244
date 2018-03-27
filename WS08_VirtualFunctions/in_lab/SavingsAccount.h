///////////////////////////////////////////
//
//   OOP244 WS08 LAB - Virtual Functions
//   Student: Andre R
//   Date: 27 MAR 2018
//
///////////////////////////////////////////

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include <ostream>

#include "Account.h"

namespace sict {
	class SavingsAccount : public Account {
	private:
		double _InterestRate;
	
		void InterestRate(const double);
		double InterestRate() const;

	public:
			//  constructor initializes balance and interest rate
		     SavingsAccount(double, double);
			//  perform month end transactions
			 void monthEnd() ;
			//  display inserts the account information into an ostream			
			 void display(std::ostream&) const ; //keyword override does not work in g++ linux

	};
}  //end of namespace sict
#endif
