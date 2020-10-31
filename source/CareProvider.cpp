#include "CareProvider.h"

CareProvider::CareProvider(){
    isEngaged = false;
    timeLimit = 10;
    type = "";
    timeStart = 0;
    
}

bool CareProvider::getEngaged(){ //check if worker is with a patient
    return isEngaged;
}

void CareProvider::doubleUp(int currenttime, Patient p){ //assign a worker to a patient
    currentPatient = p;
    treat(currenttime);
}


bool CareProvider::treat(int currenttime){
    bool healed = false;
    if(!isEngaged){ //if starting treatment, determine time needed for treatment
        timeEnd = rand()%timeLimit;
    }
    isEngaged = true;
    if(timeStart == 0){//only adjust this number once for every patient
        timeStart = currenttime;
    }

    if((currenttime-timeStart) == timeEnd){//if done treating, reset values
        isEngaged = false;
        healed = true;
        timeStart = 0;
        return healed; 
    }
    return healed;

}