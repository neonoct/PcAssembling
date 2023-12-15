#ifndef GPU_H
#define	GPU_H
#include "Component.h"
#include <string>

//type 2 = gpu
class GPU : 
	public Component 
{
private:
	int power;
	int busspeed;
public:
	GPU
	(
		const std::string& manufacturer,
		const std::string& name,
		int price,
		int stock,
		int type,
		bool islaptop,
		int power,
		int busspeed
	);
	// Getters
	int getPower() const;
	int getBusspeed() const;
	// Setters
	void setPower(const int power);
	void setBusspeed(const int busspeed);
	// Destructor
	~GPU() override;
	// string
	std::string getDetails() const override; // Override the base class method
};
#endif // GPU_H
