#include "car_rental.h"

CarRental::CarRental(Car* car, Customer* customer)
{
    this->car = car;
    this->customer = customer;
}

CarRental::~CarRental()
{}
