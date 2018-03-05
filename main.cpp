#include <iostream>
#include "CarRentalManagement.h"

int main() {

    CarRentalManagement CarCompany;
    Customer cust;
    bool running = true;
    int option;

    while (running)
    {
        std::cout<< "What would you like to do?\n"
                "1) Add a new car to the inventory\n"
                "2) Remove a car from the inventory\n"
                "3) Register new customers\n"
                "4) Remove a customer from the customer's list\n"
                "5) Rent a car to a customer\n"
                "6) Check a car's information\n"
                "7) Check privileges of a particular customer.\n"
                "8) Change a Privilege.\n"
                "9) Check whether a car is rented or not\n"
                "10) Check whether a customer has rented a car\n"
                "11) Check whether a given car is a regular customer, corporate, or VIP.\n" //This doesnt make sense, sent the teacher a message asking for clarification
                "12) Check which cars are rented by a customer of a given company.\n"
                "13) End Program\n"
                "Enter an Option: ";
        std::cin >> option;
        switch(option)
        {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                std::cout<<"Exiting\n";
                running = false;
                break;
            default:
                std::cout<<"\nInvalid Option\n\n";
                break;
        }
    }
    return 0;
}