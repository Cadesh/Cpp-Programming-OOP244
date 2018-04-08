//----------------------------------------
//----------------------------------------
// STUDENT: ANDRE R
// DATE: 03 APRIL 2018
//----------------------------------------
//----------------------------------------

#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	//
	//  sum returns the sum of n items in data
	template<typename T>
	int trend(const T* data, int n) {

		int trend = 0;
		for (int i = 0; i < (n - 1); i++) {
			if (data[i] > data[i + 1]) {
				trend = -1;
			}
			else {
				trend = 1;
				i = n;
			}
		}
		return trend;
	}

	//----------------------------------------------------
	//  sum returns the sum of n items in data
	template<typename T>
	double average(const T* data, int n) {
		double locVar = 0;
		for (int i = 0; i < n; i++) {
			locVar += data[i];
		}
		locVar = locVar / n;
		return locVar;
	}

	//----------------------------------------------------
	//  sum returns the sum of n items in data
	template<typename T>
	T sum(const T* data, int n) {
		T locVar = 0;

		for (int i = 0; i < n; i++) {
			locVar += data[i];
		}

		return locVar;
	}

	//----------------------------------------------------
	//  min returns the smallest item in data
	template<typename T>
	T min(const T* data, int n) {
		T locVar = LARGEST_NUMBER;

		for (int i = 0; i < n; i++) {
			if (locVar > data[i]) {
				locVar = data[i];
			}
		}
		return locVar;
	}

	//----------------------------------------------------
	// max returns the largest item in data
	template<typename T>
	T max(const T* data, int n) {
		T locVar = SMALLEST_NUMBER;

		for (int i = 0; i < n; i++) {
			if (locVar < data[i]) {
				locVar = data[i];
			}
		}
		return locVar;
	}
	//----------------------------------------------------
	//----------------------------------------------------
	// display inserts n items of data into std::cout
	template<typename T>
	void display(const char* name, const T* data, int n) {

		cout << right << setw(20) << name;
		for (int i = 0; i < n; i++) {
			cout << right << setw(15) << data[i];
		}
		cout << endl;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//----------------------------------------------------
	template<typename T>
	bool read(std::istream& input, T* data, int n) {


		for (int i = 0; i < n; i++) {

			if (input.bad()) {
				return false;
			}
			if (input.peek() == ',')
				input.ignore();
			input >> data[i];
		}

		return true;
	}
	//----------------------------------------------------
	//----------------------------------------------------

	template<typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}
	// min returns the smallest item in data
	//

        
	// sum returns the sum of n items in data
	//    
   
	// average returns the average of n items in data
	//

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//

	// display inserts n items of data into std::cout
	//

	//bool readRow(std::istream& input, const char* name, int* data, int n);
	//bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

