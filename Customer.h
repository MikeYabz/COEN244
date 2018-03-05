#include "Car.h"

enum CustomerType
{
    Regular = 0,
    Corporate = 1,
    VIP = 2
};

class Customer : public Car
{
private:
    int customerNumber;
    std::string name;
    std::string address;
    std::string telephoneNumber;
    std::string companyName;
    std::string companyAddress;
    Car *rentedCar;
    int maxRentalPeriod;
    CustomerType customerType;
public:
    //Constructors
    Customer();
    ~Customer();
    //Get and Set Functions
    int getCustomerNumber();
    std::string getName();
    std::string getAddress();
    std::string getTelephoneNumber();
    std::string getCompanyName();
    std::string getCompanyAddress();
    std::string getCustomerType();
    void setCustomerNumber(int inputCustomerNumber);
    void setName(std::string inputName);
    void setAddress(std::string inputAddress);
    void setTelephoneNumber(std::string inputTelephoneNumber);
    void setCompanyName(std::string inputCompanyName);
    void setCompanyAddress(std::string inputCompanyAddress);
    void setCustomerType(CustomerType inputCustomerType);
    //Other Functions
    //void
};
