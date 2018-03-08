// Final Project Milestone 1
//
// Version 1.0
// Date: 10 MAR 2018
// Description: Project Milestone 1
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H

#include <iostream>
#include <fstream>
using namespace std;

//using const to avoid the use of macros 
const int NO_ERROR = 0;  //No error, the date is valid
const int CIN_FAILED = 1;  //istream failed on information entry
const int YEAR_ERROR = 2;  //Year value is invalid
const int MON_ERROR = 3;  //Month value is invalid
const int DAY_ERROR = 4;  //Day value is invalid

namespace AMA {

	const int min_year = 2000;
	const int max_year = 2030;

	class Date {

	private:
		int mYear;
		int mMonth;
		int mDay;
		int mComparator;
		int mError;

		int mdays(int, int)const;
		void errorCode(int errorCode);
		//my private functions
		bool checkYear(const int);
		bool checkMonth(const int);
		bool checkDay(int pMonth, int pYear, const int pDay);
		void setValues(const int pYear, const int pMonth, const int pDay);
		void setValues(const int pYear, const int pMonth, const int pDay, const int pError);

	public:
		//constructors
		Date();
		Date(const int pYear, const int pMonth, const int pDay);
		bool isDateValid() const;
		//overloaded operators
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		int errCode() const; //This query returns the error state as an error code value. 
		bool bad() const; //This query returns true if the error state is not NO_ERROR. 

		std::istream& read(std::istream& istr); //This function reads the date from the console
		std::ostream& write(std::ostream& ostr) const; //This query writes the date to an std::ostream 

	};

	//IO functions
	std::istream& operator>>(std::istream& is, Date& pDate);
	std::ostream& operator<<(std::ostream& os, const Date& pDate);
}
#endif