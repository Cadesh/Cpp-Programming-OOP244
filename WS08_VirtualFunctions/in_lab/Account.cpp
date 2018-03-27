///////////////////////////////////////////
//
//   OOP244 WS08 LAB - Virtual Functions
//   Student: Andre R
//   Date: 27 MAR 2018
//
///////////////////////////////////////////

#include "Account.h"

using namespace std;

namespace sict {

	//--------------------------------------
	Account::Account() {
		balance(0);
	}
	//--------------------------------------
	Account::Account(double d) {
		balance(d);
	}

	//--------------------------------------
	bool Account::credit(double d) {
		bool succeed = false;
		if (d > 0) {
			this->_Balance += d;
			succeed = true;
		}
		return succeed;
	}


	//--------------------------------------
	bool Account::debit(double d) {
		bool succeed = false;
		if (d > 0) {
			this->_Balance -= d;
			succeed = true;
		}
		return succeed;
	}

	//--------------------------------------
	double Account::balance() const {
		return this->_Balance;
	}

	void Account::balance(const double d) {
		if (d < 0) {
			this->_Balance = 0;
		}
		else {
			this->_Balance = d;
		}
	}

	//does it need to be declared? No, because this is an abstract class
	//void Account::monthEnd() {}
	//void Account::display(std::ostream& out) const {} 

}