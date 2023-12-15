#include "HD.h"

HD::HD
(
	const std::string& manufacturer,
	const std::string& name,
	int price,
	int stock,
	int type,
	bool islaptop,
	int speed,
	int size,
	const std::string& slot
)
	: Component(manufacturer, name, price, stock, type, islaptop), speed(speed), size(size), slot(slot) {}

// Getters implementation
int HD::getSpeed() const { return speed; }
int HD::getSize() const { return size; }
std::string HD::getSlot() const { return slot; }

// Setters implementation
void HD::setSpeed(const int newSpeed) {
	speed = newSpeed;
}
void HD::setSize(const int newSize) {
	size = newSize;
}
void HD::setSlot(const std::string& newSlot) {
	slot = newSlot;
}

//Destructor implementation
HD::~HD() {}

// string implementation
std::string HD::getDetails() const {
	std::stringstream ss;
	ss << Component::getDetails() // Get the component details from the base class
		<< ", Speed: " << speed << " RPM"
		<< ", Size: " << size << " GB"
		<< ", Slot: " << slot;
	return ss.str();
}


