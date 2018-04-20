//***********************************************
// Final Project Milestone 2 - ErrorState Class
// Student: Andre R
// Id: 
// Date: 19 MAR 2018
// email: 
// File: Product.cpp
//***********************************************

//SEE THE USE OF IGNORE

#include "Product.h"

using namespace std;

namespace AMA {
	//-------------------------------------------------------
	Product::Product(const char type) {

		setInitialValues( type, "", "", "");
	}
	//-------------------------------------------------------
	Product::Product(const Product &p) {
		setInitialValues(p._Type, p._SKU, p._Name, p._Unit, p._Quant, p._IsTaxable, p._Price, p._Need);
	}
	//-------------------------------------------------------
	Product& Product::operator= (const Product &p) {
		setInitialValues(p._Type, p._SKU, p._Name, p._Unit, p._Quant, p._IsTaxable, p._Price, p._Need);
		return *this;
	}
	//-------------------------------------------------------
	Product::Product(const char *sku, const char *name, const char *unit,
		int quant, bool isTax, double price, int need)
	{
		setInitialValues('N', sku, name, unit, quant, isTax, price, need);
	}
	//-------------------------------------------------------
	void Product::setInitialValues(const char type, const char *sku, const char *name, const char *unit, int quant, bool isTax, double price, int need)
	{
		_Name = nullptr;
		this->name(name);
		_Type = type;
		strcpy(_SKU, sku);
		strcpy(_Unit, unit);
		_IsTaxable = isTax;
		_Price = price;
		_Quant = quant;
		_Need = need;
	}
	//-------------------------------------------------------
	void Product::name(const char* name) {

		if (!(this->_Name == nullptr)) {
			delete[] _Name;
		}

		if (name == nullptr) {
			_Name = new char[1];
			strcpy(_Name, "");
		}
		else {
			_Name = new char[strlen(name) + 1];
			strcpy(_Name, name);
		}
	}
	//-------------------------------------------------------
	//OK
	std::fstream& Product::store(std::fstream& file, bool newLine) const {

		file << _Type << SEPARATOR;
		file << _SKU << SEPARATOR;
		file << _Name << SEPARATOR;  //leaves name as the last field
		file << _Unit << SEPARATOR;
		file << _IsTaxable << SEPARATOR;
		file << _Price << SEPARATOR;
		file << _Quant << SEPARATOR;
		file << _Need;
		
		if (newLine == true)
		{
			file << endl;
		}
		return file;
	}
	//-------------------------------------------------------
	std::fstream& Product::load(std::fstream& file) {

		char sku[max_sku_length+1];
		char name[max_name_length+1];
		char unit[max_unit_length+1];
		int tax = 0;
		double price = 0.0;
		int onHand = 0;
		int needed = 0;

		//Product lProd; //creates local object
		//file >> lProd._Type;
		file.getline(sku, max_sku_length+1, ',');
		file.getline(name, max_name_length+1, ',');
		file.getline(unit, max_unit_length+1, ',');
		//file.ignore();  //numeric_limits<streamsize>::max(), '\n') ????
		file >> tax;
		file.ignore();
		file >> price;
		file.ignore();
		file >> onHand;
		file.ignore();
		file >> needed;
		file.ignore();
		
		//fill the object
		strcpy(this->_SKU, sku);
		strcpy(this->_Name, name);
		strcpy(this->_Unit, unit);
		this->_IsTaxable = (bool)tax;
		this->_Price = price;
		this->_Quant = onHand;
		this->_Need = needed;

		//not using copy assign because of the derivade class Perishable
		//*this = lProd;  //copy assigns to the curren tobject

		return file;
	}
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
	std::ostream& Product::write(std::ostream& os, bool linear) const {

		//test the error state for the output in MS5
		if (this->isClear()) {

			//there is no error, so its ok to print
			if (linear) {
				os.unsetf(ios::right);
				os.width(max_sku_length);
				os.setf(ios::left);
				os << _SKU;
				os << "|";
				os.width(20);
				os.setf(ios::left);
				os << _Name;
				os << "|";
				os.unsetf(ios::left);
				os.width(7);
				os.setf(ios::right);
				os << std::fixed;
				os.precision(2);
				os << cost();
				os << "|";
				os.width(4);
				os << _Quant;
				os << "|";
				os.unsetf(ios::right);
				os.width(10);
				os.setf(ios::left);
				os << _Unit;
				os << "|";
				os.unsetf(ios::left);
				os.width(4);
				os.setf(ios::right);
				os << _Need;
				os << "|";

			}
			else { //if it is not linear, go tabular
				os << " Sku: " << _SKU << endl;
				os << " Name (no spaces): " << _Name << endl;
				os << " Price: " << _Price << endl;
				if (_IsTaxable) {
					os << " Price after tax: " << cost() << endl;
				}
				else {
					os << " Price after tax: N/A" << endl;
				}
				os << " Quantity on hand: " << _Quant << " " <<  _Unit <<  endl;
				os << " Quantity needed: " << _Need << endl;
			}
		} //end of if (this.isClear())
		else { // there is error just prints the error message
			os << this->errorMsg() << endl;
		}

		return os;
	}
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
	std::istream& Product::read(std::istream& is) {

		//Product lProd;
		char sku[max_sku_length + 1];
		char unit[max_unit_length + 1];
		char* name;
		name = new char[20];
		double price;
		char taxed;
		bool isTax;
		int quantity;
		int qtyNeeded;
		ErrorState error;

		while (!is.fail()) {  //check if the istream is in fail state

			//Get SKU
			cout << " Sku: ";
			cin.getline(sku, max_sku_length);

			//Get NAME
			cout << " Name (no spaces): ";
			cin.getline(name, 20);

			//Get UNIT
			cout << " Unit: ";
			cin.getline(unit, max_unit_length);

			//Get TAXED
		
			cout << " Taxed? (y/n): ";
			is >> taxed;
			if (taxed == 'Y' || taxed == 'y')
			{
				isTax = true;
				is.clear();
			}
			else {
				if (taxed == 'N' || taxed == 'n') {
					isTax = false;
					is.clear();
				}
				else {
					error.message("Only (Y)es or (N)o are acceptable");
					is.setstate(ios::failbit); //set the fail bit
					break;
				}
			}

			//Get PRICE
			cout << " Price: ";
			if (is >> price) {   //test if input is a double
				is.clear();
			}
			else
			{
				error.message("Invalid Price Entry");
				break;
			}

			//Get QUANTITY
			cout << " Quantity on hand: ";
			if (is >> quantity) {
				is.clear();
			}
			else
			{
				error.message("Invalid Quantity Entry");
				break;
			}

			//Get NEED
			cout << " Quantity needed: ";
			if (is >> qtyNeeded) {
				is.clear();
			}
			else
			{
				error.message("Invalid Quantity Needed Entry");
				break;
			}

		is.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		break;
		} //while (!is.fail()) 

		if (error.isClear()) {   //no error message around, go straight
			strcpy(this->_SKU, sku);
			this->name(name);
			strcpy(this->_Unit, unit);
			this->_IsTaxable = isTax;
			this->_Price = price;
			this->_Quant = quantity;
			this->_Need = qtyNeeded;
			//lProd._Error.message(error.message()); //this line is no working when used in the copy constructor bellow, why? 
			this->_Error.message(error.message());
		}
		else { //if there is an error, only uses the error message
			this->_Error.message(error.message());
		}

		return is;
	}
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------


	//--------------------------------------------------
	bool Product::operator==(const char*s) const {
		bool result = false;
		if (strcmp(_SKU, s) == 0) {
			result = true;
		}
		return result;
	}
	//--------------------------------------------------
	bool Product::operator>(const char*s) const {
		return strcmp(_SKU, s) > 0;

	}
	//--------------------------------------------------
	bool Product::operator>(const iProduct&p) const {
		return strcmp(_Name, p.name()) > 0;
	}
	//--------------------------------------------------
	int Product::operator+=(int q) {
		this->_Quant += q;
		return this->_Quant;
	}

	//--------------------------------------------------
	const char* Product::sku() const { return _SKU; }
	const char* Product::name() const { return _Name; }
	const char* Product::unit() const { return _Unit; }
	bool Product::taxed() const { return _IsTaxable; }
	double Product::price() const { return _Price; }
	double Product::total_cost() const { return (_Quant *(this->cost())); }
	void Product::quantity(int q) { _Quant = q; }
	int Product::quantity() const { return _Quant; }
	int Product::qtyNeeded() const { return _Need; }
	void Product::message(const char*s) { _Error.message(s); }
	bool Product::isClear() const { return _Error.isClear(); }
	void Product::type(const char c)  { _Type = c; }
	char Product::type() { return _Type; }


	const char* Product::errorMsg()const {
		return this->_Error.message();
	}

	double Product::cost() const { 
		double cost;
		if (this->_IsTaxable) {
			cost = (_Price + (_Price * TAX_RATE));
		}
		else {
			cost = _Price;
		}
		return cost;
	}


	bool Product::isEmpty() const {
		bool empty = false;
		if (strcmp(_SKU, "") == 0) {
			empty = true;
		}
		return empty;
	}
	//-------------------------------------------------------
	Product::~Product() {
		if (this->_Name == nullptr) {
			delete[] this->_Name;
			this->_Name = nullptr;
		}
	}
	//-------------------------------------------------------
	//END OF CLASS FUNTIONS

	//BEGIN OF FRIEND FUNCTIONS

	std::ostream& operator<<(std::ostream& os, const iProduct&p) {
		p.write(os, true);
		return os;
	}
	std::istream& operator>>(std::istream& is, iProduct& p) {
		p.read(is);
		return is;
	}
	double operator+=(double& d, const iProduct& p) {
		return (p.total_cost() + d);
	}
	//END OF FRIEND FUNCTIONS
}