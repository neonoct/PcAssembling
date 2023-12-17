#ifndef COMPANY_H
#define COMPANY_H
#include "Customer.h"


class Company :
    public Customer
{
private:
	std::string vat;
	int reduction;
	int yearlyBuy;
	//calc
	int calcReduction() const;
public:
	Company
	(
		const std::string& name,
		const std::string& address,
		bool company,
		const std::string& vat,
		//int reduction, -- this is excluded because it is calculated
		int yearlyBuy
	);
	// Getters
	std::string getVat() const;
	int getReduction() const;
	int getYearlyBuy() const;
	// Setters
	void setVat(const std::string& vat);
	void setReduction(const int reduction);
	void setYearlyBuy(const int yearlyBuy);
	//Destructor
	~Company() override;
	// string
	std::string getDetails() const override; // Override the base class method
	

};
#endif // COMPANY_H
