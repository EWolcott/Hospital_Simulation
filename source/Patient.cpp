#include "Patient.h"

Patient::Patient(){
    severityNum = generateSev();
    timeOfAdmission = 0;
}

Patient::Patient(std::string name, int toa){
    severityNum = generateSev();
    timeOfAdmission = toa;
    _name = name;
}

int Patient::getSeverity(){
    return severityNum;
}

int Patient::generateSev(){
         /*
Illnesses with priority 1 to 10 occur approximately 70% of the time with equal probability
    - Illnesses with priority 11 to 15 occur approximately 20% of the time with equal probability.
    - Illnesses with priority 16 to 20 occur approximately 10% of the time with equal probability.
         */
        int result;
        int temp = rand()%100;
        if(temp <= 70){
            result = rand()%10 + 1;
        }
        if(temp >70 && temp <=90){
            result = rand()%5 +11;
        }
        if(temp >90){
            result = rand()%5 +16;
        }
        return result;
}

std::string Patient::getName(){
    return _name;
}

void Patient::toString() //display person name
{
    std::cout << _name << " , " << "Severity level: " << severityNum;
}

bool operator<(const Patient &s, const Patient &t)
{
    return s.severityNum < t.severityNum;
}

bool operator>(const Patient &s, const Patient &t)
{
    return s.severityNum > t.severityNum;
}

bool operator==(const Patient &s, const Patient &t)
{
    return s.severityNum == t.severityNum;
}