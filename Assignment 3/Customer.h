#pragma once
#include"Person.h"
#include<iostream>
#include<string>


using namespace std;
class Customer : public Person{
private:
    int mechanicID;
    Appointment appointment;
public:
    Customer() {}
    Customer(string name, int ID, int age, int mechanicID, Appointment appointment)
        : Person(name, id, age), mechanicID(mechanicID), appointment(appointment) {}
    void setMechanicID(int mechanicID) ;

    void setAppointment(Appointment appointment) ;

    int getMechanicID();

    Appointment getAppointment();
    void printInfo();

    bool operator<(const Customer& other) const;

    bool operator>(const Customer& other) const;

    bool operator==(const Customer& other) const;
};
    
    
    
    

