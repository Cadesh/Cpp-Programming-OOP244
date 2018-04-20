//***********************************************
// Final Project Milestone 5 - Product Class
// Student: Andre R
// Id:
// Date: 07 APR 2018
// email: 
// File: Product.h
//***********************************************

#ifndef PRODUCT_H
#define PRODUCT_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
//#include <fstream>
#include <cstring>
//#include <string>
#include <limits>
#include "ErrorState.h"
#include "iProduct.h"

using namespace std;

namespace AMA {

	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double TAX_RATE = 0.13;
	const char SEPARATOR(',');

	class Product: public iProduct {
	private:
		char _Type;    //record tag: "P" for Perishable, 
		char _SKU[max_sku_length + 1];
		char _Unit[max_unit_length + 1];
		char * _Name;
		int _Quant; //current quantity 
		int _Need;  //quantity needed
		double _Price; //before taxes
		bool _IsTaxable;
		ErrorState _Error;

		//my functions
		void setInitialValues(const char type, const char *sku, const char *name, const char *unit,
			int quant = 0, bool isTax = true, double price = 0, int need = 0);

	public:
		Product(const char type = 'N');
		Product(const char *sku, const char *name, const char *unit,
			int quant = 0, bool isTax = true, double price = 0, int need = 0);
		Product(const Product &p); //copy constructor
		Product& operator= (const Product &p); //copy assignment operator
		~Product(); //destructor

		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double total_cost() const; //returns price with taxes
		void quantity(int);
		int quantity() const;
		bool isEmpty() const;
		int qtyNeeded() const;
		void type(const char );
		char type();
		const char* errorMsg()const; //return the error state message
	    //void errorMsg(const char*);

		bool operator>(const char*) const;
		bool operator>(const iProduct&) const;
		bool operator==(const char*) const; //return true if sku equal
		int operator+=(int q);

		virtual std::fstream& store(std::fstream& file, bool newLine = true) const;
		virtual std::fstream& load(std::fstream& file);
		virtual std::ostream& write(std::ostream& os, bool linear) const;
		virtual std::istream& read(std::istream& is);

	protected:
		void name(const char*);
		const char* name() const;
		double cost() const; //cost of a single product plus taxes
		void message(const char*); //stores error message
		bool isClear() const; // true if not Error
	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);

}
#endif