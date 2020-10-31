#ifndef VISIT_H
#define VISIT_H

#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
//Visit class
class Visit
{
public:
    int CheckInTime; //time patient was admitted
    int CheckOutTime; //time patient was released
    int TotalTime; //total accrued time spent at hospital
    int severityNum; //severity of illness
    std::string patientname; //name

    //Base empty constructor
    Visit();
    //constructor with parameters
    Visit(std::string name, int checkout, int checkin, int severity);

    int getCheckIn(); //return checkin time
    std::string getName(); //return patient name
    int getCheckOut(); //return checkout time
    int totaltime(); //return total time
    int getSeverity();     //return Patient severity number
    void toString();       //display Patient info
    void convertTime(int minutes); //convert raw data to readable format
};

#endif