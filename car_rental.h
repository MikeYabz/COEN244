#include "car.h"
#include "customer.h"

#pragma once

class CarRental
{
public:
    CarRental(Car* car, Customer* customer);
    ~CarRental();

    Car* car;
    Customer* customer;
};
