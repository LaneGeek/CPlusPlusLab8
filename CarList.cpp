#include "CarList.hpp"
#include <sstream>

// constructor, defines head
CarList::CarList()
{
    head = nullptr;
}

// destructor, deletes items, using recursion
CarList::~CarList()
{
    recDestruct(head);
}

// recursive method to walk down list, deleting items starting at tail
void CarList::recDestruct(Link * ptr)
{
    if (ptr)
    {
        recDestruct(ptr->next);
        // delete the car
        delete ptr->car;
        delete ptr;
    }
}

// recursive method to search the list
// uses overloaded equality operator in Car
bool CarList::recFind(Link * ptr, Car *car)
{
    if (ptr == nullptr) {
        // delete car which was created to test for equality
        delete car;
        return false;
    }
    if (*ptr->car == *car) {
        // delete car which was created to test for equality
        delete car;
        return true;
    }
    return recFind(ptr->next, car);
}

// creates a new car on heap
// creates new link
// adds link to head of list
void CarList::addCar(std::string make, std::string color, int year)
{
    Car *car = new Car(make, color, year);
    Link *tempLink = new Link;
    tempLink->car = car;
    tempLink->next = head;
    head = tempLink;
}

// look for a car on the list
// create an instance of it, use recursive method to see if there
bool CarList::findCar(std::string make, std::string color, int year)
{
    // this car will be deleted in recFind
    Car *car = new Car(make, color, year);
    return recFind(head, car);
}

// remove the item at head and return its value
Car* CarList::removeHead()
{
    // deal with empty list
    if (head == nullptr)
        return nullptr;

    // create a pointer to the car object in head
    Car *car = head->car;

    // update head
    head = head->next;

    // return the car pointer
    return car;
}

// build a string  by walking down the list
// uses overloaded extraction operator in Car
std::string CarList::displayList()
{
    std::stringstream buffer;

    // start at the head
    Link *ptr = head;

    // until done with list
    while (ptr)
    {
        buffer << *ptr->car << ", ";
        ptr = ptr->next;
    }

    // now return the string
    return buffer.str();
}
