#include "customer.h"

#include <string>

#pragma once

class CorporateCustomer : public Customer
{
    std::string companyName;
    std::string companyAddress;

public:
    CorporateCustomer();
    CorporateCustomer(Customer*& other);
    ~CorporateCustomer();

    std::string getCompanyName() const;
    std::string getCompanyAddress() const;

    void setCompanyName(std::string companyName);
    void setCompanyAddress(std::string companyAddress);
};
