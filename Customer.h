#include <string>

#pragma once

enum CustomerType
{
    Regular,
    Corporate,
    VIP
};

class Customer
{
    int number;
    std::string name;
    std::string address;
    std::string tel;
    CustomerType type;

public:
    Customer();
    ~Customer();

    int getNumber() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getTel() const;
    CustomerType getType() const;

    void setNumber(int number);
    void setName(std::string name);
    void setAddress(std::string address);
    void setTel(std::string tel);
    void setType(CustomerType type);
};
