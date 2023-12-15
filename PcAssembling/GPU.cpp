#include "GPU.h"

GPU::GPU
(
	const std::string& manufacturer,
	const std::string& name,
	int price,
	int stock,
	int type,
	bool islaptop,
	int power,
	int busspeed
)
	: Component(manufacturer, name, price, stock, type, islaptop), power(power), busspeed(busspeed) {}

// Getters implementation
int GPU::getPower() const { return power; }
int GPU::getBusspeed() const { return busspeed; }

// Setters implementation
void GPU::setPower(const int newPower) {
	power = newPower;
}
void GPU::setBusspeed(const int newBusspeed) {
	busspeed = newBusspeed;
}

// Destructor implementation
GPU::~GPU() {}

// string implementation
std::string GPU::getDetails() const {
	std::stringstream ss;
	ss << Component::getDetails() // Get the component details from the base class
		<< ", Power: " << power 
		<< ", Busspeed: " << busspeed;
		
	return ss.str();
}
