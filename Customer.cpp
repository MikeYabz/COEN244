#include "Customer.h"

    //Constructors
Customer::Customer()
{
    customerNumber = 0;
    name = "NULL";
    address = "NULL";
    telephoneNumber = "NULL";
    companyName = "NULL";
    companyAddress = "NULL";
    customerType = Regular;
}
Customer::~Customer()
{
    std::cout<<"Customer Entry Deleted\n";
}

    //Get and Set Functions
int Customer::getCustomerNumber()
{
    return customerNumber;
}
std::string Customer::getName()
{
    return name;
}
std::string Customer::getAddress()
{
    return address;
}
std::string Customer::getTelephoneNumber()
{
    return telephoneNumber;
}
std::string Customer::getCompanyName()
{
    return companyName;
}
std::string Customer::getCompanyAddress()
{
    return companyAddress;
}
std::string Customer::getCustomerType()
{
    if (customerType == 0) return "Regular";
    else if (customerType == 1) return "Corporate";
    else if (customerType == 2) return "VIP";
}
void Customer::setCustomerNumber(int inputCustomerNumber)
{
    customerNumber = inputCustomerNumber;
}
void Customer::setName(std::string inputName)
{
    name = inputName;
}
void Customer::setAddress(std::string inputAddress)
{
    address = inputAddress;
}
void Customer::setTelephoneNumber(std::string inputTelephoneNumber)
{
    telephoneNumber = inputTelephoneNumber;
}
void Customer::setCompanyName(std::string inputCompanyName)
{
    companyName = inputCompanyName;
}
void Customer::setCompanyAddress(std::string inputCompanyAddress)
{
    companyAddress = inputCompanyAddress;
}
void Customer::setCustomerType(Customer_Types inputCustomerType)
{
    customerType = inputCustomerType;
}