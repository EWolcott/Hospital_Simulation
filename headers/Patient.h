#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
#include "Visit.h"
#include "Person.h"
//Patient class
class Patient : public Person
{
public:
    int severityNum; //severity of illness
    int timeOfAdmission; //time patient was admitted to hospital

    //Base empty constructor
    Patient();
    //constructor with parameters
    Patient(std::string name, int toa);

    std::string getName(); //return Patient name
    int getSeverity();     //return Patient severity number
    void toString();       //display patient info
    int generateSev();//generate a severity number
     friend bool operator<(const Patient &, const Patient &); //operator for comparing within priority queue
    friend bool operator>(const Patient &, const Patient &);//operator for comparing within priority queue
    friend bool operator==(const Patient &, const Patient &);//operator for comparing within priority queue
};

#endif