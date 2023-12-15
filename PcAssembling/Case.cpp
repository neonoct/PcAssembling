#include "Case.h"

Case::Case
(
	const std::string& manufacturer,
	const std::string& name,
	int price,
	int stock,
	int type,
	bool islaptop,
	const std::string& color,
	const std::string& MBsize,
	const std::string& Material
)
	: Component(manufacturer, name, price, stock, type, islaptop), color(color), MBsize(MBsize), Material(Material) {}

// Getters implementation
std::string Case::getColor() const { return color; }
std::string Case::getMBsize() const { return MBsize; }
std::string Case::getMaterial() const { return Material; }

// Setters implementation
void Case::setColor(const std::string& newColor) {
	color = newColor;
}
void Case::setMBsize(const std::string& newMBsize) {
	MBsize = newMBsize;
}
void Case::setMaterial(const std::string& newMaterial) {
	Material = newMaterial;
}

//Destructor
Case::~Case() {}

// string implementation
std::string Case::getDetails() const {
	std::stringstream ss;
	ss << Component::getDetails() // Get the component details from the base class
		<< ", Color: " << color
		<< ", Motherboard Size: " << MBsize
		<< ", Material: " << Material;
	return ss.str();
}