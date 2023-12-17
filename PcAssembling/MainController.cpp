#include "MainController.h"
#include "ComponentController.h"
#include "CustomerController.h"
#include "ComputerShop.h"
#include "InvoiceController.h"
#include <iostream>
using namespace std;


void ownerActions(ComputerShop* computerShop) {
    int action;
        
    do {
        cout << "Owner Menu:\n";
        cout << "1. Create category\n";
        cout << "2. Change category\n";
        cout << "3. Delete category\n";
        cout << "4. Add client\n";
        cout << "5. Update client\n";
        cout << "6. Delete client\n";
        cout << "7. Delete component\n";
        cout << "8. Add component\n";
        cout << "9. Update component\n";
        cout << "10. Update stock\n";
        cout << "0. Return to main menu\n";
        cout << "Enter action:\n ";
        cin >> action;

        switch (action) {
        case 1:
            cout << "Create component category selected.\n----------------------------\n";
            // Placeholder for future function
            cout << "this part is not implemented yet\n";
            break;
        case 2:
            cout << "Change component category selected.\n----------------------------\n";
            // Placeholder for future function
            cout << "this part is not implemented yet\n";
            break;
        case 3:
            cout << "Delete component category selected.\n----------------------------\n";
            // Placeholder for future function
            cout << "this part is not implemented yet\n";
            break;
        case 4:
            cout << "Add client selected.\n----------------------------\n";
            addCustomer(computerShop->getCustomers());
            break;
        case 5:
            cout << "Update client selected.\n----------------------------\n";
            updateCustomer(computerShop->getCustomers());
            break;
        case 6:
            cout << "Delete client selected.\n----------------------------\n";
            deleteCustomer(computerShop->getCustomers());
            break;
        case 7:
            cout << "Delete component selected.\n----------------------------\n";
            showComponents(computerShop->getComponents());
            cout << "Enter the index of the component you want to delete: ";
            int delIndex;
            cin >> delIndex;
            if (delIndex < 0 || delIndex >= computerShop->getComponents().size()) {
                cout << "Invalid index.No component at index " << delIndex << "\n";
            }
            else deleteComponent(computerShop->getComponents(), delIndex);
            break;
        case 8:
            cout << "Add component selected.\n----------------------------\n";
            //function to add component
            addComponent(computerShop->getComponents());
            break;
        case 9:
            cout << "Update component selected.\n----------------------------\n";
            showComponents(computerShop->getComponents());
            cout << "Enter the index of the component you want to update: ";
            int index;
            cin >> index;
            if (index < 0 || index >= computerShop->getComponents().size()) {
                cout << "Invalid index.No component at index " << index << "\n";
            }
            else updateComponent(computerShop->getComponents(), index);
            break;
        case 10:
            cout << "Update stock selected.\n----------------------------\n";
            showComponents(computerShop->getComponents());
            cout << "Enter the index of the component whose stock level you want to update: ";
            int stockIndex;
            cin >> stockIndex;
            // Input validation
            if (stockIndex < 0 || stockIndex >= computerShop->getComponents().size()) {
                std::cout << "Invalid index. No component at index " << stockIndex << "\n";
            }
            else {
                // Ask user for update option
                std::cout << "Select update option:\n";
                std::cout << "1. Set new stock level\n";
                std::cout << "2. Adjust stock level\n";
                int updateOption;
                std::cin >> updateOption;

                if (updateOption == 1) {
                    int newStock;
                    std::cout << "Enter new stock level: ";
                    std::cin >> newStock;
                    updateStock(computerShop->getComponents()[stockIndex], newStock);
                }
                else if (updateOption == 2) {
                    int stockChange;
                    bool increase;
                    std::cout << "Enter stock change amount: ";
                    std::cin >> stockChange;
                    std::cout << "Should this amount be added? (1 for yes, 0 for no): ";
                    std::cin >> increase;
                    updateStock(computerShop->getComponents()[stockIndex], stockChange, increase);
                }
                else {
                    std::cout << "Invalid option selected.\n";
                }
            }
            break;
        case 0:
            break;
        default:
            cout << "Invalid action. Please try again.\n----------------------------\n";
        }
    } while (action != 0);

}



void employeeActions(ComputerShop* computerShop, std::vector<Invoice*>& invoices) {
    int action;
  
    do {
        cout << "Employee Menu:\n";
        cout << "1. Add client\n"; 
        cout << "2. Update client\n";
        cout << "3. Build system\n";
        cout << "0. Return to main menu\n";
        cout << "Enter action: ";
        cin >> action;

        switch (action) {
        case 1:
            cout << "Add client selected.\n--------------------------\n";
            addCustomer(computerShop->getCustomers());
            break;
        case 2:
            cout << "Update client selected.\n--------------------------\n";
            updateCustomer(computerShop->getCustomers());
            break;
        case 3:
            cout << "Build system selected.\n--------------------------\n";
            //add invoice to the list of invoices
            invoices.push_back(buildSystem(computerShop->getCustomers(), computerShop->getComponents()));
            break;
        case 0:
            cout << "Returning to main menu.\n--------------------------\n";
            break;
        default:
            cout << "Invalid action. Please try again.\n--------------------------\n";
        }
    } while (action != 0);
}


