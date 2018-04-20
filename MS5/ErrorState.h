//***********************************************
// Final Project Milestone 3 - ErrorState Class
// Student: Andre R
// Id: 
// Date: 19 MAR 2018
// email: 
// File: ErrorState.h
//***********************************************

#ifndef ERRORSTATE_H
#define ERRORSTATE_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

namespace AMA {


	class ErrorState {
	private:
		char * _ErrStateMsg;
		void setErrorState(const char* errorMessage);

	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		//whats the meaning of =delete I googled it but I still cant understand
		ErrorState(const ErrorState& em) = delete; //will not be defined
		ErrorState& operator=(const ErrorState& em) = delete; //will not be defined
		virtual ~ErrorState(); //this is a virtual function it will only be redefined on derived classes. 
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;
	};
	std::ostream& operator<<(std::ostream& os, const ErrorState& pES);

}
#endif