#include "Component.h"

// Constructor implementation
Component::Component
(
    const std::string& manufacturer,
    const std::string& name,
    int price,
    int stock,
    int type,
    bool laptop
)
    : manufacturer(manufacturer), name(name), price(price),stock(stock), type(type), islaptop(laptop) {}

// Getters implementation
std::string Component::getManufacturer() const { return manufacturer; }
std::string Component::getName() const { return name; }
int Component::getPrice() const { return price; }
int Component::getStock() const { return stock; }
int Component::getType() const { return type; }
bool Component::isLaptopComponent() const { return islaptop; }

// Setters implementation
void Component::setManufacturer(const std::string& newManufacturer) {
    manufacturer = newManufacturer;
}
void Component::setName(const std::string& newName) {
    name = newName;
}
void Component::setPrice(int newPrice) { 
    price = newPrice; 
}
void Component::setStock(int newStock) { 
    stock = newStock; 
}
void Component::setType(int newType) {
    type = newType;
}
void Component::setLaptop(bool newLaptop) {
	islaptop = newLaptop;
}

// Destructor implementation
Component::~Component() {}


// string implementation
std::string Component::getDetails() const {
    std::stringstream ss;
    ss << "Manufacturer: " << manufacturer
        << ", Name: " << name
        << ", Price: " << price
        << ", Stock: " << stock
        // if type is 1, it is CPU and so on
        << ", Type: " << type << "-" << (type == 1 ? "CPU" : type == 2 ? "GPU" : type == 3 ? "HD" : type == 4 ? "MB" : type == 5 ? "Memory" : type == 6 ? "PS" : type == 0 ? "Case" : "Unknown")

        //if it is laptop yes, if it is not no
        << ", LaptopComponent: " <<  (islaptop ? "Yes" : "No");
    return ss.str();
}