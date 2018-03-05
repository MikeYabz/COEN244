#include "Car.h"

#include <iostream>

//Constructors
Car::Car ()
{
    id = 0;
    type = "Standard";
}
Car::Car (int inputId, std::string inputType)
{
    id = inputId;
    type = inputType;
}
Car::~Car()
{
    std::cout<<"Car Entry Deleted\n";
}

//Get and Set Functions
int Car::getId()
{
    return id;
}
std::string Car::getType()
{
    return type;
}
void Car::setId(int inputId)
{
    inputId = id;
}
void Car::setType(std::string inputType)
{
    if (inputType == "Standard" || inputType == "Luxury")
    {
        type = inputType;
    }
    else
    {
        std::cout<<"Invalid car type\n";
    }
}
