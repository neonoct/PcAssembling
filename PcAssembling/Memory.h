#ifndef MEMORY_H
#define MEMORY_H
#include "Component.h"

//type 5 = memory
class Memory :
    public Component
{
private:
	int size;
	int speed;
public:
	Memory
	(
		const std::string& manufacturer,
		const std::string& name,
		int price,
		int stock,
		int type,
		bool islaptop,
		int size,
		int speed
	);
	// Getters
	int getSize() const;
	int getSpeed() const;
	// Setters
	void setSize(const int size);
	void setSpeed(const int speed);
	//Destructor
	~Memory() override;
	// string
	std::string getDetails() const override; // Override the base class method
};
#endif // MEMORY_H
