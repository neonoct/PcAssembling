// Customer.cpp
#include "Customer.h"

// Parameterized constructor definition
Customer::Customer
(
    const std::string& name,
    const std::string& address,
    bool company
)
    : name(name), address(address), company(company) {}

// Accessors
std::string Customer::getName() const {
    return name;
}
std::string Customer::getAddress() const {
    return address;
}
bool Customer::isCompany() const {
    return company;
}

//mutators
void Customer::setName(const std::string& newName) {
    name = newName;
}
void Customer::setAddress(const std::string& newAddress) {
    address = newAddress;
}
void Customer::setCompany(bool newCompany) {
    company = newCompany;
}

// Destructor
Customer::~Customer() {}

// string
std::string Customer::getDetails() const {
	std::string details = "Name: " + name + "\nAddress: " + address + "\n";
    if (company) {
		details += "Company: Yes\n";
	}
    else {
		details += "Company: No\n";
	}
	return details;
}