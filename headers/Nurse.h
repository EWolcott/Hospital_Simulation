#ifndef NURSE_H
#define NURSE_H

#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
#include "Visit.h"
#include "CareProvider.h"
//Nurse class
class Nurse : public CareProvider
{
public:

    //Base empty constructor
    Nurse();
    std::string getType(); //returns type
  
};

#endif