/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Description
// Workshop 02 - OOP244
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"

using namespace std;

// TODO: the sict namespace
namespace sict {



	// TODO:definition for display(...) 
	void display(const struct Kingdom &kdom) {
	   
		cout << kdom.m_name << ", population " << kdom.m_population << endl;
		//	KINGDOM_NAME, population POPULATION<ENDL>
	    
	}

}
