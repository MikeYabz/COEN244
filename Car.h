#include <string>

#pragma once

enum class CarType
{
    Standard,
    Luxury
};

class Car
{
    int id;
    CarType type;
    bool rented;

public:
    Car();
    ~Car();

    int getId() const;
    CarType getType() const;
    bool isRented() const;

    void setId(int id);
    void setType(CarType type);
    void setRented(bool rented);
};
