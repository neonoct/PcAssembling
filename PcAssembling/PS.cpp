#include "PS.h"

PS::PS
(
	const std::string& manufacturer,
	const std::string& name,
	int price,
	int stock,
	int type,
	bool islaptop,
	int power,
	int certification
)
	: Component(manufacturer, name, price, stock, type, islaptop), power(power), certification(certification) {}

// Getters implementation
int PS::getPower() const { return power; }
int PS::getCertification() const { return certification; }

// Setters implementation
void PS::setPower(const int newPower) {
	power = newPower;
}
void PS::setCertification(const int newCertification) {
	certification = newCertification;
}

//Destructor implementation
PS::~PS() {}

// string implementation
std::string PS::getDetails() const {
	std::stringstream ss;
	ss << Component::getDetails() // Get the component details from the base class
		<< ", Power: " << power << " W"
		<< ", Certification: " << certification << " Plus";
	return ss.str();
}