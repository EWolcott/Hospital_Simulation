#include "Visit.h"
//base constructor
Visit::Visit(){
    CheckInTime = 0;
    CheckOutTime = 0;
    TotalTime = 0;
    severityNum = 0;
    patientname = "Jane Doe";
}
//constructor with parameters
Visit::Visit(std::string name, int checkout, int checkin, int severity){
    CheckInTime = checkin;
    CheckOutTime = checkout;
    TotalTime = (checkout-checkin);
    severityNum = severity;
    patientname = name;
}

int Visit::getCheckIn(){
    return CheckInTime;
}

void Visit::convertTime(int minutes){//convert the time into a more legible format
int tot_mins = minutes;
int days = tot_mins / 1440;
int hours = (tot_mins % 1440)/60;
int mins = tot_mins % 60;
std::cout << days << " days, " << hours << " hours, " << mins << " minutes " ;
}

std::string Visit::getName(){
    return patientname;
}
int Visit::getCheckOut(){
    return CheckOutTime;
}
int Visit::totaltime(){
    return TotalTime;
}
int Visit::getSeverity(){
    return severityNum;
}
void Visit::toString(){
    std::cout << "Patient: " << patientname << std::endl;
     std::cout << "Admitted at ";  
      convertTime(CheckInTime);
      std::cout << "With a severity of level " << severityNum << std::endl;
      std::cout << "Released at ";
      convertTime(CheckOutTime);
        std::cout << "Total wait time: " << TotalTime << " minutes." << std::endl;

}