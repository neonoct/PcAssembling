#include "CPU.h"

CPU::CPU
(
	const std::string& manufacturer,
	const std::string& name,
	int price,
	int stock,
	int type,
	bool islaptop,
	int speed,
	int cores,
	const std::string& socket
)
	: Component(manufacturer, name, price, stock, type, islaptop), speed(speed), cores(cores), socket(socket) {}

// Getters implementation
int CPU::getSpeed() const { return speed; }
int CPU::getCores() const { return cores; }
std::string CPU::getSocket() const { return socket; }

// Setters implementation
void CPU::setSpeed(const int newSpeed) {
	speed = newSpeed;
}
void CPU::setCores(const int newCores) {
	cores = newCores;
}
void CPU::setSocket(const std::string& newSocket) {
	socket = newSocket;
}

//Destructor
CPU::~CPU() {}

// string implementation
std::string CPU::getDetails() const {
	std::stringstream ss;
	ss << Component::getDetails() // Get the component details from the base class
		<< ", Speed: " << speed << "MHz"
		<< ", Cores: " << cores
		<< ", Socket: " << socket;
	return ss.str();
}

