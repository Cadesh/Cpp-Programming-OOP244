/* -------------------------------------------

Section: OOP244 SEF
Date: 23 JAN 2018
----------------------------------------------
Workshop 1
---------------------------------------------- */

#ifndef NAMESPACE_GRAPH_H
#define NAMESPACE_GRAPH_H

#pragma once

// Maximum number of samples in an graph
#define MAX_NO_OF_SAMPLES 20

namespace sict {  //if you coment this line you can use functions with sict::getSamples

	// Fills the samples array with the statistic samples
	void getSamples(int samples[], int noOfSamples);

	// Finds the largest sample in the samples array, if it is larger than 70,
	// therwise it will return 70. 
	int findMax(int samples[], int noOfSamples);
	// Prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max);

	// Prints a graph comparing the sample values visually 
	void printGraph(int samples[], int noOfSamples);

}

#endif