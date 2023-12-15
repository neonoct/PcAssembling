#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

class Customer {
private:
    std::string name;
    std::string address;
    bool company;

public:
    Customer
    (
        const std::string& name,
        const std::string& address,
        bool company
    );  // Parameterized constructor declaration

    // Accessors 
    std::string getName() const;
    std::string getAddress() const;
    bool isCompany() const;
    
    //Mutators
    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setCompany(bool company);

    // Destructor
    virtual ~Customer();

    // string
    virtual std::string getDetails() const; // Virtual method
};

#endif // CUSTOMER_H

