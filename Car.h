#include <string>

class Car
{
private:
    int id;
    std::string type;
public:
    //Constructors
    Car ();
    Car (int inputId, std::string inputType);
    ~Car();
    //Get and Set Functions
    int getId();
    std::string getType();
    void setId(int inputId);
    void setType(std::string inputType);
};
