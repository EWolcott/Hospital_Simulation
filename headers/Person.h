#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
//Person class
class Person 
{
public:
    std::string _name; //track name

    //Base empty constructor
    Person();
    //constructor with parameters
    Person(std::string name);

    std::string getName(); //return person name
};

#endif