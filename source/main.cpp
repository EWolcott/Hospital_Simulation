#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Hospital.h"


int main()
{
    srand(time(0)); //seed a random number
  int Totalminutes = 0; //minutes passed
  int pCount = 0; //patients visited per hour
  int pLimit = 4; //patient rate
  int hourlyminutes; //minutes/hour
  int input; //user input
  int totalpatients = 0; //total patients
  bool browsing = true;

  std::cout << "How many patients would you like per hour?" << std::endl;
  std::cin >> pLimit;

  Hospital h;//build a hospital

  std::cout << "How many Doctors are employed??" << std::endl;//add doctors
    std::cin >> input;
    h.addDoctors(input);
  std::cout << "How many Nurses are employed??" << std::endl;//add nurses
std::cin >> input;
    h.addNurses(input);
 while (Totalminutes < 10080){ //loop for every minute in a week
    hourlyminutes = 0;
    pCount = 0;
  while (hourlyminutes < 60){
      h.Carefor(Totalminutes+hourlyminutes);//checkup on all treating patients
    
      if((pLimit-pCount == 60-hourlyminutes)  && (pCount < pLimit) ){//if the random generator has not been able to 
                                                            //meet needed rate of patients, start pumping them out
            pCount++;
            h.admitPatient(Totalminutes+hourlyminutes);//admit a patient to the queue
        }
      
      else if((rand()%100<20) && (pCount < pLimit) ){ //else randomize the patients so they don't all arrive one after th other
      
            pCount++;
            h.admitPatient(Totalminutes+hourlyminutes);//admit a patient to the queue
        }
        
      hourlyminutes++;
  }
  Totalminutes = Totalminutes +60; //total minutes passed
  totalpatients = totalpatients+pCount; //total patients admitted
}  
 std::cout << "Average wait time: "<< h.calculateAverageWait() << " minutes. Total patients: " << totalpatients << std::endl;
 while(browsing){
 std::cout << "What would you like to do now?" << std::endl;
   std::cout << "1. Print all patients." << std::endl;
    std::cout << "2. Check patient visit history" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cin >> input;
    std::string choice;
    switch(input){
      case 1: for(int i = 0; i < h.YeOldeIll.size(); i++){
        std::cout << h.YeOldeIll[i] << std::endl;
      }break;
      case 2: std::cout << "Which patient would you like to review?" << std::endl;
      std::cin.ignore();
      std::getline(std::cin, choice);
      std::cout << choice << std::endl;
      h.searchRecords(choice); break;
      case 3: browsing = false; break;
      break;
      
    }
 }
}

