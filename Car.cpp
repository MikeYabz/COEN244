#include "car.h"

Car::Car()
{
    id = 0;
    type = CarType::Standard;
    rented = false;
}

Car::~Car()
{}

int Car::getId() const
{
    return id;
}

CarType Car::getType() const
{
    return type;
}

bool Car::isRented() const
{
    return rented;
}

void Car::setId(int id)
{
    this->id = id;
}

void Car::setType(CarType type)
{
    this->type = type;
}

void Car::setRented(bool rented)
{
    this->rented = rented;
}
