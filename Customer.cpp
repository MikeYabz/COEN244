#include "Customer.h"

    //Constructors
Customer::Customer()
{
    customerNumber = 0;
    name = "";
    address = "";
    telephoneNumber = "";
    companyName = "";
    companyAddress = "";
    setCustomerType(Regular);
    customerRental = false;
    vipMax = 45;
    corporateMax = 35;
    regularMax = 25;
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
bool Customer::getCustomerRental()
{
    return customerRental;
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
    if (customerType == 0) maxRentalPeriod = regularMax;
    else if (customerType == 1) maxRentalPeriod = corporateMax;
    else if (customerType == 2) maxRentalPeriod = vipMax;
}
void Customer::setCustomerRental(bool inputCustomerRental)
{
    customerRental = inputCustomerRental;
}
void Customer::setRental(Car *car)
{
    if ((customerType == 0) && (car->getType() == 1)) //
    {
        std::cout<<"Error: Regular Customers Can't Rent Luxury Cars\n";
    }
    else
    {
        rentedCar = car;
        customerRental = true;
        car->setCarRented(true);
    }
}