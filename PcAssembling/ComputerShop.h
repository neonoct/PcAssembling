#ifndef COMPUTER_SHOP_H
#define COMPUTER_SHOP_H
#include <vector>
#include "Component.h" 
#include "Customer.h" 

class ComputerShop {
private:
    std::string name;
    std::string address;
    std::vector<Component*> components; 
    std::vector<Customer*> customers; 

public:
    ComputerShop
    (
        const std::string& name,
        const std::string& address,
        std::vector<Component*> components,
        std::vector<Customer*> customers

    );

    // Getters
    std::string getName() const;
    std::string getAddress() const;
    std::vector<Component*>& getComponents();
    std::vector<Customer*>& getCustomers();

    // Setters
    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setComponents(std::vector<Component*>& components);
    void setCustomers(std::vector<Customer*>& customers);
    

    // Destructor
    ~ComputerShop();

   
};

#endif // COMPUTER_SHOP_H

