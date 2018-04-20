
//***********************************************
// Final Project Milestone 5 - Perishable Class
// Student: Andre R
// Id: 
// email: 
// Date: 07 APR 2018
// File: Perishable.cpp
//***********************************************

#include "Perishable.h"

namespace AMA {

	Perishable::Perishable(): Product ('P') {
    //passes 'P' as the _Type for Perishable products

	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {

	   //calls its base class version passing as arguments a reference to the fstream object and a false flag
	   Product::store(file, false);

		file << SEPARATOR;
		file << this->_DateExp;

		if (newLine == true)
		{
			file << endl;
		}
		return file;

	}
	std::fstream& Perishable::load(std::fstream& file) {
		
	    Product::load(file);

		this->_DateExp.read(file);

		return file;

	}
	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
	
		 Product::write(os, linear);

		if ((!isEmpty()) && (strcmp(this->errorMsg(), "SAFE") == 0))
		{
			if (linear == true)
			{
				os << this->_DateExp;
			}
			else {
				os << " Expiry date: " << this->_DateExp;
			}
		}
		return os;

	}
	std::istream& Perishable::read(std::istream& is) {
	
		 Product::read(is);

		 Date lDate;
		 ErrorState error;
	
			 cout << " Expiry date (YYYY/MM/DD): ";
			 is.clear();
			 is >> lDate;


			 switch (lDate.errCode()){
			 
			 case CIN_FAILED:
				 error.message("Invalid Date Entry");
				 is.setstate(std::ios::failbit);
				 break;
			 case YEAR_ERROR:
				 error.message("Invalid Year in Date Entry");
				 is.setstate(std::ios::failbit);
				 break;
			 case MON_ERROR:
				 error.message("Invalid Month in Date Entry");
				 is.setstate(std::ios::failbit);
				 break;
			 case DAY_ERROR:
				 error.message("Invalid Day in Date Entry");
				 is.setstate(std::ios::failbit);
				 break;
			 default:
				 if (!is.fail()) { 
					// this->type('P');
					 this->_DateExp = lDate; 
				 }
				 break;
			 }

			 if (!error.isClear()) {
				 this->message(error.message());
			 }

		 return is;
	}
	const Date& Perishable::expiry() const {
		return this->_DateExp;
	}

}