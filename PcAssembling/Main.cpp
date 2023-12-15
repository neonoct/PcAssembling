#include "MainController.h"
#include "ComputerShop.h"
#include "ComponentController.h"
#include "CustomerController.h"
#include "InvoiceController.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

    int userType;
    //make a ComputerShop object and add customers(vector) and components(vector) to it
    vector<Invoice*> invoices;
    vector<Component*> components;
    vector<Customer*> customers;
    ComputerShop* computerShop = new ComputerShop ("ComputerShop", "Address", components, customers);

    //load components and customers from file
    readCustomers(computerShop->getCustomers(), CUSTOMERS_FILE);
    readComponents(computerShop->getComponents(), COMPONENTS_FILE);



    do {
        cout << "Please select your user type:\n";
        cout << "1. Owner\n";
        cout << "2. Employee\n";
        cout << "0. Exit\n";
        cout << "Enter choice: \n";
        cin >> userType;

        switch (userType) {
        case 1:
            ownerActions(computerShop);
            break;
        case 2:
            employeeActions(computerShop, invoices);
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid selection. Please try again.\n";
        }
    } while (userType != 0);

    //save components and customers to file
    writeCustomers(computerShop->getCustomers(), CUSTOMERS_FILE);
    writeComponents(computerShop->getComponents(), COMPONENTS_FILE);

    // Delete the computerShop when done to invoke its destructor and clean up
    delete computerShop;
    //Delete the invoices when done to invoke its destructor and clean up
    for (Invoice* invoice : invoices) {
        delete invoice; // Deletes the object pointed to by invoice
    }
    invoices.clear(); // Clears the vector of pointers

    return 0;
}