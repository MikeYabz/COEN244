#include "corporate.h"

CorporateCustomer::CorporateCustomer()
    : Customer()
{
    companyName = "";
    companyAddress = "";
}

CorporateCustomer::CorporateCustomer(Customer*& other)
    : Customer()
{
    setNumber(other->getNumber());
    setName(other->getName());
    setAddress(other->getAddress());
    setTel(other->getTel());
    setType(CustomerType::Corporate);
    companyName = "";
    companyAddress = "";
}

CorporateCustomer::~CorporateCustomer()
{}

std::string CorporateCustomer::getCompanyName() const
{
    return companyName;
}

std::string CorporateCustomer::getCompanyAddress() const
{
    return companyAddress;
}

void CorporateCustomer::setCompanyName(std::string companyName)
{
    this->companyName = companyName;
}

void CorporateCustomer::setCompanyAddress(std::string companyAddress)
{
    this->companyAddress = companyAddress;
}
