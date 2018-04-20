//***********************************************
// Final Project Milestone 5 - Perishable Class
// Student: Andre R
// Id: 
// email: 
// Date: 07 APR 2018
// File: Product.h
//***********************************************

#ifndef PERISHABLE_H
#define PERISHABLE_H
#define _CRT_SECURE_NO_WARNINGS

#include "Product.h"
#include "Date.h"


namespace AMA {

	class Perishable : public Product {

	private:
		Date _DateExp;

	public:
		Perishable();

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;
	};


}

#endif