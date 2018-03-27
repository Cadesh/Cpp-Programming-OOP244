//***********************************************
// Final Project Milestone 2 - ErrorState Class
// Student: Andre R
// Id: 
// Date: 19 MAR 2018
// File: ErrorState.cpp
//***********************************************

#include "ErrorState.h"


namespace AMA {
	//----------------------------------------------------------
	ErrorState::ErrorState(const char* errorMessage) {
		this->_ErrStateMsg = nullptr;
		setErrorState(errorMessage);

	}
	//----------------------------------------------------------
	ErrorState::~ErrorState() {
		delete[] this->_ErrStateMsg;
	} 
	//----------------------------------------------------------
	void ErrorState::setErrorState(const char* errorMessage) {
		if (errorMessage == nullptr) {
			this->_ErrStateMsg = new char[5];
			strcpy(this->_ErrStateMsg, "SAFE");
		}
		else {
			if (this->_ErrStateMsg != nullptr) {
				delete[] this->_ErrStateMsg;
			}
			this->_ErrStateMsg = new char[strlen(errorMessage) + 1];
			strcpy(this->_ErrStateMsg, errorMessage);
		}
	}
	//----------------------------------------------------------
	void ErrorState::clear() {
		delete[] this->_ErrStateMsg;
		this->_ErrStateMsg = new char[5];
		strcpy(this->_ErrStateMsg, "SAFE");
	}
	//----------------------------------------------------------
	bool ErrorState::isClear() const {
		bool isClear = false;
		if (strcmp(this->_ErrStateMsg, "SAFE") == 0) {
			isClear = true;
		}
		return isClear;
	}
	//----------------------------------------------------------
	void ErrorState::message(const char* str) {
		delete[] this->_ErrStateMsg;
		this->_ErrStateMsg = new char[strlen(str) + 1];
		strcpy(this->_ErrStateMsg, str);
	}
	//----------------------------------------------------------
	const char* ErrorState::message()const {
		return this->_ErrStateMsg;
	}
	//----------------------------------------------------------
	std::ostream& operator<<(std::ostream& os, const ErrorState& pES) {
		if (pES.isClear() == false) {
			cout << pES.message();
		}
		return os;
	}
	//----------------------------------------------------------
}

//----------------------------------------------------------
/*	ErrorState& ErrorState::operator=(const ErrorState& em) {
if (em._ErrStateMsg == nullptr) {
this->_ErrStateMsg = new char[5];
strcpy(this->_ErrStateMsg, "SAFE");
}
else {
delete[] this->_ErrStateMsg;
this->_ErrStateMsg = new char[strlen(em._ErrStateMsg) + 1];
strcpy(this->_ErrStateMsg, em._ErrStateMsg);
}
}
*/