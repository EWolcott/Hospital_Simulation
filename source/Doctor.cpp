#include "CareProvider.h"
#include "Doctor.h"

//Base empty constructor

Doctor::Doctor()
{
    isEngaged = false;
    timeLimit = 20; //how long the doctor might take to treat a patient
    type = "Doctor";
    timeStart = 0;
    
}

std::string Doctor::getType(){
   return type;
}