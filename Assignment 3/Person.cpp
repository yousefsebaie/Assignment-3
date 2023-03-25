#include "Person.h"
#include <string>

void Person::setName(string name)
{
	this->name = name;
}

void Person::setID(int id)
{
	this->id = id;
}

void Person::setAge(int age)
{
	this->age = age;
}

string Person::getName()
{
	return name;
}

int Person::getID()
{
	return  id;
}

int Person::getAge()
{
	return  id;
}
