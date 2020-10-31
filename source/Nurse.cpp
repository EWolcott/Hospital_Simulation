#include "CareProvider.h"
#include "Nurse.h"

//Base empty constructor

Nurse::Nurse()
{
    isEngaged = false;
    timeLimit = 10; //how long the nurse might take to treat a patient
    type = "Nurse";
    timeStart = 0;
}

std::string Nurse::getType(){
    return type;
}
