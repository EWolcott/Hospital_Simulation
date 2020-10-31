#ifndef CAREPROVIDER_H
#define CAREPROVIDER_H

#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
#include "Visit.h"
#include "Patient.h"
//CareProvider class abstract
class CareProvider
{
public:
    bool isEngaged;//tracks if with a patient
    int timeLimit;//tracks their total time to treat any patient
    int timeStart;//tracks when they are paired with patient initially
    int timeEnd;//tracks when they have ended treatment
    Patient currentPatient;//assigns a patient for passing parameters
    std::string type;//was having issues with typeid, so I just did this as a workaround

    //Base empty constructor
    CareProvider();

    bool getEngaged(); //return true if worker is with patient
    void doubleUp(int currenttime, Patient p);//assign a patient to worker and initialize treatment time
    bool treat(int currenttime);//check in every minute to see if we have reached the end of their treatment
    Patient release();//send patient back to town and create a visit object
   virtual std::string getType(){return type;}//returns type of doctor or nurse
  
};

#endif