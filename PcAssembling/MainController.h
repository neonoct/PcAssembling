#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "Component.h"
#include "Customer.h"
#include "ComputerShop.h"
#include "Invoice.h"
#include <vector>
using namespace std;

//functioons owneractions and employeeactions accept a ComputerShop object as a parameter
void ownerActions(ComputerShop* computerShop);
void employeeActions(ComputerShop* computerShop, std::vector<Invoice*>& invoices);



#endif // !MAINCONTROLLER_H

