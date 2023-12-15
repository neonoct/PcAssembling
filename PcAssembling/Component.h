#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <sstream>

enum class ComponentType {
    Case=0,
    CPU,
    GPU,
    HD,
    MB,
    Memory,
    PS
    
};


class Component {
private:
    std::string manufacturer;
    std::string name;
    int price;
    int stock;
    int type;
    bool islaptop;

public:
    // Constructor
    Component
    (
        const std::string& manufacturer,
        const std::string& name,
        int price,
        int stock,
        int type,
        bool islaptop
    );

    // Getters 
    std::string getManufacturer() const;
    std::string getName() const;
    int getPrice() const;
    int getStock() const;
    int getType() const;
    bool isLaptopComponent() const;

    // Setters
    void setManufacturer(const std::string& manufacturer);
    void setName(const std::string& name);
    void setPrice(int price);// const can be removed because it is not a pointer or reference and it is already a copy for data types like int, double, char, etc.
    void setStock(int stock);// but for string it is a reference so const is needed
    void setType(int type);// but you can choose to keep it for int for better readability
    void setLaptop(bool laptop);

    // Destructor
    virtual ~Component(); // Virtual destructor

    //string
    virtual std::string getDetails() const;
};

#endif // COMPONENT_H


