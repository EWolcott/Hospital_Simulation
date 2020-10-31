#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <unordered_map>
#include <queue>
#include "Patient.h"
#include "Person.h"
#include "CareProvider.h"
#include "Doctor.h"
#include "Nurse.h"

#include "hash.h"

using namespace cs273;
//Hospital class
class Hospital
{
public:
    std::deque<Person> townspeople; //holds the population. I figure since there is an equal probability of them getting
                                    //sick, that just using all of them in a deque would be the least costly to memory 
    std::priority_queue<Patient> waiting_room; //stores patients with <= 10 severity
    std::priority_queue<Patient> emergency_patients;//stores patients with >10 severity
    std::vector<std::string> YeOldeIll; //stores the names of patients, again, this was because the std::unordered_map was giving me trouble
    std::vector<CareProvider> workers;//stores the careproviders
    Hash<Visit> records;//stores all of the visit objects with a patient names as key
    int numpatients;//tracks the number of patients admitted for average calculation
    int waittime;//stores the wait time of patients for average calculation
    int numD;//stores the number of doctors for constructing
    int numN;//stores the number of nurses for constructing

    //Base empty constructor
    Hospital();

    void LoadTownspeople();//build a town wih random names
    void Carefor(int currenttime);//ensures the patients are being assigned and cared for
    std::string getname(); //generates random namefor townspeople
    void admitPatient(int currenttime);//creates new patient from townsperson
    void searchRecords(std::string key);//find an print patient records
    double calculateAverageWait();//find the average of patient wait time
    void addDoctors(int numDoctors);//generate doctors
    void addNurses(int numNurses);//generate nurses
    int getDoctors();//returns number of doctors
    int getNurses();//returns number of nurses
};

#endif