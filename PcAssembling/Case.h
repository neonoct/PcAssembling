#ifndef CASE_H
#define CASE_H
#include "Component.h"
#include <string>

//type 0 = case
class Case :
	public Component
{
private:
	std::string color;

	std::string MBsize;

	std::string Material;
public:
	Case
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
	);
	// Getters
	std::string getColor() const;
	std::string getMBsize() const;
	std::string getMaterial() const;
	// Setters
	void setColor(const std::string& color);
	void setMBsize(const std::string& MBsize);
	void setMaterial(const std::string& Material);
	//Destructor
	~Case() override;
	// string
	std::string getDetails() const override; // Override the base class method
};
#endif // CASE_H

