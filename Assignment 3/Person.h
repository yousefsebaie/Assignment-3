#include <string>
#include<iostream>
using namespace std;

class Person { 
protected:
    string name;
    int id;
    int age;
public:
    Person() {}
    Person(string name, int id, int age) : name(name), id(id), age(age) {}
    void setName(string name);

    void setID(int id);
    void setAge(int age);
    string getName();
    int getID();
    int getAge();
    virtual void printInfo() = 0;
};

// Struct Appointment
struct Appointment {
    int hours;
    int mins;
};

