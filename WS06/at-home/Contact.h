//-----------------------------------------------------------------
// WS06 CLASS WITH A RESOURCE
// STUDENT: ANDRE R
// COURSE: OOP 244
// DATE: 15 APR 2018
// AT HOME
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
		int countDigits(const long long & number) const;
		void copyValues(const Contact&);

	public:
		Contact(); //Default constructor
		Contact(const char *, const long long *, const int); //constructor 3 param
		Contact(const Contact &); //COPY constructor
		~Contact();

		bool isEmpty() const;
		void display() const;
		Contact& operator = (const Contact& ); // assignment operator
		Contact& operator += (const long long& pNumber);


        

	};

}

#endif //CONTRACT_H