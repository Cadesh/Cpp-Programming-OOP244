///////////////////////////////////////////
//
//   OOP244 WS08 LAB - Virtual Functions
//   Student: Andre R
//   Date: 27 MAR 2018
//
///////////////////////////////////////////

#include "SavingsAccount.h"

using namespace std;

namespace sict {

	SavingsAccount::SavingsAccount(double balance, double interest) : Account (balance){
		this->InterestRate(interest);
	}

	// TODO: perform month end transactions
	void SavingsAccount::monthEnd() {
		double earned = 0;
		earned = this->balance() * this->InterestRate();
		this->credit(earned);
	}

	// TODO: display inserts the account information into an ostream			
	//-------------------------------------------------
	void SavingsAccount::display(std::ostream& out) const {

		out.setf(ios::fixed); // control format
		out << setprecision(2);  //set precision
		out << "Account type: Savings" << endl;
		out <<  "Balance: $"   << this->balance() << endl;
		out << "Interest Rate (%): " << (this->InterestRate()*100) << endl;
		out.unsetf(ios::fixed);
	
	}
	//-------------------------------------------------
	double SavingsAccount::InterestRate() const {
		return this->_InterestRate;
	}
	//-------------------------------------------------
	void SavingsAccount::InterestRate(const double d) {
		if (d < 0) {
			this->_InterestRate = 0;
		}
		else {
			this->_InterestRate = d;
		}
	}

}