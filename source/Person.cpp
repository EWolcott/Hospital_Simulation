#include "Person.h"

//Base empty constructor
Person::Person(){
    _name = "Jane Doe";
}
//constructor with parameters
Person::Person(std::string name)
{
    _name = name;
}

std::string Person::getName() //return name
{                             //return person name
    return _name;
}

