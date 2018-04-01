#include "car.h"
#include "car_rental.h"
#include "customer.h"

#include <map>
#include <string>
#include <vector>

#pragma once

class CarRentalManagement
{
    std::vector<Car*> cars;
    std::vector<Customer*> customers;
    std::vector<CarRental> rentals;
    std::map<CustomerType, int> privileges;

public:
    CarRentalManagement();
    ~CarRentalManagement();

    void addCar(Car* car);
    void removeCar(int id);
    void registerCustomer(Customer* customer);
    void removeCustomer(int number);
    void rent(int carId, int custNumber);
    Car* getCar(int id);
    void updateCar(int id, Car* car);
    int getPrivileges(int number);
    void setPrivileges(CustomerType type, int rentalDuration);
    bool isRented(int id);
    bool hasRentedCar(int number);
    CustomerType isRentedByType(int id);
    std::vector<CarType> getCarsRentedBy(std::string companyName);
};
