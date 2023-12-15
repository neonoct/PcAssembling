#include "Company.h"

Company::Company
(
	const std::string& name,
	const std::string& address,
	bool company,
	const std::string& vat,
	//int reduction,
	int yearlyBuy
)
	: Customer(name, address, company), vat(vat), yearlyBuy(yearlyBuy)//, reduction(reduction) -- this is excluded because it is calculated
{
	reduction = calcReduction(); // Calculate the reduction based on yearlyBuy
}

// Getters implementation
std::string Company::getVat() const { return vat; }
int Company::getReduction() const { return reduction; }
int Company::getYearlyBuy() const { return yearlyBuy; }

// Setters implementation
void Company::setVat(const std::string& newVat) {
	vat = newVat;
}
void Company::setReduction(const int newReduction) {
	reduction = newReduction;
}
void Company::setYearlyBuy(const int newYearlyBuy) {
	yearlyBuy = newYearlyBuy;
}

// Destructor
Company::~Company() {}

// string
std::string Company::getDetails() const {
	std::string details = Customer::getDetails();
	details += "VAT: " + vat + "\n";
	details += "Reduction: " + std::to_string(reduction) + "%\n";
	details += "Yearly Buy: " + std::to_string(yearlyBuy) + "\n";
	return details;
}

//private function calc
int Company::calcReduction() const {
	int reduction = 0;
	if (yearlyBuy < 1000) {
		reduction = 0;
	}
	else if (yearlyBuy >= 1000 && yearlyBuy < 2000) {
		reduction = 5;
	}
	else if (yearlyBuy >= 2000 && yearlyBuy < 5000) {
		reduction = 10;
	}
	else if (yearlyBuy >= 5000 && yearlyBuy < 10000) {
		reduction = 15;
	}
	else if (yearlyBuy >= 10000) {
		reduction = 20;
	}
	return reduction;
}

// Compare this snippet from PcAssembling/Component.h:

