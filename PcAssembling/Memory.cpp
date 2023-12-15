#include "Memory.h"

Memory::Memory
(
	const std::string& manufacturer,
	const std::string& name,
	int price,
	int stock,
	int type,
	bool islaptop,
	int size,
	int speed
)
	: Component(manufacturer, name, price, stock, type, islaptop), size(size), speed(speed) {}

// Getters implementation
int Memory::getSize() const { return size; }
int Memory::getSpeed() const { return speed; }

// Setters implementation
void Memory::setSize(const int newSize) {
	size = newSize;
}
void Memory::setSpeed(const int newSpeed) {
	speed = newSpeed;
}

//Destructor implementation
Memory::~Memory() {}

// string implementation
std::string Memory::getDetails() const {
	std::stringstream ss;
	ss << Component::getDetails() // Get the component details from the base class
		<< ", Size: " << size << " GB"
		<< ", Speed: " << speed << " MHz";
	return ss.str();
}


