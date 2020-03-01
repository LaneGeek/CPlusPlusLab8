#ifndef CARLIST_HPP
#define CARLIST_HPP

#include "Car.hpp"
#include <string>

struct Link {
    Link *next;
    Car car;
};

class CarList {
    Link *head;

    // recursive methods
    void recDestruct(Link *ptr);
    bool recFind(Link *ptr, Car car);

public:
    // constructor and destructor
    CarList();
    ~CarList();

    // methods
    void addCar(std::string make, std::string color, int year);
    bool findCar(std::string make, std::string color, int year);
    Car removeHead();
    std::string displayList();
};

#endif
