#include"Person.h"
#include"Customer.h"
#include"Mechanic.h"
#include "Queue.h"
#include<queue>
#include <iostream>
using namespace std;

int main() {
    int numMechanics, numCustomers;
    cout << "Enter the number of mechanics: ";
    cin >> numMechanics;
    Mechanic mechanics[numMechanics];
    for (int i = 0; i < numMechanics; i++) {
        string name;
        int id, age;
        cout << "Enter the name of Mechanic " << i + 1 << ": ";
        cin >> name;
        cout << "Enter the ID of Mechanic " << i + 1 << ": ";
        cin >> id;
        cout << "Enter the age of Mechanic " << i + 1 << ": ";
        cin >> age;
        mechanics[i] = Mechanic(name, id, age);
    }
    cout << "Enter the number of customers: ";
    cin >> numCustomers;
    Customer customers[numCustomers];
    for (int i = 0; i < numCustomers; i++) {
        string name;
        int id, age, mechanicID, hours, mins;
        cout << "Enter the name of Customer " << i + 1 << ": ";
        cin >> name;
        cout << "Enter the ID of Customer " << i + 1 << ": ";
        cin >> id;
        cout << "Enter the age of Customer " << i + 1 << ": ";
        cin >> age;
        cout << "Enter the ID of the mechanic assigned to " << name << ": ";
        cin >> mechanicID;
        cout << "Enter the appointment time for " << name << " in the format hh mm: ";
        cin >> hours >> mins;
        Appointment appointment = { hours, mins };
        customers[i] = Customer(name, id, age, mechanicID, appointment);
    }
    Queue<Customer> queue;
    int currentMechanic = 0;
    for (int i = 0; i < numCustomers; i++) {
        int j;
        for (j = 0; j < numMechanics; j++) {
            if (mechanics[currentMechanic].isAvailable(customers[i].getAppointment())) {
                mechanics[currentMechanic].bookAppointment(customers[i].getAppointment());
                customers[i].setMechanicID(mechanics[currentMechanic].getID());
                queue.push(customers[i]);
                break;
            }
            currentMechanic = (currentMechanic + 1) % numMechanics;
        }
        if (j == numMechanics) {
            cout << "No mechanics available for Customer " << customers[i].getName() << " at " << customers[i].getAppointment().hours << ":" << customers[i].getAppointment().mins << endl;
        }
    }
    while (!queue.empty()) {
        Customer customer = queue.front();
        queue.pop();
        cout << endl;
        customer.printInfo();
        Mechanic mechanic = mechanics[customer.getMechanicID() - 1];
        mechanic.printInfo();
        mechanic.unbookAppointment(customer.getAppointment());
    }
    return 0;
}
