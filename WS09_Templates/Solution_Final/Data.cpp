//----------------------------------------
//----------------------------------------
// STUDENT: ANDRE R
// DATE: 03 APRIL 2018
//----------------------------------------
//----------------------------------------

#include "Data.h"

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//

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
		double dLoc = average(grandTheftAuto, n) / 1000000;
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