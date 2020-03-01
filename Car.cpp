#include "Car.hpp"

// constructors
Car::Car() {
    make = "Ford";
    color = "Black";
    year = 1910;
}

Car::Car(std::string make, std::string color, int year) {
    this->make = make;
    this->color = color;
    this->year = year;
}

// getters
std::string Car::getMake() {
    return make;
}

std::string Car::getColor() {
    return color;
}

int Car::getYear() {
    return year;
}

// setters
void Car::setMake(std::string make) {
    this->make = make;
}

void Car::setColor(std::string color) {
    this->color = color;
}

void Car::setYear(int year) {
    this->year = year;
}

// overloaded operators
bool Car::operator==(const Car &rhs) {
    return this->make == rhs.make && this->color == rhs.color && this->year == rhs.year;
}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    std::string SPACE = " ";
    os << rhs.year;
    os << SPACE;
    os << rhs.color;
    os << SPACE;
    os << rhs.make;
    return os;
}
