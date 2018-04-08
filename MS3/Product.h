//***********************************************
// Final Project Milestone 2 - ErrorState Class

// Date: 19 MAR 2018
// File: Product.h
//***********************************************

#ifndef PRODUCT_H
#define PRODUCT_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
//#include <fstream>
//#include <cstring>
//#include <string>
#include <limits>
#include "ErrorState.h"

using namespace std;

namespace AMA {

	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double TAX_RATE = 0.13;
	const char SEPARATOR(',');

	class Product {
	private:
		char _Type;
		char _SKU[max_sku_length + 1];
		char _Unit[max_unit_length + 1];
		char * _Name;
		int _Quant; //current quantity 
		int _Need;  //quantity needed
		double _Price; //before taxes
		bool _IsTaxable;
		ErrorState _Error;

		//my functions
		void setInitialValues(const char *sku, const char *name, const char *unit,
			int quant = 0, bool isTax = true, double price = 0, int need = 0);

	public:
		Product();
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

		bool operator>(const char*) const;
		bool operator>(const Product&) const;
		int operator+=(int);
		bool operator==(const char*) const; //return true if sku equal

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);

	protected:
		void name(const char*);
		const char* name() const;
		double cost() const; //cost of a single product plus taxes
		void message(const char*); //stores error message
		bool isClear() const; // true if not Error
	};

	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);

}
#endif