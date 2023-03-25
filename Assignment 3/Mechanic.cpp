#include "Mechanic.h"

void Mechanic::printInfo()
{
    cout << "Mechanic " << getName() << " has " << counter << " appointments today" << endl;
}

void Mechanic::bookAppointment(Appointment appointment)
{
    appointments[appointment.hours].mins = 1;
    counter++;
}

void Mechanic::unbookAppointment(Appointment appointment)
{
    appointments[appointment.hours].mins = 0;
    counter--;
}
