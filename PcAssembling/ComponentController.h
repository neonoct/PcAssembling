#ifndef COMPONENTCONTROLLER_H
#define COMPONENTCONTROLLER_H
#include "Case.h"
#include "CPU.h"
#include "GPU.h"
#include "HD.h"
#include "MB.h"
#include "Memory.h"
#include "PS.h"
#include <vector>
#include <memory>
constexpr auto COMPONENTS_FILE = "files/components.txt";

void addComponent(std::vector<Component*>& components);
void addCPU(std::vector<Component*>& components);
void addGPU(std::vector<Component*>& components);
void addHD(std::vector<Component*>& components);
void addMB(std::vector<Component*>& components);
void addMemory(std::vector<Component*>& components);
void addPS(std::vector<Component*>& components);
void addCase(std::vector<Component*>& components);

void updateComponent(std::vector<Component*>& components,int index);
void updateComponentBase(Component* component);

void updateStock(Component* component, int newStock);
void updateStock(Component* component, int changeInStock, bool isIncrease);

void deleteComponent(std::vector<Component*>& components, int index);

void showComponents(const std::vector<Component*>& components);

void testComponentController(std::vector<Component*>& components);//for testing delete later
void readComponents(std::vector<Component*>& components, const std::string& filename);

//a function to show specific component according to the pc or laptop
void showIsLaptopComponents(const std::vector<Component*>& components, bool isLaptop);

//a function to show specific component according to the pc or laptop and type
void showSpecificComponents(const std::vector<Component*>& components, ComponentType type, bool isLaptop);

//overload the function to show specific component according to the type
void showSpecificComponents(const std::vector<Component*>& components, ComponentType type);

int findCompTypeFromFile(const std::string& line);

void writeComponents(const std::vector<Component*>& components, const std::string& filename);




#endif // !COMPONENTCONTROLLER_H

