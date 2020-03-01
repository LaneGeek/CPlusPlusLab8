#ifndef LAB8_CAR_HPP
#define LAB8_CAR_HPP

#include <string>

class Car {
    // fields
    std::string make;
    std::string color;
    int year;

public:
    // constructors
    Car();
    Car(std::string make, std::string color, int year);

    // getters
    std::string getMake();
    std::string getColor();
    int getYear();

    // setters
    void setMake(std::string make);
    void setColor(std::string color);
    void setYear(int year);

    // overloaded operators
    bool operator==(const Car &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif
