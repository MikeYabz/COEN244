#include "customer.h"

Customer::Customer()
{
    number = 0;
    name = "";
    address = "";
    tel = "";
    type = CustomerType::Regular;
}

Customer::~Customer()
{}

int Customer::getNumber() const
{
    return number;
}

std::string Customer::getName() const
{
    return name;
}

std::string Customer::getAddress() const
{
    return address;
}

std::string Customer::getTel() const
{
    return tel;
}

CustomerType Customer::getType() const
{
    return type;
}

void Customer::setNumber(int number)
{
    this->number = number;
}

void Customer::setName(std::string name)
{
    this->name = name;
}

void Customer::setAddress(std::string address)
{
    this->address = address;
}

void Customer::setTel(std::string tel)
{
    this->tel = tel;
}

void Customer::setType(CustomerType type)
{
    this->type = type;
}
