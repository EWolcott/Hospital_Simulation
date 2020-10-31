#include "Hospital.h"
#include <list>

Hospital::Hospital(){
    LoadTownspeople();
    numpatients = 0;
    waittime = 0;
}

void Hospital::LoadTownspeople(){ //generate a town
    for(int i = 0; i < 2000; i++){
        std::string dummyname = getname();
        Person p(dummyname);
        townspeople.push_back(p);
    }
}

void Hospital::Carefor(int currenttime){
     for(int i = 0; i < workers.size(); i++){//make sure all engaged workers treat patients
       if(workers[i].getEngaged()){
            if(workers[i].treat(currenttime)){//if done treating, make a record of visit
                 Visit over(workers[i].currentPatient.getName(), currenttime, workers[i].currentPatient.timeOfAdmission, workers[i].currentPatient.getSeverity()); 
                  pair<Visit> q(over.patientname, over);  
                    records.insert(q);
                 
                 waittime = waittime + (currenttime - workers[i].currentPatient.timeOfAdmission); //adjust accumulated wait time
                 Person revive(over.getName());
                  townspeople.push_back(revive);  //release back into the wild
                  workers[i].currentPatient.toString(); 
   std::cout << ", released at " << currenttime << " for a total time of " << (currenttime - workers[i].currentPatient.timeOfAdmission) << std::endl;
            }
       }
   } 
    if (!waiting_room.empty()||!emergency_patients.empty()){ //assign careworkers to patients if available
        for(int i = 0; i < workers.size(); i++){//use the nurses for low level patients first
            if (workers[i].getType() == "Nurse" && workers[i].getEngaged()==false && waiting_room.empty() == false){
                workers[i].doubleUp(currenttime, waiting_room.top());
               // inTreatment.push_back(waiting_room.top());
                waiting_room.pop();
            }//assign available doctors to high severity patients
            if (workers[i].getType() == "Doctor" && workers[i].getEngaged()==false && emergency_patients.empty() == false){
                workers[i].doubleUp(currenttime, emergency_patients.top());
               // inTreatment.push_back(waiting_room.top());
                emergency_patients.pop();
            }
        }
        for(int i = 0; i < workers.size(); i++){//then use a doctor on a lowlevel patient if no nurse available
            if (workers[i].getType() == "Doctor" && workers[i].getEngaged()==false && waiting_room.empty() == false){
                workers[i].doubleUp(currenttime, waiting_room.top());
               // inTreatment.push_back(waiting_room.top());
                waiting_room.pop();
            }
        }
    }
  
}

std::string Hospital::getname() //random name generator for town 
{
    std::vector<std::string> _firstNames;
    std::vector<std::string> _lastNames;

    _firstNames = {"Roy", "Wyatt", "Owen", "Herschel", "Bill", "Florencio", "Guy", "Renato", "Octavio", "Alexis",
                   "Gaylord", "Kyle", "Danny", "Aurelio", "Wilfredo", "Mel", "Rosario", "Clay", "Max", "Dino", "Elvin",
                   "Donnell", "Darrell", "Seymour", "Chong", "Lionel", "Noel", "Victor", "Marc", "Trevor", "Rusty", "Russ",
                   "Jonathan", "Chris", "Chauncey", "Emmitt", "Antony", "Deandre", "Anthony", "Raymond", "Eliseo", "Kris",
                   "Travis", "Felton", "Britt", "Pierre", "Patrick", "Mauro", "Erwin", "Gregorio"};
    _lastNames = {"Parrish", "Garner", "Blackwell", "Valentine", "Guerra", "Cox", "Kirk", "Clements", "Pratt",
                  "Coffey", "Romero", "Mayo", "Patel", "Page", "Oneal", "Bowen", "Chapman", "Buchanan", "Schmitt", "Mckee",
                  "Foster", "Collier", "Shea", "Velez", "Booth"};

    std::string first = _firstNames[rand() % 50];
    std::string last = _lastNames[rand() % 25];
    std::string name = first + " " + last;
    return name;
}

void Hospital::admitPatient(int currenttime){ //remove person from town, admit as patient, assign to priority queue
    if(!townspeople.empty()){
   Patient p(townspeople.front().getName(), currenttime);
   if (p.severityNum > 10){ //assign to doctor queue
       emergency_patients.push(p);
   }
   else{
   waiting_room.push(p);//assign to general queue
   }
   townspeople.pop_front();//remove from deque
   YeOldeIll.push_back(p.getName()); //but store the name for recall
   p.toString(); 
   std::cout << ", admitted at " << currenttime << std::endl;
    numpatients++; //track for average-sake
    }
}

void Hospital::searchRecords(std::string key){

int index;
    index = records.hash_it_up(key); //find vector placement
    typename std::list<pair<Visit>>::iterator j = records.data[index].begin();
    for (j = records.data[index].begin(); j != records.data[index].end(); j++)
    {
        if (j->first == key)
        { //find linked list placement

            j->second.toString();
        }
 
}
}

double Hospital::calculateAverageWait(){
    double total = 0.0;
    total = (waittime/numpatients);
    return total;
}

void Hospital::addDoctors(int numDoctors){
    numD = numDoctors;
    for(int i = 0; i< numDoctors; i++){
        Doctor d;
        workers.push_back(d);
    }
}

void Hospital::addNurses(int numNurses){
    numN = numNurses;
    for(int i = 0; i< numNurses; i++){
        Nurse n;
        workers.push_back(n);
    }
}

int Hospital::getDoctors(){
    return numD;
}

int Hospital::getNurses(){
    return numN;
}