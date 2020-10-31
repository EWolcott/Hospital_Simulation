User Runs Simulation

do
{
    prompt user to enter rate of patients per hour
    store response
    prompt user to enter number of Doctors on staff
    store response
    prompt user to enter number of nurses on staff
    store response
    System creates new hospital with specified responses.
    system loads a deque of townspeople with which to generate patients
    system iterates through simulated minutes
    if a minute falls within the specified rate(
        generate patient from townspeople deque
        if severity level <= 10, add it to the waitingroom priority queue
        if severity level >10, add it to the doctor queue.
        search through vector of medical staff for a nurse that is not with a patient,
        and assign a patient to them.
        search through vector of medical staff for a doctor who is not with a patient and assign
        a high priority patient to them.
        if a high priority patient is not waiting for treatment, assign a lower priority patient to the __cpp_delegating_constructors
        treat(), that is, confirm that the endtime generated for the careprovider
        does not yet exceed the time alotted.
    )
    for(every new minute)
        treat(), all workers with patients have their time incremented
        until it becomes equal with the time of care generated

        if(time of care = current time){
            release the patient back to the townspeople vector and generate
            a visit object containing details of visit. store object in a hash table
            with patient name as the key
        }

} while (not reached the end of seven days);
print average wait time and number of patients treated.
ask user for next selection.


*********************************************************************

Printing all patients

User asks to print out all patients treated

for(int i < size of patients vector)
print patients name vector[i]

*********************************************************************

Searching patient records

User asks to see patient records

system asks for full name

user enters full name

system uses input as key to find location of a list on the hashtable
for(iterator i = list.begin(); i != list.end(); i++)
{
    print i->second;
} 

