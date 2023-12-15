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
        cout << "11. Show components--test\n";
        cout << "12. Add customers--test\n";
        cout << "13. Write customers--test\n";
        cout << "14. Write components--test\n";
        cout << "0. Return to main menu\n";
        cout << "Enter action:\n ";
        cin >> action;

        switch (action) {
        case 1:
            cout << "Create component category selected.\n----------------------------\n";
            // Placeholder for future function

            break;
        case 2:
            cout << "Change component category selected.\n----------------------------\n";
            // Placeholder for future function
            break;
            // Add cases for each owner action
        case 3:
            cout << "Delete component category selected.\n----------------------------\n";
            // Placeholder for future function
            break;
        case 4:
            cout << "Add client selected.\n----------------------------\n";
            // Placeholder for future function
            addCustomer(computerShop->getCustomers());
            break;
        case 5:
            cout << "Update client selected.\n----------------------------\n";
            // Placeholder for future function
            updateCustomer(computerShop->getCustomers());
            break;
        case 6:
            cout << "Delete client selected.\n----------------------------\n";
            // Placeholder for future function
            deleteCustomer(computerShop->getCustomers());
            break;
        case 7:
            cout << "Delete component selected.\n----------------------------\n";
            // Placeholder for future function
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
            // Placeholder for future function
            //function to add component
            addComponent(computerShop->getComponents());
            break;
        case 9:
            cout << "Update component selected.\n----------------------------\n";
            // Placeholder for future function
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
            // Placeholder for future function
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
        case 11://test too
            cout << "Show components selected.\n----------------------------\n";
			// Placeholder for future function
			//make a menu
            cout << "1. Show all components\n";
            cout << "2. Show laptop components\n";
            cout << "3. Show pc components\n";
            cout << "4. Show laptop CPU components\n";
            cout << "5. Show laptop GPU components\n";
            cout << "6. Show laptop HD components\n";
            cout << "7. Show laptop MB components\n";
            cout << "8. Show laptop Memory components\n";
            cout << "9. Show laptop PS components\n";
            cout << "10. Show laptop Case components\n";
            cout << "11. Show pc CPU components\n";
            cout << "12. Show pc GPU components\n";
            cout << "13. Show pc HD components\n";
            cout << "14. Show pc MB components\n";
            cout << "15. Show pc Memory components\n";
            cout << "16. Show pc PS components\n";
            cout << "17. Show pc Case components\n";
            cout << "18. Show all Cpu components\n";
            cout << "19. Exit\n";
            cout << "Enter action: ";
            int showAction;
            cin >> showAction;
            switch (showAction) {
                case 1:
				    showComponents(computerShop->getComponents());
				    break;
                case 2:
                    showIsLaptopComponents(computerShop->getComponents(), true);
                    break;
                case 3:
					showIsLaptopComponents(computerShop->getComponents(), false);
					break;
				case 4:
                    showSpecificComponents(computerShop->getComponents(), ComponentType::CPU, true);
                    break;
                case 5:
                    showSpecificComponents(computerShop->getComponents(), ComponentType::GPU, true);
                    break;
                case 6:
					showSpecificComponents(computerShop->getComponents(), ComponentType::HD, true);
					break;
				case 7:
                    showSpecificComponents(computerShop->getComponents(), ComponentType::MB, true);
                    break;
                case 8:
                    showSpecificComponents(computerShop->getComponents(), ComponentType::Memory, true);
					break;
                case 9:
					showSpecificComponents(computerShop->getComponents(), ComponentType::PS, true);
					break;
				case 10:
					showSpecificComponents(computerShop->getComponents(), ComponentType::Case, true);
                    break;
                case 11:
                    showSpecificComponents(computerShop->getComponents(), ComponentType::CPU, false);
					break;
                case 12:
					showSpecificComponents(computerShop->getComponents(), ComponentType::GPU, false);
                    break;
                case 13:
                    showSpecificComponents(computerShop->getComponents(), ComponentType::HD, false);
                    break;
				case 14:
                    showSpecificComponents(computerShop->getComponents(), ComponentType::MB, false);
                    break;
                case 15:
                    showSpecificComponents(computerShop->getComponents(), ComponentType::Memory, false);
					break;
                case 16:
					showSpecificComponents(computerShop->getComponents(), ComponentType::PS, false); 
                    break;
                case 17:
                    showSpecificComponents(computerShop->getComponents(), ComponentType::Case, false);
                    break;
                case 18:
                    showSpecificComponents(computerShop->getComponents(), ComponentType::CPU);
                    break;
                case 19:
                    cout << "Returning to main menu.\n----------------------------\n";
                    break;
                default:
                    cout << "Invalid action. Please try again.\n----------------------------\n";
            }

			break;
		case 12:
			cout << "Add customers selected.\n----------------------------\n";
			// Placeholder for future function
			readCustomers(computerShop->getCustomers(), CUSTOMERS_FILE);
            showCustomers(computerShop->getCustomers());
			break;
        case 13:
			cout << "Write customers selected.\n----------------------------\n";
			// Placeholder for future function
			writeCustomers(computerShop->getCustomers(), CUSTOMERS_FILE);
			break;
        case 14:
            cout << "Write components selected.\n----------------------------\n";
			// Placeholder for future function
			writeComponents(computerShop->getComponents(), COMPONENTS_FILE);
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
        cout << "1. Add client\n"; //needs Search Client use-case
        cout << "2. Update client\n"; //needs Search Client use-case
        cout << "3. Build system\n";//needs Search Client use-case and Create Invovice use case
        cout << "4. test requirements\n";
        cout << "0. Return to main menu\n";
        cout << "Enter action: ";
        cin >> action;

        switch (action) {
        case 1:
            cout << "Add client selected.\n--------------------------\n";
            // Placeholder for future function
            addCustomer(computerShop->getCustomers());
            break;
        case 2:
            cout << "Update client selected.\n--------------------------\n";
            // Placeholder for future function
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


