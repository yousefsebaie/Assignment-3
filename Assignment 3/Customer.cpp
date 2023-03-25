#include "Customer.h"

void Customer::setMechanicID(int mechanicID)
{
	this->mechanicID = mechanicID;
}

void Customer::setAppointment(Appointment appointment)
{
	this->appointment = appointment;
}

int Customer::getMechanicID()
{
	return mechanicID;
}

Appointment Customer::getAppointment()
{
	return appointment;
}

void Customer::printInfo()
{
	cout << "Mr./Mrs. " << getName() << " has an appointment at " << appointment.hours << ":" << appointment.mins << " with Mechanic " << mechanicID << endl;
}

bool Customer::operator<(const Customer& other) const
{
	if (appointment.hours == other.appointment.hours) {
		return appointment.mins > other.appointment.mins;
	}
	return appointment.hours > other.appointment.hours;
}

bool Customer::operator>(const Customer& other) const
{
	if (appointment.hours == other.appointment.hours) {
		return appointment.mins < other.appointment.mins;
	}
	return appointment.hours < other.appointment.hours;
}

bool Customer::operator==(const Customer& other) const
{
	return appointment.hours == other.appointment.hours && appointment.mins == other.appointment.mins;
}
