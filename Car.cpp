#include "Car.h"

    //Constructors
Car::Car ()
{
    id = 0;
    type = Standard;
    carRented = false;
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
Car_Types Car::getType()
{
    return type;
}
bool Car::getCarRented()
{
    return carRented;
}
void Car::setId(int inputId)
{
    id = inputId;
}
void Car::setType(Car_Types inputType)
{
   type = inputType;
}
void Car::setCarRented(bool inputCarRented)
{
    carRented = inputCarRented;
}