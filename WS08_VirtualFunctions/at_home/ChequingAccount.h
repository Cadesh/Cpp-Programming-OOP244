///////////////////////////////////////////
//
//   OOP244 WS08 LAB - Virtual Functions
//   Student: Andre R
//   Date: 27 MAR 2018
//
///////////////////////////////////////////

#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount : public Account {

	    private: 
			double _TransacFee;
			double _MonthlyFee;

			void transactionFee(const double);
			void monthlyFee(const double); 

		public:
			// constructor initializes account balance and transaction fee
			ChequingAccount(double, double, double);

			// credit adds +ve amount to the balance
			bool credit(double);

			// debit subtracts a +ve amount from the balance
			bool debit(double);

			// month end
			void monthEnd();

			// TODO: display inserts the account information into an ostream
			void display(std::ostream&) const;

	};
}
#endif
