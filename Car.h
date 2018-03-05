#include <iostream>

enum Car_Types
{
    Standard = 0,
    Luxury = 1
};

class Car
{
private:
    int id;
    Car_Types type;
    bool carRented;
public:
        //Constructors
    Car ();
    ~Car();
        //Get and Set Functions
    int getId();
    Car_Types getType();
    bool getCarRented();
    void setId(int inputId);
    void setType(Car_Types inputType);
    void setCarRented(bool inputCarRented);
};
