#ifndef MB_H
#define MB_H
#include "Component.h"

//type 4 = mb
class MB :
    public Component
{
private:
    int socket;
    int memoryslots;
    std::string size;
public:
    MB
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
	);
	// Getters
	int getSocket() const;
	int getMemoryslots() const;
	std::string getSize() const;
	// Setters
	void setSocket(const int socket);
	void setMemoryslots(const int memoryslots);
	void setSize(const std::string& size);
	//Destructor
	~MB() override; // Override the base class destructor
	// string
	std::string getDetails() const override; // Override the base class method
}; 
#endif  // COMPONENT_H

