#include "car.h"
#include "customer.h"
#include "car_rental.h"
#include "corporate.h"
#include "management.h"

#include <iostream>
#include <limits>

// Compiled with: g++ --std=c++11 main.cpp management.cpp car_rental.cpp corporate.cpp customer.cpp car.cpp
// Or with cmake: mkdir build && cd build && cmake .. && make

// NOTE std::cin.ignore is used after using the '>>' operator with std::cin to ignore potential remaining '\n' characters

CarRentalManagement* coen244cars;

// For convenience
std::string getStringFromUser()
{
    std::string s;
    std::getline(std::cin, s);
    return s;
}

void addCar()
{
    int id, t;
    CarType type;
    Car* car = new Car();
    std::cout << "Enter id: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    car->setId(id);
    std::cout << "Enter a type (0 for standard, 1 for luxury): ";
    std::cin >> t;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    type = (CarType)t;
    if (type == CarType::Standard || type == CarType::Luxury) {
        car->setType(type);
        coen244cars->addCar(car);
    }
}

void removeCar()
{
    int id;
    std::cout << "Enter the car's id: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    coen244cars->removeCar(id);
}

void registerCustomer()
{
    int number;
    std::cout << "Enter number: ";
    std::cin >> number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    std::cout << "Enter name: ";
    std::string name = getStringFromUser();
    std::cout << "Enter address: ";
    std::string address = getStringFromUser();
    std::cout << "Enter tel: ";
    std::string tel = getStringFromUser();
    int t;
    std::cout << "Enter type (0 for regular, 1 for corporate, 2 for vip): ";
    std::cin >> t;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    CustomerType type;
    type = (CustomerType)t;
    Customer* cust;
    if (type != CustomerType::Corporate) {
        cust = new Customer();
    } else {
        cust = new CorporateCustomer();
        std::cout << "Enter company name: ";
        std::string companyName = getStringFromUser();
        ((CorporateCustomer*)cust)->setCompanyName(companyName);
        std::cout << "Enter company address: ";
        std::string companyAddress = getStringFromUser();
        ((CorporateCustomer*)cust)->setCompanyAddress(companyAddress);
    }
    cust->setNumber(number);
    cust->setName(name);
    cust->setAddress(address);
    cust->setTel(tel);
    cust->setType(type);
    coen244cars->registerCustomer(cust);
}

void removeCustomer()
{
    int number;
    std::cout << "Enter the customer's number: ";
    std::cin >> number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    coen244cars->removeCustomer(number);
}

void rent()
{
    int id;
    std::cout << "Enter the car's id: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    int number;
    std::cout << "Enter the customer's number: ";
    std::cin >> number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    coen244cars->rent(id, number);
}

void getCar()
{
    int id;
    std::cout << "Enter the car's id: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    Car* car = coen244cars->getCar(id);
    std::cout << "Car with id " << id << " is a "
        << (car->getType() == CarType::Luxury ? "luxury" : "standard")
        << " car\n";
}

void updateCar()
{
    int id;
    std::cout << "Enter the car's id: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    int t;
    CarType type;
    Car* car = new Car();
    car->setId(id);
    std::cout << "Enter a type (0 for standard, 1 for luxury): ";
    std::cin >> t;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    type = (CarType)t;
    if (type == CarType::Standard || type == CarType::Luxury)
        car->setType(type);
    coen244cars->updateCar(id, car);
}

void getPrivileges()
{
    int number;
    std::cout << "Enter the customer's number: ";
    std::cin >> number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    int priv = coen244cars->getPrivileges(number);
    std::cout << "Privileges: " << priv << "\n";
}

void setPrivileges()
{
    int t;
    CustomerType type;
    std::cout << "Enter the customer type (0 for regular, 1 for coporate, 2 for vip): ";
    std::cin >> t;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    type = (CustomerType)t;
    int duration;
    std::cout << "Enter the new duration of a rental: ";
    std::cin >> duration;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    if (type >= CustomerType::Regular && type <= CustomerType::VIP)
        coen244cars->setPrivileges(type, duration);
}

void isRented()
{
    int id;
    std::cout << "Enter the car's id: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    if (coen244cars->isRented(id))
        std::cout << "This car is rented\n";
    else
        std::cout << "This car is not rented\n";
}

void hasRentedCar()
{
    int number;
    std::cout << "Enter the customer's number: ";
    std::cin >> number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    if (coen244cars->hasRentedCar(number))
        std::cout << "This customer has rented a car\n";
    else
        std::cout << "This customer has not rented a car\n";
}

void isRentedByType()
{
    int id;
    std::cout << "Enter the car's id: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
    switch(coen244cars->isRentedByType(id)) {
        case CustomerType::Regular:
            std::cout << "This car is rented by a regular customer\n";
            break;
        case CustomerType::Corporate:
            std::cout << "This car is rented by a corporate customer\n";
            break;
        case CustomerType::VIP:
            std::cout << "This car is rented by a VIP customer\n";
            break;
        default:
            std::cout << "This car is not rented/does not exist\n";
            break;
    }
}

void getCarsRentedBy()
{
    std::cout << "Enter company name: ";
    std::string name = getStringFromUser();
    std::vector<CarType> cars = coen244cars->getCarsRentedBy(name);
    std::cout << "This company has rented these types of cars: ";
    for (auto t : cars)
        std::cout << (t == CarType::Luxury ? "luxury " : "standard ");
    std::cout << "\n";
}

int main()
{
    coen244cars = new CarRentalManagement();
    bool running = true;
    int option;

    while (running) {
        std::cout << "What would you like to do:\n"
            << "1. Add a car\n"
            << "2. Remove a car\n"
            << "3. Register a customer\n"
            << "4. Remove a customer\n"
            << "5. Rent a car\n"
            << "6. Get a car\n"
            << "7. Update a car\n"
            << "8. Get privileges of a customer\n"
            << "9. Set privileges for a type of customer\n"
            << "10. Check if a car is rented\n"
            << "11. Check if a customer has rented a car\n"
            << "12. Check by what type of customer a car is rented\n"
            << "13. Get types of cars rented by a company\n"
            << "14. Exit\n";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fix io
        switch (option) {
            case 1:
                addCar();
                break;
            case 2:
                removeCar();
                break;
            case 3:
                registerCustomer();
                break;
            case 4:
                removeCustomer();
                break;
            case 5:
                rent();
                break;
            case 6:
                getCar();
                break;
            case 7:
                updateCar();
                break;
            case 8:
                getPrivileges();
                break;
            case 9:
                setPrivileges();
                break;
            case 10:
                isRented();
                break;
            case 11:
                hasRentedCar();
                break;
            case 12:
                isRentedByType();
                break;
            case 13:
                getCarsRentedBy();
                break;
            case 14:
                running = false;
                break;
            default:
                std::cout << "Invalid option\n";
                break;
        }
    }

    delete coen244cars;
    return 0;
}
