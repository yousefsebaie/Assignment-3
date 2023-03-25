#pragma once
#include<string>
#include"Person.h"
using namespace std;

class Mechanic : public Person
{
private:
    int counter;
    Appointment appointments[24];


public:
    Mechanic() {}
    Mechanic(string name, int id, int age) : Person(name, id, age), counter(0) {
        for (int i = 0; i < 24; i++) {
            appointments[i].hours = i;
            appointments[i].mins = 0;
        }
    }
    bool isAvailable(Appointment appointment) {
        return appointments[appointment.hours].mins == 0;
    }
    void bookAppointment(Appointment appointment);
    

    void unbookAppointment(Appointment appointment);

    int getCounter() { return counter; }
    void printInfo() {
        cout << "Mechanic " << getName() << " has " << counter << " appointments today" << endl;
    }
};

    
