// Final Project Milestone 1
//
// Version 1.0
// Date: 08 MAR 2018
// Author: Andre R
// Description: Project Milestone 1
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include "Date.h"

namespace AMA {

	// number of days in month mon_ and year year_
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errorCode(int errorCode) {
		this->mError = errorCode;
	}
	//--------------------------------------------------------------------------------------------------
	//default constructor
	Date::Date() {
		this->setValues(0, 0, 0, NO_ERROR);
	}
	//--------------------------------------------------------------------------------------------------
	// Constructor with 3 parameters
	Date::Date(const int pYear, const int pMonth, const int pDay) {
		setValues(pYear, pMonth, pDay);
	}
	//--------------------------------------------------------------------------------------------------
	bool Date::checkYear(const int pYear) {
		if ((pYear <= max_year) && (pYear >= min_year)) {
			return true;
		}
		return false;
	}
	//--------------------------------------------------------------------------------------------------
	bool Date::checkMonth(const int pMonth) {
		if ((pMonth < 13) && (pMonth > 0)) {
			return true;
		}
		return false;
	}
	//--------------------------------------------------------------------------------------------------
	bool Date::checkDay(int pYear, int pMonth, const int pDay) {
		//calls the method to check how many days in a month
		int quantDays = this->mdays(pMonth, pYear); //orde of param Month Year

		if ((pDay >= 1) && (pDay <= quantDays)) {
			return true;
		}
		return false;
	}

	//--------------------------------------------------------------------------------------------------
	// overloaded function: this one receives the dates and the ERROR code
	void Date::setValues(const int pYear, const int pMonth, const int pDay, const int pError) {
		this->mDay = pDay;
		this->mMonth = pMonth;
		this->mYear = pYear;
		this->mError = pError;
		if (pError == NO_ERROR) {
			this->mComparator = (pYear * 372) + (pMonth * 13) + pDay;
		}
		else {
			this->mComparator = 0;
		}
	}
	//--------------------------------------------------------------------------------------------------
	// overloaded function: this one receives only the dates and tests to set the ERROR code 
	void Date::setValues(const int pYear, const int pMonth, const int pDay) {
		if (!checkYear(pYear))
		{
			this->setValues(0, 0, 0, YEAR_ERROR); //Not a valid year
			return;
		}
		if (!checkMonth(pMonth)) {
			this->setValues(0, 0, 0, MON_ERROR); //not a valid month
			return;
		}
		if (!checkDay(pYear, pMonth, pDay)) {
			this->setValues(0, 0, 0, DAY_ERROR); //not a valid day
			return;
		}
		//no ERRORS
		this->setValues(pYear, pMonth, pDay, NO_ERROR); //all fine
		return;
	}
	//--------------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------
	bool Date::operator==(const Date& rhs) const {

		if ((this->isDateValid() == false) || (rhs.isDateValid() == false)) { return false; }

		if (this->mComparator == rhs.mComparator) {   //same date
			return true;
		}
		return false;
	}
	//--------------------------------------------------------------------------------------------------
	bool Date::operator!=(const Date& rhs) const {
		if ((this->isDateValid() == false) || (rhs.isDateValid() == false)) { return false; }

		return !(this->operator==(rhs));
	}
	//--------------------------------------------------------------------------------------------------
	bool Date::operator<(const Date& rhs) const {
		if ((this->isDateValid() == false) || (rhs.isDateValid() == false)) { return false; }

		if (this->mComparator < rhs.mComparator) {
			return true;
		}
		return false;
	}
	//--------------------------------------------------------------------------------------------------
	bool Date::operator>(const Date& rhs) const {
		if ((this->isDateValid() == false) || (rhs.isDateValid() == false)) { return false; }

		if (this->mComparator > rhs.mComparator) {
			return true;
		}
		return false;
	}
	//--------------------------------------------------------------------------------------------------
	bool Date::operator<=(const Date& rhs) const {
		if ((this->isDateValid() == false) || (rhs.isDateValid() == false)) { return false; }

		if (this->mComparator <= rhs.mComparator) {
			return true;
		}
		return false;
	}
	//--------------------------------------------------------------------------------------------------
	bool Date::operator>=(const Date& rhs) const {
		if ((this->isDateValid() == false) || (rhs.isDateValid() == false)) { return false; }

		if (this->mComparator >= rhs.mComparator) {
			return true;
		}
		return false;
	}
	//--------------------------------------------------------------------------------------------------
	int Date::errCode() const {  // This query returns the error state as an error code value.
		return this->mError;
	}
	//--------------------------------------------------------------------------------------------------
	bool Date::bad() const {     //This query returns true if the error state is not NO_ERROR. 
		if (this->mError == NO_ERROR) {
			return true;
		}
		return false;
	}
	//--------------------------------------------------------------------------------------------------
	//Read the date in the format YYYY/MM/DD if there is no "/" set the ERROR to CIN_FAILED 
	std::istream& Date::read(std::istream& istr) {

		int lDay, lMonth, lYear;
		istr >> lYear;
		if (istr.get() != '/') {
			this->setValues(0, 0, 0, CIN_FAILED);
			return istr;
		}
		istr >> lMonth;
		if (istr.get() != '/') {
			this->setValues(0, 0, 0, CIN_FAILED);
			return istr;
		}
		istr >> lDay;

		this->setValues(lYear, lMonth, lDay);
		return istr;

	}
	//--------------------------------------------------------------------------------------------------
	//Write the date in the format YYYY/MM/DD
	std::ostream& Date::write(std::ostream& ostr) const {

		ostr << this->mYear << "/";

		if (this->mMonth < 10) {
			ostr << "0";
		}
		ostr << this->mMonth << "/";

		if (this->mDay < 10) {
			ostr << "0";
		}

		ostr << this->mDay;
		return ostr;
	}
	//--------------------------------------------------------------------------------------------------
	bool Date::isDateValid() const {
		if (this->mError == NO_ERROR) {
			return true;
		}
		return false;
	}


	//OUTPUT function (not member function)
	std::ostream& operator<<(ostream& os, const Date& pDate) {
		pDate.write(os);
		return os;
	}
	//INPUT function  (not member function)
	std::istream& operator>>(istream& is, Date& pDate) {
		pDate.read(is);
		return is;
	}

}
