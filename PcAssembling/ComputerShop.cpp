// ComputerShop.cpp
#include "ComputerShop.h"

ComputerShop::ComputerShop
(
    const std::string& name,
    const std::string& address,
    std::vector<Component*> components,
    std::vector<Customer*> customers
)
    : name(name), address(address), components(components), customers(customers) {}

// Getters implementation
std::string ComputerShop::getName() const {
    return name;
}
std::string ComputerShop::getAddress() const {
    return address;
}
std::vector<Component*>& ComputerShop::getComponents() {
    return components;
}
std::vector<Customer*>& ComputerShop::getCustomers() {
    return customers;
}

// Setters implementation
void ComputerShop::setName(const std::string& newName) {
    name = newName;
}
void ComputerShop::setAddress(const std::string& newAddress) {
    address = newAddress;
}
void ComputerShop::setComponents(std::vector<Component*>& newComponents) {
    components = newComponents;
}
void ComputerShop::setCustomers(std::vector<Customer*>& newCustomers) {
    customers = newCustomers;
}

// Destructor implementation
ComputerShop::~ComputerShop() {
	for (Component* component : components) {
		delete component;
	}
	for (Customer* customer : customers) {
		delete customer;
	}
}

// Other methods can be implemented here
