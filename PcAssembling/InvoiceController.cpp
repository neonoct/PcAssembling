#include "InvoiceController.h"
#include <set>
//gotto work on this errors int to float,returning the address of local variable or temporary


void showInvoice(Invoice* invoice) {
	// Display the invoice details
	std::cout << "Invoice ID: " << invoice->getInvoiceId() << std::endl;
	std::cout << "Customer: " << invoice->getCustomer()->getName() << std::endl;
	std::cout << "Total price: " << invoice->getTotalPrice() << std::endl;
	std::cout << "Components: " << std::endl;
	for (Component* comp : invoice->getComponents()) {
		std::cout << " - " << comp->getName() << std::endl;
	}
}

Invoice* buildSystem(std::vector<Customer*>& customers, std::vector<Component*>& components) {
	//first ask which client is buying
	//if there are no customers return to main menu
	if (customers.size() == 0) {
		std::cout << "no customers" << std::endl;
		return nullptr;
	}

	showCustomers(customers);
	std::cout <<"choose the client(index) to build the system for: "<< std::endl;
	int customerIndex;
	std::cin >> customerIndex;
	Customer* customer = customers[customerIndex];
	//if customer is empty return to main menu
	if (customer == nullptr) {
		std::cout << "no customer at selected index" << std::endl;
		return nullptr;
	}

	//then build the system
	//std::vector<Component*>& selectedComponents = buildSystem(customer, components);
	//prompt user to select what kind of system he wants to build(laptop or desktop)
	std::cout << "choose the type of system you want to build" << std::endl;
	std::cout << "1. Laptop" << std::endl;
	std::cout << "2. Desktop" << std::endl;
	int systemType;
	std::cin >> systemType;
	bool isLaptop = true;
	if (systemType == 2) {isLaptop = false;}
	//if there aren't enough components to build the system in the selected type, display an error message and return to the main menu
	if (checkComponents(components, isLaptop) == false) {
		std::cout << "not enough components to build the system" << std::endl;
		return nullptr;
	}
	//now select the components
	std::vector<Component*> selectedComponents;
	//selectComponents(selectedComponents,components, isLaptop);
	if (selectComponents(selectedComponents, components, isLaptop) == false) {
		std::cout << "not enough stock to build the system" << std::endl;
		return nullptr;
	}
	//test working
	//std::cout << "!!!!!!!!" << std::endl;
	//std::cout << selectedComponents[0]->getDetails() << std::endl;
	//std::cout << "workworkwork" << std::endl;

	//create invoice
	Invoice* invoice = createInvoice(customer, selectedComponents);
	//if the invoice is not created display an error message and return to the main menu
	// else return the invoice
	if (invoice == nullptr) {
		std::cout << "invoice not created" << std::endl;
		return nullptr;
	}
	return invoice;
	
}

bool checkComponents(std::vector<Component*>& components,bool isLaptop) {
	//in the vector of components check if there are enough components to build a system there should be at least one component from every category
	//if there are enough components return true
	//if there aren't enough components return false
	int count = 0;
	std::set<int> foundTypes;
		for (int i = 0; i < components.size(); i++) {
			if (components[i]->isLaptopComponent() == isLaptop) {
				foundTypes.insert(components[i]->getType());
			}
		}
		std::cout << "found types" << std::endl;
		std::cout << foundTypes.size() << std::endl;
		std::cout << "found types" << std::endl;
		if (foundTypes.size() == 7) {
			return true;
		}
		else {
			return false;
		}

}

bool selectComponents(std::vector<Component*>& selectedComponents, std::vector<Component*>& components, bool isLaptop) { 
	//prompt the user to select components from every category
	
	std::cout << "select components from every category" << std::endl;//can be done in a better way with a loop
	std::cout << "1. CPU:" << std::endl;
	selectedComponents.push_back(chooseSpecificComponents(components, ComponentType::CPU, isLaptop));
	if (selectedComponents[0] == nullptr) {return false;}
	//test working
	//std::cout << "!!!!!!!!" << std::endl;
	//std::cout << selectedComponents[0]->getDetails() << std::endl;
	//std::cout << "!!!!!!!!" << std::endl;
	std::cout << "2. GPU:" << std::endl;
	selectedComponents.push_back(chooseSpecificComponents(components, ComponentType::GPU, isLaptop));
	if (selectedComponents[1] == nullptr) { return false; }
	std::cout << "3. HD:" << std::endl;
	selectedComponents.push_back(chooseSpecificComponents(components, ComponentType::HD, isLaptop));
	if (selectedComponents[2] == nullptr) { return false; }
	std::cout << "4. MB:" << std::endl;
	selectedComponents.push_back(chooseSpecificComponents(components, ComponentType::MB, isLaptop));
	if (selectedComponents[3] == nullptr) { return false; }
	std::cout << "5. Memory:" << std::endl;
	selectedComponents.push_back(chooseSpecificComponents(components, ComponentType::Memory, isLaptop));
	if (selectedComponents[4] == nullptr) { return false; }
	std::cout << "6. PS:" << std::endl;
	selectedComponents.push_back(chooseSpecificComponents(components, ComponentType::PS, isLaptop));
	if (selectedComponents[5] == nullptr) { return false; }
	std::cout << "7. Case:" << std::endl;
	selectedComponents.push_back(chooseSpecificComponents(components, ComponentType::Case, isLaptop));
	if (selectedComponents[6] == nullptr) { return false; }

	//if there is a nullptr in the vector return false
	//for (int i = 0; i < selectedComponents.size(); i++) {
	//	if (selectedComponents[i] == nullptr) {
	//		return false;
	//	}
	//}

	//now drop the stock of the components from the components vector
	for (int i = 0; i < selectedComponents.size(); i++) {
		updateStock(selectedComponents[i], 1, false);
	}


	return true;
}

Component* chooseSpecificComponents(const std::vector<Component*>& components, ComponentType type, bool isLaptop) {//show function ile beraber calisabilir ?
	//cast the type to int
	int typeInt = static_cast<int>(type);
	int index = 0;
	int selectedIndex;
	int count = 0;
	if (components.empty()) {
		std::cout << "No components to display." << std::endl;
		return nullptr;
	}

	for (const auto& component : components) {

		if (component != nullptr && component->getType() == typeInt && component->isLaptopComponent() == isLaptop) {
			std::cout << index++ << ". ";
			std::cout << component->getDetails() << std::endl;
		}

	}

	std::cout << "Choose component: ";
	std::cin >> selectedIndex;

	for (const auto& component : components) {
		if (component != nullptr && component->getType() == typeInt && component->isLaptopComponent() == isLaptop) {
			if (selectedIndex == count) {
				std::cout << "Selected component: ";
				std::cout << component->getDetails() << std::endl;
				std::cout << "returned: " << std::endl;
				//it stock of the component is 0 return nullptr
				if (component->getStock() == 0) {
					std::cout << "stock is 0 returning nullptr" << std::endl;
					return nullptr;
				}
				return component;
			}
			count++;
		}
	}

	return nullptr;
}

Invoice* createInvoice(Customer* customer, std::vector<Component*>& components) {
	Invoice* invoice;
	int id;
	//create a unique id for the invoice
	id = generateUniqueID();
	invoice = new Invoice(id, customer, components);

	//show invoice
	showInvoice(invoice);

	return invoice;

}

int generateUniqueID() {
	static int lastID = 999; // Initialize to 999 so the first ID will be 1000
	return ++lastID; // Increment and return the new ID
}
