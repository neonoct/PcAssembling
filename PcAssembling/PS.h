#ifndef PS_H
#define PS_H
#include "Component.h"
#include <string>

//type 6 = ps
class PS :
    public Component
{
private:
    int power;
    int certification;
public:
    PS
    (
		const std::string& manufacturer,
		const std::string& name,
		int price,
		int stock,
		int type,
		bool islaptop,
		int power,
		int certification
	);
	// Getters
	int getPower() const;
	int getCertification() const;
	// Setters
	void setPower(const int power);
	void setCertification(const int certification);
	//Destructor
	~PS() override;
	// string
	std::string getDetails() const override; // Override the base class method

};
#endif // !PS_H