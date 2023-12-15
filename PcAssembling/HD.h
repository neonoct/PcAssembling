#ifndef HD_H
#define HD_H
#include "Component.h"
#include <string>

//type 3 = hd
class HD :
    public Component
{
private:
	int speed;
	int size;
	std::string slot;
public:
	HD
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
	);
	// Getters
	int getSpeed() const;
	int getSize() const;
	std::string getSlot() const;
	// Setters
	void setSpeed(const int speed);
	void setSize(const int size);
	void setSlot(const std::string& slot);
	// Destructor
	~HD() override;
	// string
	std::string getDetails() const override; // Override the base class method
};
#endif // HD_H
