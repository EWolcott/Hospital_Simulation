#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
#include "Visit.h"
#include "CareProvider.h"
//Doctor class
class Doctor : public CareProvider //sublcass
{
public:

    //Base empty constructor
    Doctor();
  std::string getType(); //returns type
};

#endif
