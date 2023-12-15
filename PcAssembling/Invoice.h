#ifndef INVOICE_H
#define INVOICE_H
#include "Customer.h"
#include "Component.h"
#include <string>
#include <vector>

class Invoice
{
private:
	int invoiceId;
	Customer* customer;
	std::vector<Component*> components;
	float totalPrice;
	//calc
	float calcTotalPrice(std::vector<Component*>& components,Customer* customer);
public:
	Invoice
	(
		int invoiceId,
		Customer* customer,
		std::vector<Component*> components
	);
	// Getters
	int getInvoiceId() const;
	Customer* getCustomer();
	std::vector<Component*>& getComponents() ;// can be const ???
	float getTotalPrice() const;
	// Setters
	void setInvoiceId(const int invoiceId);
	void setCustomer( Customer* customer);
	void setComponents(std::vector<Component*>& components);
	void setTotalPrice(const float totalPrice);
};

#endif // INVOICE_H