#ifndef INVOICECONTROLLER_H
#define INVOICECONTROLLER_H
#include "Invoice.h"
#include "Customer.h"
#include "Component.h"
#include "ComputerShop.h"
#include "ComponentController.h"
#include "CustomerController.h"
#include <vector>
#include <iostream>
#include <map>
#include <stdexcept>


void showInvoice(Invoice* invoice);

bool checkComponents(std::vector<Component*>& components, bool isLaptop);
Invoice* buildSystem(std::vector<Customer*>& customers, std::vector<Component*>& components);
Component* chooseSpecificComponents(const std::vector<Component*>& components, ComponentType type, bool isLaptop);
bool selectComponents(std::vector<Component*>& selectedComponents, std::vector<Component*>& components, bool isLaptop);
int generateUniqueID();
Invoice* createInvoice(Customer* customer, std::vector<Component*>& components);

#endif // !INVOICECONTROLLER_H

