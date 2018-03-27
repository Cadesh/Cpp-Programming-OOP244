//-----------------------------------------------------------------
// WS06 CLASS WITH A RESOURCE
// STUDENT: Andre R
// COURSE: OOP 244
// DATE: 13 APR 2018
//----------------------------------------------------------------

#ifndef CONTRACT_H
#define CONTRACT_H

const int NAMESIZE = 20;

namespace sict {


	class Contact {

	private:
		char _name[NAMESIZE];
		long long * _phoneNumbers;
		int _phoneQuant;

		void setEmpty();
		void setAll(const char *, const long long *, const int);
		bool isValidPhone(const long long&) const;
		void printPhoneToString(const long long&) const;
		int countDigits(const long long &number) const;

	public:
		Contact(); //Default constructor
		Contact(const char *, const long long *, const int);
		~Contact();

		bool isEmpty() const;
		void display() const;

        

	};

}

#endif //CONTRACT_H