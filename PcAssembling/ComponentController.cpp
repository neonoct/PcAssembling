#include "ComponentController.h"
#include "ComponentController.h"
#include "CPU.h"  // Include other component headers as needed
#include <iostream>
#include <string>
#include <vector>
#include <fstream>




void addComponent(std::vector<Component*>& components) {
    //type 0 = case, type 1 = cpu, type 2 = gpu, type 3 = hd, type 4 = mb, type 5 = memory, type 6 = ps
    int choice;

    // Display a menu to choose the component type
    std::cout << "Select the component type:" << std::endl;
    //test
    std::cout << "-1. test(add some components with function)" << std::endl;
    std::cout << "0. test(add some components from file)" << std::endl;
    std::cout << "1. CPU" << std::endl;
    std::cout << "2. GPU" << std::endl;
    std::cout << "3. HD (Hard Drive)" << std::endl;
    std::cout << "5. Memory" << std::endl;
    std::cout << "6. PS (Power Supply)" << std::endl;
    std::cout << "4. MB (Motherboard)" << std::endl;
    std::cout << "7. Case" << std::endl;
    std::cout << "8. Exit" << std::endl;

    std::cin >> choice;

    // Create a new component based on the user's choice
    switch (choice) {
    //test
    case -1:
		testComponentController(components);
		break;
    case 0:
	    readComponents(components, COMPONENTS_FILE);
	    break;
    case 1:
        addCPU(components);
        break;
    case 2:
        addGPU(components);
        break;
    case 3:
        addHD(components);
        break;
    case 4:
        addMB(components);
        break;
    case 5:
        addMemory(components);
        break;
    case 6:
        addPS(components);
        break;
    case 7:
        addCase(components);
        break;
    case 8:
        std::cout << "Exiting the component addition menu." << std::endl;
        break;
    default:
        std::cout << "Invalid choice. Please select a valid option." << std::endl;
        break;
    }
    showComponents(components);
}

//test
void testComponentController(std::vector<Component*>& components) {
    // Add a few components to the list
    components.push_back(new CPU("Intel", "i7-9700K", 300, 10, 1, true, 3600, 8, "LGA1151"));
    components.push_back(new GPU("Nvidia", "RTX-2080", 700, 5, 2, true, 250, 14000));
    components.push_back(new HD("Seagate", "Barracuda", 50, 20, 3, true, 7200, 1000, "3.5\""));
    components.push_back(new MB("Asus", "ROG-Strix-Z390-E", 250, 10, 4, true, 1151, 4, "ATX"));
    components.push_back(new Memory("Corsair", "Vengeance-LPX", 100, 15, 5, true, 16, 3200));
    components.push_back(new PS("Corsair", "RMx-Series RM750x", 120, 10, 6, true, 750, 80));
    components.push_back(new Case("Corsair", "Crystal-570X-RGB", 180, 5, 0, true, "Black", "ATX", "Tempered-Glass"));
    //also add some components for pc but different characteristics
    components.push_back(new CPU("Intel", "i7-9700K", 300, 10, 1, false, 3600, 8, "LGA1151"));
    components.push_back(new GPU("Nvidia", "RTX-2080", 700, 5, 2, false, 250, 14000));
    components.push_back(new HD("Seagate", "Barracuda", 50, 20, 3, false, 7200, 1000, "3.5\""));
    components.push_back(new MB("Asus", "ROG-Strix-Z390-E", 250, 10, 4, false, 1151, 4, "ATX"));
    components.push_back(new Memory("Corsair", "Vengeance-LPX", 100, 15, 5, false, 16, 3200));
    components.push_back(new PS("Corsair", "RMx-Series-RM750x", 120, 10, 6, false, 750, 80));
    components.push_back(new Case("Corsair", "Crystal-570X RGB", 180, 5, 0, false, "Black", "ATX", "Tempered-Glass"));
    

}
void readComponents(std::vector<Component*>& components, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream linestream(line);
        std::string _type;
        //std::getline(linestream, _type, ',');
        int _type_ = findCompTypeFromFile(line);

        if (_type_ == 1) {
            std::string manufacturer, name, socket, isLaptopStr;
            int price, stock, type, speed, cores;
            bool isLaptop;

            

            // Ignore the leading whitespace after the comma
            linestream >> std::ws;

            //std::getline(linestream, manufacturer, ',');
            //manufacturer.erase(0, manufacturer.find_first_not_of("\"")); // Remove leading quote
            //manufacturer.erase(manufacturer.find_last_not_of("\"") + 1); // Remove trailing quote

            //std::getline(linestream, name, ',');
            //name.erase(0, name.find_first_not_of("\"")); // Remove leading quote
            //name.erase(name.find_last_not_of("\"") + 1); // Remove trailing quote

            linestream >> manufacturer >> std::ws >> name >> std::ws;
            linestream >> price >> std::ws >> stock >> std::ws >> type >> std::ws;
            linestream >> isLaptopStr >> std::ws >> speed >> std::ws >> cores >> std::ws >> socket >> std::ws;


            // Read laptopInput as string and then convert to bool
            //std::getline(linestream, isLaptopStr, ',');
            //std::cout << isLaptopStr << std::endl;
            isLaptop = (isLaptopStr == "true");

            //linestream >> speed >> std::ws >> cores >> std::ws;

            //std::getline(linestream, socket);
            //socket.erase(0, socket.find_first_not_of(" \"")); // Remove leading space and quote
            //socket.erase(socket.find_last_not_of("\"") + 1); // Remove trailing quote

            components.push_back(new CPU(manufacturer, name, price, stock, type, isLaptop, speed, cores, socket));
        }
        else if (_type_ == 2) {
            std::string manufacturer, name, isLaptopStr;
            int price, stock, type, power, busspeed;
            bool isLaptop;

            // Ignore the leading whitespace after the comma
            linestream >> std::ws;

            linestream >> manufacturer >> std::ws >> name >> std::ws;
            linestream >> price >> std::ws >> stock >> std::ws >> type >> std::ws;
            linestream >> isLaptopStr >> std::ws >> power >> std::ws >> busspeed >> std::ws;
            
            isLaptop = (isLaptopStr == "true");

            components.push_back(new GPU(manufacturer, name, price, stock, type, isLaptop, power, busspeed));

        }
        else if (_type_ == 3) {
			std::string manufacturer, name, slot, isLaptopStr;
			int price, stock, type, speed, size;
			bool isLaptop;

			// Ignore the leading whitespace after the comma
			linestream >> std::ws;

			linestream >> manufacturer >> std::ws >> name >> std::ws;
			linestream >> price >> std::ws >> stock >> std::ws >> type >> std::ws;
			linestream >> isLaptopStr >> std::ws >> speed >> std::ws >> size >> std::ws >> slot >> std::ws;
			
			isLaptop = (isLaptopStr == "true");

			components.push_back(new HD(manufacturer, name, price, stock, type, isLaptop, speed, size, slot));
        }
        else if (_type_ == 4) {
            std::string manufacturer, name, size, isLaptopStr;
            int price, stock, type, socket, memoryslots;
            bool isLaptop;

            // Ignore the leading whitespace after the comma
            linestream >> std::ws;

            linestream >> manufacturer >> std::ws >> name >> std::ws;
            linestream >> price >> std::ws >> stock >> std::ws >> type >> std::ws;
            linestream >> isLaptopStr >> std::ws >> socket >> std::ws >> memoryslots >> std::ws >> size >> std::ws;

            isLaptop = (isLaptopStr == "true");

            components.push_back(new MB(manufacturer, name, price, stock, type, isLaptop, socket, memoryslots, size));
        }
        else if (_type_ == 5) {
			std::string manufacturer, name, isLaptopStr;
			int price, stock, type, size, speed;
			bool isLaptop;

			// Ignore the leading whitespace after the comma
			linestream >> std::ws;

			linestream >> manufacturer >> std::ws >> name >> std::ws;
			linestream >> price >> std::ws >> stock >> std::ws >> type >> std::ws;
			linestream >> isLaptopStr >> std::ws >> size >> std::ws >> speed >> std::ws;

			isLaptop = (isLaptopStr == "true");

			components.push_back(new Memory(manufacturer, name, price, stock, type, isLaptop, size, speed));
		}
        else if (_type_ == 6) {
			std::string manufacturer, name, isLaptopStr;
			int price, stock, type, power, certification;
			bool isLaptop;

			// Ignore the leading whitespace after the comma
			linestream >> std::ws;

			linestream >> manufacturer >> std::ws >> name >> std::ws;
			linestream >> price >> std::ws >> stock >> std::ws >> type >> std::ws;
			linestream >> isLaptopStr >> std::ws >> power >> std::ws >> certification >> std::ws;

			isLaptop = (isLaptopStr == "true");

			components.push_back(new PS(manufacturer, name, price, stock, type, isLaptop, power, certification));
		}
        else if (_type_ == 0) {
			std::string manufacturer, name, color, MBsize, Material, isLaptopStr;
			int price, stock, type;
			bool isLaptop;

			// Ignore the leading whitespace after the comma
			linestream >> std::ws;

			linestream >> manufacturer >> std::ws >> name >> std::ws;
			linestream >> price >> std::ws >> stock >> std::ws >> type >> std::ws;
			linestream >> isLaptopStr >> std::ws >> color >> std::ws >> MBsize >> std::ws >> Material >> std::ws;

			isLaptop = (isLaptopStr == "true");

			components.push_back(new Case(manufacturer, name, price, stock, type, isLaptop, color, MBsize, Material));
        }
        // Handle other component types...
    }
    file.close();
}

int findCompTypeFromFile(const std::string& line) {
    std::istringstream iss(line);
    std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss},
                                    std::istream_iterator<std::string>{} };
    if (tokens.size() < 5) {
        throw std::out_of_range("Less than five words in string.");
    }
    //return tokens[4]; // Indexing starts from 0, so the fifth word is at index 4.
    return std::stoi(tokens[4]);
}




void addCPU(std::vector<Component*>& components) {
    std::string manufacturer, name, socket;
    int price, stock, type, speed, cores, laptopInput;
    bool isLaptop;
    
    type = 1; //type 1 = cpu
    // Prompt the user for CPU-specific details
    std::cout << "Enter CPU manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Enter CPU name: ";
    std::cin >> name;
    std::cout << "Enter CPU price: ";
    std::cin >> price;
    std::cout << "Enter CPU stock: ";
    std::cin >> stock;
    std::cout << "Enter CPU speed: ";
    std::cin >> speed;
    std::cout << "Enter CPU cores: ";
    std::cin >> cores;
    std::cout << "Enter CPU socket: ";
    std::cin >> socket;
    std::cout << "Is this a laptop CPU? (1 for yes, 0 for no): ";
    std::cin >> laptopInput;

    // Validate input and set isLaptop accordingly
    isLaptop = (laptopInput == 1);

    // Create a new CPU object and add it to the list of components
    CPU* cpu = new CPU(manufacturer, name, price, stock, type, isLaptop, speed, cores, socket);
    components.push_back(cpu);
}

void addGPU(std::vector<Component*>& components) {
    std::string manufacturer, name;
    int price, stock, type, power, busspeed, laptopInput;
    bool isLaptop;
    type = 2; //type 2 = gpu

    // Prompt the user for GPU-specific details
    std::cout << "Enter GPU manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Enter GPU name: ";
    std::cin >> name;
    std::cout << "Enter GPU price: ";
    std::cin >> price;
    std::cout << "Enter GPU stock: ";
    std::cin >> stock;
    std::cout << "Enter GPU power (in watts): ";
    std::cin >> power;
    std::cout << "Enter GPU bus speed (in MHz): ";
    std::cin >> busspeed;
    std::cout << "Is this GPU for a laptop? (1 for yes, 0 for no): ";
    std::cin >> laptopInput;

    // Validate input and set isLaptop accordingly
    isLaptop = (laptopInput == 1);

    // Create a new GPU object and add it to the list of components
    GPU* gpu = new GPU(manufacturer, name, price, stock, type, isLaptop, power, busspeed);
    components.push_back(gpu);
}

void addHD(std::vector<Component*>& components) {
    std::string manufacturer, name, slot;
    int price, stock, type, speed, size, laptopInput;
    bool isLaptop;
    type = 3; //type 3 = hd

    // Prompt the user for HD-specific details
    std::cout << "Enter HD manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Enter HD name: ";
    std::cin >> name;
    std::cout << "Enter HD price: ";
    std::cin >> price;
    std::cout << "Enter HD stock: ";
    std::cin >> stock;
    std::cout << "Enter HD speed (in RPM): ";
    std::cin >> speed;
    std::cout << "Enter HD size (in GB): ";
    std::cin >> size;
    std::cout << "Enter HD slot: ";
    std::cin >> slot;
    std::cout << "Is this HD for a laptop? (1 for yes, 0 for no): ";
    std::cin >> laptopInput;

    // Validate input and set isLaptop accordingly
    isLaptop = (laptopInput == 1);

    // Create a new HD object and add it to the list of components
    HD* hd = new HD(manufacturer, name, price, stock, type, isLaptop, speed, size, slot);
    components.push_back(hd);
}

void addMB(std::vector<Component*>& components) {
    std::string manufacturer, name, size;
    int price, stock, type, socket, memoryslots, laptopInput;
    bool isLaptop;
    type = 4; //type 4 = mb

    // Prompt the user for motherboard-specific details
    std::cout << "Enter motherboard manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Enter motherboard name: ";
    std::cin >> name;
    std::cout << "Enter motherboard price: ";
    std::cin >> price;
    std::cout << "Enter motherboard stock: ";
    std::cin >> stock;
    std::cout << "Enter motherboard socket type: ";
    std::cin >> socket;
    std::cout << "Enter motherboard memory slots: ";
    std::cin >> memoryslots;
    std::cout << "Enter motherboard size: ";
    std::cin >> size;
    std::cout << "Is this motherboard for a laptop? (1 for yes, 0 for no): ";
    std::cin >> laptopInput;

    // Validate input and set isLaptop accordingly
    isLaptop = (laptopInput == 1);

    // Create a new MB (motherboard) object and add it to the list of components
    MB* mb = new MB(manufacturer, name, price, stock, type, isLaptop, socket, memoryslots, size);
    components.push_back(mb);
}

void addMemory(std::vector<Component*>& components) {
    std::string manufacturer, name;
    int price, stock, type, size, speed, laptopInput;
    bool isLaptop;
    type = 5; //type 5 = memory

    // Prompt the user for Memory-specific details
    std::cout << "Enter Memory manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Enter Memory name: ";
    std::cin >> name;
    std::cout << "Enter Memory price: ";
    std::cin >> price;
    std::cout << "Enter Memory stock: ";
    std::cin >> stock;
    std::cout << "Enter Memory size (in GB): ";
    std::cin >> size;
    std::cout << "Enter Memory speed (in MHz): ";
    std::cin >> speed;
    std::cout << "Is this Memory for a laptop? (1 for yes, 0 for no): ";
    std::cin >> laptopInput;

    // Validate input and set isLaptop accordingly
    isLaptop = (laptopInput == 1);

    // Create a new Memory object and add it to the list of components
    Memory* memory = new Memory(manufacturer, name, price, stock, type, isLaptop, size, speed);
    components.push_back(memory);
}

void addPS(std::vector<Component*>& components) {
    std::string manufacturer, name;
    int price, stock, type, power, certification, laptopInput;
    bool isLaptop;
    type = 6; //type 6 = ps

    // Prompt the user for Power Supply-specific details
    std::cout << "Enter Power Supply manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Enter Power Supply name: ";
    std::cin >> name;
    std::cout << "Enter Power Supply price: ";
    std::cin >> price;
    std::cout << "Enter Power Supply stock: ";
    std::cin >> stock;
    std::cout << "Enter Power Supply power (in watts): ";
    std::cin >> power;
    std::cout << "Enter Power Supply certification: ";
    std::cin >> certification;
    std::cout << "Is this Power Supply for a laptop? (1 for yes, 0 for no): ";
    std::cin >> laptopInput;

    // Validate input and set isLaptop accordingly
    isLaptop = (laptopInput == 1);

    // Create a new PS (Power Supply) object and add it to the list of components
    PS* ps = new PS(manufacturer, name, price, stock, type, isLaptop, power, certification);
    components.push_back(ps);
}

void addCase(std::vector<Component*>& components) {
    std::string manufacturer, name, color, MBsize, Material;
    int price, stock, type, laptopInput;
    bool isLaptop;
    type = 0; //type 0 = case

    // Prompt the user for Case-specific details
    std::cout << "Enter Case manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Enter Case name: ";
    std::cin >> name;
    std::cout << "Enter Case price: ";
    std::cin >> price;
    std::cout << "Enter Case stock: ";
    std::cin >> stock;
    std::cout << "Enter Case color: ";
    std::cin >> color;
    std::cout << "Enter Case motherboard size: ";
    std::cin >> MBsize;
    std::cout << "Enter Case material: ";
    std::cin >> Material;
    std::cout << "Is this Case for a laptop? (1 for yes, 0 for no): ";
    std::cin >> laptopInput;

    // Validate input and set isLaptop accordingly
    isLaptop = (laptopInput == 1);

    // Create a new Case object and add it to the list of components
    Case* pcCase = new Case(manufacturer, name, price, stock, type, isLaptop, color, MBsize, Material);
    components.push_back(pcCase);
}

void updateComponent(std::vector<Component*>& components, int index) {
    //!!!!!
    //correct first case deleted when entering manufacturer problem
    //!!!!!
    if (index < 0 || index >= components.size()) {
        std::cout << "Invalid index. No component updated." << std::endl;
        return;
    }

    Component* comp = components[index];

    // Dynamically determine the type of component
    CPU* cpu = dynamic_cast<CPU*>(comp);
    GPU* gpu = dynamic_cast<GPU*>(comp);
    HD* hd = dynamic_cast<HD*>(comp);
    MB* mb = dynamic_cast<MB*>(comp);
    Memory* memory = dynamic_cast<Memory*>(comp);
    PS* ps = dynamic_cast<PS*>(comp);
    Case* _case = dynamic_cast<Case*>(comp);



    // Update attributes based on the type
    if (cpu) {
        // Update CPU specific attributes
        int newSpeed, newCores;
        std::string newSocket;
        std::cout << "Updating CPU component:" << std::endl;
        std::cout << "Enter new speed (MHz): ";
        std::cin >> newSpeed;
        std::cout << "Enter new number of cores: ";
        std::cin >> newCores;
        std::cout << "Enter new socket type: ";
        std::cin.ignore(); // To ignore leftover newline from previous input
        std::getline(std::cin, newSocket);
        cpu->setSpeed(newSpeed);
        cpu->setCores(newCores);
        cpu->setSocket(newSocket);
    }
    else if (gpu) {
        // Update GPU specific attributes
        int newPower, newBusSpeed;
        std::cout << "Updating GPU component:" << std::endl;
        std::cout << "Enter new power (W): ";
        std::cin >> newPower;
        std::cout << "Enter new bus speed (MHz): ";
        std::cin >> newBusSpeed;
        gpu->setPower(newPower);
        gpu->setBusspeed(newBusSpeed);
    }
    else if (hd) {
        // Update HD specific attributes
		int newSpeed, newSize;
		std::string newSlot;
		std::cout << "Updating HD component:" << std::endl;
		std::cout << "Enter new speed (RPM): ";
		std::cin >> newSpeed;
		std::cout << "Enter new size (GB): ";
		std::cin >> newSize;
		std::cout << "Enter new slot: ";
		std::cin.ignore(); // To ignore leftover newline from previous input
		std::getline(std::cin, newSlot);
		hd->setSpeed(newSpeed);
		hd->setSize(newSize);
		hd->setSlot(newSlot);
    }
    else if (mb) {
		// Update MB specific attributes
        int newSocket, newMemoryslots;
        std::string newSize;
        std::cout << "Updating MB component:" << std::endl;
        std::cout << "Enter new socket type: ";
        std::cin >> newSocket;
        std::cout << "Enter new number of memory slots: ";
        std::cin >> newMemoryslots;
        std::cout << "Enter new size: ";
        std::cin.ignore(); // To ignore leftover newline from previous input
        std::getline(std::cin, newSize);
        mb->setSocket(newSocket);
        mb->setMemoryslots(newMemoryslots);
        mb->setSize(newSize);
    }
    else if (memory) {
        // Update Memory specific attributes
		int newSize, newSpeed;
		std::cout << "Updating Memory component:" << std::endl;
		std::cout << "Enter new size (GB): ";
		std::cin >> newSize;
		std::cout << "Enter new speed (MHz): ";
		std::cin >> newSpeed;
		memory->setSize(newSize);
		memory->setSpeed(newSpeed);
	}
	else if (ps) {
		// Update PS specific attributes
		int newPower, newCertification;
		std::cout << "Updating PS component:" << std::endl;
		std::cout << "Enter new power (W): ";
		std::cin >> newPower;
		std::cout << "Enter new certification: ";
		std::cin >> newCertification;
		ps->setPower(newPower);
		ps->setCertification(newCertification);
	}
    else if (_case) {
        // Update Case specific attributes
        std::string newColor, newMBsize, newMaterial;
        std::cout << "Updating Case component:" << std::endl;
        std::cout << "Enter new color: ";
        std::cin.ignore(); // To ignore leftover newline from previous input
        std::getline(std::cin, newColor);
        std::cout << "Enter new motherboard size: ";
        std::getline(std::cin, newMBsize);
        std::cout << "Enter new material: ";
        std::getline(std::cin, newMaterial);
        _case->setColor(newColor);
        _case->setMBsize(newMBsize);
        _case->setMaterial(newMaterial);
    }
    updateComponentBase(comp);
}

void updateComponentBase(Component* component) {
    // Update generic component attributes
    
    std::string newManufacturer, newName;
    int newPrice, newStock; //newType;
    bool isLaptop;
    std::cout << "Updating generic component:" << std::endl;
    std::cout << "Enter new manufacturer: ";
    //std::cin.ignore(); // To ignore leftover newline from previous input
    std::getline(std::cin, newManufacturer);
    std::cout << "Enter new name: ";
    std::getline(std::cin, newName);
    std::cout << "Enter new price: ";
    std::cin >> newPrice;
    std::cout << "Enter new stock: ";
    std::cin >> newStock;
    //std::cout << "Enter new type: ";
    //std::cin >> newType;
    std::cout << "Is this a laptop component? (1 for yes, 0 for no): ";
    std::cin >> isLaptop;

    component->setManufacturer(newManufacturer);
    component->setName(newName);
    component->setPrice(newPrice);
    component->setStock(newStock);
    //component->setType(newType);
    // component->setLaptop(isLaptop); // This setter method should exist in the Component class
    std::cout << "Component updated: " << component->getDetails() << std::endl;

}

void deleteComponent(std::vector<Component*>& components, int index) {
    if (index < 0 || index >= components.size()) {
		std::cout << "Invalid index. No component deleted." << std::endl;
		return;
	}

	Component* comp = components[index];
	components.erase(components.begin() + index);
	delete comp;
	std::cout << "Component deleted." << std::endl;
}   

void updateStock(Component* component, int newStock) {
    component->setStock(newStock);
    std::cout << "Stock updated to " << newStock << " for component: " << component->getName() << std::endl;
}

void updateStock(Component* component, int changeInStock, bool isIncrease) {
    int currentStock = component->getStock();
    int updatedStock = isIncrease ? currentStock + changeInStock : currentStock - changeInStock;

    // Ensure stock doesn't drop below zero
    if (updatedStock < 0) {
        std::cout << "Cannot decrease stock below 0. No changes made to component: " << component->getName() << std::endl;
        return;
    }

    component->setStock(updatedStock);
    std::cout << (isIncrease ? "Increased" : "Decreased") << " stock by " << changeInStock
        << ". New stock is " << updatedStock << " for component: " << component->getName() << std::endl;
}



void showComponents(const std::vector<Component*>& components) {
    int index = 0;
    if (components.empty()) {
        std::cout << "No components to display." << std::endl;
        return;
    }

    for (const auto& component : components) {
        if (component != nullptr) {
            std::cout << index++ << ". ";
            std::cout << component->getDetails() << std::endl;
        }
    }
}

//a function to show specific component according to the pc or laptop
void showIsLaptopComponents(const std::vector<Component*>& components, bool isLaptop) {
    int index = 0;
    if (components.empty()) {
		std::cout << "No components to display." << std::endl;
		return;
	}

    for (const auto& component : components) {

        if (component != nullptr && component->isLaptopComponent() == isLaptop) {
			std::cout << index++ << ". ";
			std::cout << component->getDetails() << std::endl;
        }
        
	
	}


}

//a function to show specific component according to the pc or laptop and type
void showSpecificComponents(const std::vector<Component*>& components, ComponentType type, bool isLaptop) {
        //cast the type to int
        int typeInt = static_cast<int>(type);
    	int index = 0;
        if (components.empty()) {
		std::cout << "No components to display." << std::endl;
		return;
	    }

        for (const auto& component : components) {

            if (component != nullptr && component->getType() == typeInt && component->isLaptopComponent() == isLaptop) {
			std::cout << index++ << ". ";
			std::cout << component->getDetails() << std::endl;
		    }
		
	
	    }
}

//overload the function to show specific component according to the type
void showSpecificComponents(const std::vector<Component*>& components, ComponentType type) {
        //cast the type to int
        int typeInt = static_cast<int>(type);
    	int index = 0;
        if (components.empty()) {
		std::cout << "No components to display." << std::endl;
		return;
	    }

        for (const auto& component : components) {

            if (component != nullptr && component->getType() == typeInt) {
			std::cout << index++ << ". ";
			std::cout << component->getDetails() << std::endl;
		    }
		
	
	    }
}

void writeComponents(const std::vector<Component*>& components, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const auto& component : components) {
        // Determine the type of the component and cast to the correct type
        if (auto* cpu = dynamic_cast<CPU*>(component)) {
            file << cpu->getManufacturer() << " " << cpu->getName() << " "
                << cpu->getPrice() << " " << cpu->getStock() << " " << cpu->getType() << " "
                << (cpu->isLaptopComponent() ? "true" : "false") << " " << cpu->getSpeed() << " "
                << cpu->getCores() << " " << cpu->getSocket() << std::endl;
        }
        else if (auto* gpu = dynamic_cast<GPU*>(component)) {
            file << gpu->getManufacturer() << " " << gpu->getName() << " "
                << gpu->getPrice() << " " << gpu->getStock() << " " << gpu->getType() << " "
                << (gpu->isLaptopComponent() ? "true" : "false") << " " << gpu->getPower() << " "
                << gpu->getBusspeed() << std::endl;
        }
        else if (auto* hd = dynamic_cast<HD*>(component)) {
            file << hd->getManufacturer() << " " << hd->getName() << " "
				<< hd->getPrice() << " " << hd->getStock() << " " << hd->getType() << " "
				<< (hd->isLaptopComponent() ? "true" : "false") << " " << hd->getSpeed() << " "
				<< hd->getSize() << " " << hd->getSlot() << std::endl;
        }
        else if (auto* mb = dynamic_cast<MB*>(component)) {
			file << mb->getManufacturer() << " " << mb->getName() << " "
                << mb->getPrice() << " " << mb->getStock() << " " << mb->getType() << " "
                << (mb->isLaptopComponent() ? "true" : "false") << " " << mb->getSocket() << " "
                << mb->getMemoryslots() << " " << mb->getSize() << std::endl;

        }
        else if (auto* memory = dynamic_cast<Memory*>(component)) {
            file << memory->getManufacturer() << " " << memory->getName() << " "
				<< memory->getPrice() << " " << memory->getStock() << " " << memory->getType() << " "
				<< (memory->isLaptopComponent() ? "true" : "false") << " " << memory->getSize() << " "
				<< memory->getSpeed() << std::endl;
		}
        else if (auto* ps = dynamic_cast<PS*>(component)) {
        	file << ps->getManufacturer() << " " << ps->getName() << " "
                << ps->getPrice() << " " << ps->getStock() << " " << ps->getType() << " "
                << (ps->isLaptopComponent() ? "true" : "false") << " " << ps->getPower() << " "
                << ps->getCertification() << std::endl;

        }
        else if (auto* _case = dynamic_cast<Case*>(component)) {
			file << _case->getManufacturer() << " " << _case->getName() << " "
				<< _case->getPrice() << " " << _case->getStock() << " " << _case->getType() << " "
				<< (_case->isLaptopComponent() ? "true" : "false") << " " << _case->getColor() << " "
				<< _case->getMBsize() << " " << _case->getMaterial() << std::endl;
		}
        
    }

    file.close();
}