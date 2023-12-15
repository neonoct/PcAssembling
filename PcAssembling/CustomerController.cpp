#include "CustomerController.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>

using namespace std;

void addCustomer(vector<Customer*>& customers) {
	string name;
	string address;
	bool company;
	string vat;
	//int reduction; -- not used but calculated
	int yearlyBuy;

	cout << "Enter customer name: ";
	cin >> name;
	cout << "Enter customer address: ";
	cin >> address;
	cout << "Is the customer a company? (1 for yes, 0 for no): ";
	cin >> company;

	if (company) {
		cout << "Enter customer VAT: ";
		cin >> vat;
		//cout << "Enter customer reduction: "; -- not used but calculated
		//cin >> reduction;
		cout << "Enter customer yearly buy: ";
		cin >> yearlyBuy;
		customers.push_back(new Company(name, address, company, vat, yearlyBuy));//reduction, -- not used excluded from constructor
	}
	else {
		customers.push_back(new Customer(name, address, company));
	}
	showCustomers(customers);
}	

void deleteCustomer(vector<Customer*>& customers) {
	int index;
	showCustomers(customers);
	cout << "Enter the index of the customer you want to delete: ";
	cin >> index;
	if (index >= 0 && index < customers.size()) {
		delete customers[index];
		customers.erase(customers.begin() + index);
		cout << "Customer deleted." << endl;
	}
	else {
		cout << "Invalid index." << endl;
	}
}

void updateCustomer(vector<Customer*>& customers) {
	int index;
	showCustomers(customers);
	cout << "Enter the index of the customer you want to update: ";
	cin >> index;
	if (index >= 0 && index < customers.size()) {
		string name;
		string address;
		bool company;
		string vat;
		//int reduction; -- not used but calculated
		int yearlyBuy;

		cout << "Enter customer name: ";
		cin >> name;
		cout << "Enter customer address: ";
		cin >> address;
		cout << "Is the customer a company? (1 for yes, 0 for no): ";
		cin >> company;

		if (company) {
			cout << "Enter customer VAT: ";
			cin >> vat;
			//cout << "Enter customer reduction: "; -- not used but calculated
			//cin >> reduction;
			cout << "Enter customer yearly buy: ";
			cin >> yearlyBuy;
			customers[index] = new Company(name, address, company, vat, yearlyBuy);//reduction, -- not used excluded from constructor
			cout << "Customer updated." << endl;
		}
		else {
			customers[index] = new Customer(name, address, company);
			cout << "Customer updated." << endl;
		}
	}
	else {
		cout << "Invalid index." << endl;
	}
}

void showCustomers(const vector<Customer*>& customers) {
    int index = 0;
    if (customers.empty()) {
        std::cout << "No customers to display." << std::endl;
        return;
    }

    for (const auto& customer : customers) {
        if (customer != nullptr) {
            std::cout << "Customer " << index++ << ": "<< std::endl;
			//draw a line
			std::cout << "------------------------" << std::endl;
            std::cout << customer->getDetails() << std::endl;
        }
    }
}

void readCustomers(vector<Customer*>& customers, const std::string& filename) {

	ifstream file(filename);
	if (!file.is_open()) {
		std::cout << "Error opening file " << filename << std::endl;
		return;
	}
	std::string line;

	while (getline(file, line)) {
		std::stringstream linestream(line);
		std::string _type;
		//std::getline(linestream, _type, ',');
		bool _type_ = findCustomerType(line);
		
		if (!_type_) {
			std::string _name, _address,_companyString;
			bool _company;

			linestream >> std::ws;
			linestream >> _name >> std::ws >> _address >> std::ws >> _companyString;
			_company = _companyString == "true" ? true : false;
			customers.push_back(new Customer(_name, _address, _company));
			
		}
		else{
			std::string _name, _address, _companyString, _vat;
			bool _company;
			int _yearlyBuy;

			linestream >> std::ws;
			linestream >> _name >> std::ws >> _address >> std::ws >> _companyString >> std::ws >> _vat >> std::ws >> _yearlyBuy;
			_company = _companyString == "true" ? true : false;
			customers.push_back(new Company(_name, _address, _company, _vat, _yearlyBuy));
			
		}
		
	}
	
	file.close();
}

bool findCustomerType(const std::string& line) {
	
	std::istringstream iss(line);
	
	std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss},
									std::istream_iterator<std::string>{} };
	
	if (tokens.size() < 3) {
		throw std::out_of_range("Less than three words in string.");
	}
	//return tokens[4]; // Indexing starts from 0, so the fifth word is at index 4.
	if (tokens[2] == "true") {
		return true;
	}
	return false;
}

void writeCustomers(const std::vector<Customer*>& customers, const std::string& filename) {
	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cout << "Error opening file " << filename << std::endl;
		return;
	}

	for (const auto& customer : customers) {
		if (customer->isCompany()) {
			// Dynamic cast to check if customer is actually a Company and to access Company-specific methods
			const auto& company = dynamic_cast<const Company*>(customer);
			if (company) {
				file << company->getName() << " " << company->getAddress() << " "
					<< "true " << company->getVat() << " " << company->getYearlyBuy() << std::endl;
			}
		}
		else {
			// It's a regular customer
			file << customer->getName() << " " << customer->getAddress() << " "
				<< "false" << std::endl;
		}
	}

	file.close();
}
