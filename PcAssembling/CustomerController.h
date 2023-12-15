#ifndef CUSTOMERCONTROLLER_H
#define CUSTOMERCONTROLLER_H
#include "Customer.h"
#include "Company.h"
#include <vector>
#include <memory>
constexpr auto CUSTOMERS_FILE = "files/customers.txt";
constexpr auto CUSTOMERS_W_FILE = "files/customerswrite.txt";

void addCustomer(std::vector<Customer*>& customers);
void deleteCustomer(std::vector<Customer*>& customers);
void updateCustomer(std::vector<Customer*>& customers);

void showCustomers(const std::vector<Customer*>& customers);
void readCustomers(std::vector<Customer*>& customers, const std::string& filename);
bool findCustomerType(const std::string& type);
void writeCustomers(const std::vector<Customer*>& customers, const std::string& filename);

#endif // !CUSTOMERCONTROLLER_H
