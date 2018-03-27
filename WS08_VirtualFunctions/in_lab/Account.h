///////////////////////////////////////////
//
//   OOP244 WS08 LAB - Virtual Functions
//   Student: Andre R
//   Date: 27 MAR 2018
//
///////////////////////////////////////////

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include <iomanip>
#include "iAccount.h"

using namespace std;

namespace sict {

	class Account : public iAccount {

	private:
		double _Balance;

	protected:
		double balance() const;
		void balance(const double) ;

	public:
		Account();
		// constructor initializes account balance, defaults to 0.0 
		Account(double);
		// credit adds +ve amount to the balance 
		bool credit(double);
		// debit subtracts a +ve amount from the balance
		bool debit(double);

		//does it need to be declared? No, because this is an abstract class
		//virtual void monthEnd();
		//virtual void display(std::ostream&) const;

	};
} //end of namespace sict
#endif
