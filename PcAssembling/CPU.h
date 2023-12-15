#ifndef CPU_H
#define CPU_H
#include "Component.h"

//type 1 = cpu
class CPU :
    public Component
{
private:
	int speed;
	int cores;
	std::string socket;
public:
	CPU
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
	);
	// Getters
	int getSpeed() const;
	int getCores() const;
	std::string getSocket() const;
	// Setters
	void setSpeed(const int speed);
	void setCores(const int cores);
	void setSocket(const std::string& socket);
	//Destructor
	~CPU() override;
	// string
	std::string getDetails() const override; // Override the base class method
};

#endif // CPU_H

