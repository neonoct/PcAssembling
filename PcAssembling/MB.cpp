#include "MB.h"
#include <sstream>
#include <iostream>

MB::MB
(
	const std::string& manufacturer,
	const std::string& name,
	int price,
	int stock,
	int type,
	bool islaptop,
	int socket,
	int memoryslots,
	const std::string& size
)
	: Component(manufacturer, name, price, stock, type, islaptop), socket(socket), memoryslots(memoryslots), size(size) {}

// Getters implementation
int MB::getSocket() const { return socket; }
int MB::getMemoryslots() const { return memoryslots; }
std::string MB::getSize() const { return size; }

// Setters implementation
void MB::setSocket(const int newSocket) {
	socket = newSocket;
}
void MB::setMemoryslots(const int newMemoryslots) {
	memoryslots = newMemoryslots;
}
void MB::setSize(const std::string& newSize) {
	size = newSize;
}

// Destructor implementation
MB::~MB() {}

// string implementation
std::string MB::getDetails() const {
	std::stringstream ss;
	ss << Component::getDetails() // Get the component details from the base class
		<< ", Socket: " << socket
		<< ", Memory Slots: " << memoryslots
		<< ", Size: " << size;
	return ss.str();
}