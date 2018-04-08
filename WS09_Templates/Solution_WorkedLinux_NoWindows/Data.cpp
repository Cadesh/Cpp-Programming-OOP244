

#include "Data.h"



namespace sict {


	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

	
		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		double pop = (max(population, n) - min(population, n));
		pop = pop / 1000000;
		std::cout << std::fixed;
		std::cout << std::setprecision(2);
		std::cout << "Population change from 2000 to 2004 is " << pop << " million" << std::endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		int lTrend = trend(violentCrimeRate, n);
		if (lTrend == -1) {
			std::cout << "Violent Crime trend is down" << std::endl;
		}
		else {
			std::cout << "Violent Crime trend is up" << std::endl;
		}

		// Q3 print the GTA number accurate to 0 decimal places
		double dLoc = average(grandTheftAuto, n)/1000000;
		std::cout << std::fixed;
		std::cout << std::setprecision(2);
		std::cout << "There are " << (dLoc) << " million Grand Theft Auto incidents on average a year" << std::endl;

		// Q4. Print the min and max violentCrime rates
		int loc = min(violentCrimeRate, n);
		std::cout << "The Minimum Violent Crime rate was " << (loc) << std::endl;

		loc = max(violentCrimeRate, n);
		std::cout << "The Maximum Violent Crime rate was " << (loc) << std::endl;

	}
}


	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//
/*	bool readRow(std::istream& input, const char* name, double* data, int n) {
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

	bool readRow(std::istream& input, const char* name, int* data, int n) {
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
	} */
