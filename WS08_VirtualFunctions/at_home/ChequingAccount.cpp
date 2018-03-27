// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	ChequingAccount::ChequingAccount(double balance, double transacFee, double monthlyFee): Account (balance) {
		this->balance(balance);
	}

	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	bool ChequingAccount::credit(double d) {
		bool succeed = false;
		if (Account::credit(d)) {
			Account::debit(TRANSACTION_FEE);
			succeed = true;
		}
		return succeed;
	}

	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	bool ChequingAccount::debit(double d) {
		bool succeed = false;
		if (Account::debit(d)) {
			Account::debit(TRANSACTION_FEE);
			succeed = true;
		}
		return succeed;
	}

	// monthEnd debits month end fee
	void ChequingAccount::monthEnd() {
		Account::debit(MONTHLY_FEE);
	}


	// display inserts account information into ostream os
	void ChequingAccount::display(std::ostream &out) const {

		out.setf(ios::fixed); // control format		
		out << setprecision(2);
		out << "Account type: Chequing" << endl;
		out << "Balance: $"  << this->balance() << endl;
		out << "Per Transaction Fee: " << TRANSACTION_FEE << endl;
		out << "Monthly Fee: " << MONTHLY_FEE << endl;
		out.unsetf(ios::fixed);

	}

	void ChequingAccount::transactionFee(const double f) {
		if (f > 0) {
			this->_TransacFee = f;
		}
		else {
			this->_TransacFee = 0;
		}
	}
	void ChequingAccount::monthlyFee(const double f) {
		if (f > 0) {
			this->_MonthlyFee = f;
		}
		else {
			this->_MonthlyFee = 0;
		}
	}


}