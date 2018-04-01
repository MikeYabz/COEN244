#include "management.h"

#include <algorithm>

CarRentalManagement::CarRentalManagement()
{
    privileges.insert({CustomerType::Regular, 20});
    privileges.insert({CustomerType::Corporate, 35});
    privileges.insert({CustomerType::VIP, 45});
}

CarRentalManagement::~CarRentalManagement()
{
    for (auto* c : cars)
        delete c;
    for (auto* c : customers)
        delete c;
}

void CarRentalManagement::addCar(Car* car)
{
    cars.push_back(car);
}

void CarRentalManagement::removeCar(int id)
{
    Car* toRemove = nullptr;
    for (auto* c : cars) {
        if (c->getId() == id) {
            toRemove = c;
            break;
        }
    }
    if (toRemove)
        cars.erase(std::remove(cars.begin(), cars.end(), toRemove), cars.end());
    delete toRemove;
}

void CarRentalManagement::registerCustomer(Customer* customer)
{
    customers.push_back(customer);
}

void CarRentalManagement::removeCustomer(int number)
{
    Customer* toRemove = nullptr;
    for (auto* c : customers) {
        if (c->getNumber() == number) {
            toRemove = c;
            break;
        }
    }
    if (toRemove) {
        customers.erase(std::remove(customers.begin(), customers.end(), toRemove), customers.end());
    }
    delete toRemove;
}

void CarRentalManagement::rent(int carId, int custNumber)
{
    Car* car = nullptr;
    for (auto* c : cars)
        if (c->getId() == carId)
            car = c;
    Customer* cust = nullptr;
    for (auto* c: customers)
        if (c->getNumber() == custNumber)
            cust = c;
    if (car && cust) {
        CarRental cr = CarRental(car, cust);
        rentals.emplace_back(cr);
    }
}

Car* CarRentalManagement::getCar(int id)
{
    for (auto* c : cars)
        if (c->getId() == id)
            return c;
}

void CarRentalManagement::updateCar(int id, Car* car)
{
    Car* toUpdate = nullptr;
    for (auto* c : cars)
        if (c->getId() == id)
            toUpdate = c;
    if (toUpdate) {
        std::replace(cars.begin(), cars.end(), toUpdate, car);
        delete toUpdate;
    }
}

int CarRentalManagement::getPrivileges(int number)
{
    Customer* cust = nullptr;
    for (auto* c : customers)
        if (c->getNumber() == number)
            cust = c;
    if (cust)
        return privileges[cust->getType()];
    else
        return -1;
}

void CarRentalManagement::setPrivileges(CustomerType type, int rentalDuration)
{
    privileges[type] = rentalDuration;
}

bool CarRentalManagement::isRented(int id)
{
    Car* car;
    for (auto* c: cars)
        if (c->getId() == id)
            car = c;
    for (auto& cr : rentals)
        if (cr.car == car)
            return true;
    return false;
}

bool CarRentalManagement::hasRentedCar(int number)
{
    Customer* cust = nullptr;
    for (auto* c : customers)
        if (c->getNumber() == number)
            cust = c;
    if (cust)
        for (auto& cr : rentals)
            if (cr.customer == cust)
                return true;
    return false;
}

CustomerType CarRentalManagement::isRentedByType(int id)
{
    Car* car;
    for (auto* c: cars)
        if (c->getId() == id)
            car = c;
    for (auto& cr : rentals)
        if (cr.car == car)
            return cr.customer->getType();
    return (CustomerType)-1;
}

std::vector<CarType> CarRentalManagement::getCarsRentedBy(std::string companyName)
{
    std::vector<CarType> types;
    for (auto* cust : customers)
        if (cust->getType() == CustomerType::Corporate)
            for (auto& cr : rentals)
                if (cr.customer->getNumber() == cust->getNumber())
                    types.emplace_back(cr.car->getType());
    return types;
}
