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
    //didnt load and write invoices as i was not sure if that was needed

    // display welcome message
    cout << "Welcome to the Computer Shop!\n";
    //display how user should use the program
    cout << "Please do not enter any spaces in your input.If you need to enter multiple words, use a dash(-) instead.\n";
    // for input types class diagram should be followed as i didnt have time to implement the input validation
    cout << "Please follow the class diagram for input types.\n";
    // please try to give correct input types as much as possible
    cout << "Please try to give correct input types as much as possible as the catch block is not implemented.\n";
    



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
    //didnt load and write invoices as i was not sure if that was needed

    // Delete the computerShop when done to invoke its destructor and clean up
    delete computerShop;
    //Delete the invoices when done to invoke its destructor and clean up
    for (Invoice* invoice : invoices) {
        delete invoice; // Deletes the object pointed to by invoice
    }
    invoices.clear(); // Clears the vector of pointers

    return 0;
}