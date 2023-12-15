#include "Invoice.h"
#include "Customer.h"
#include "Component.h"
#include "Company.h"
#include <string>
#include <vector>

Invoice::Invoice
(
	int invoiceId,
	Customer* customer,
	std::vector<Component*> components
)
	: invoiceId(invoiceId), customer(customer), components(components), totalPrice(calcTotalPrice(components, customer)) {}

// Getters implementation
int Invoice::getInvoiceId() const { return invoiceId; }
Customer* Invoice::getCustomer() { return customer; }
std::vector<Component*>& Invoice::getComponents()  { return components; }
float Invoice::getTotalPrice() const { return totalPrice; }

// Setters implementation
void Invoice::setInvoiceId(const int newInvoiceId) {
	invoiceId = newInvoiceId;
}
void Invoice::setCustomer(Customer* newCustomer ) {
	customer = newCustomer;
}
void Invoice::setComponents(std::vector<Component*>& newComponents) {
	components = newComponents;
}
void Invoice::setTotalPrice(const float newTotalPrice) {
	totalPrice = newTotalPrice;
}

//calc
float Invoice::calcTotalPrice(std::vector<Component*>& components,Customer* customer){
	float totalPrice = 0;
	for (int i = 0; i < components.size(); i++) {
		totalPrice += components[i]->getPrice();
	}
	if (customer->isCompany()) {//if customer is company he gets discount as much as reduction
		Company* company = dynamic_cast<Company*>(customer);
		if(company){
			totalPrice -= totalPrice * company->getReduction() / 100;
		}
	}
	return totalPrice;
}