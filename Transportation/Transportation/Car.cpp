#include "Car.h"
//defaul no-argument constructor.
Car::Car():Vehicle()
{
	this->type = None;
}
//constructor for specific input
Car::Car(int id, const char* brandNew, const char* modelNew, const char* plateNoNew, int typeNew):Vehicle(id, brandNew, modelNew, plateNoNew)
{
	this->type = carType(typeNew);
}
//destructor
Car::~Car()
{

}
//it gets the number of seats according to type.
int Car::getSeats()
{
	if (this->type == Sedan || this->type == Hatchback)
	{
		return 5;
	}
	else if (this->type == Limousine)
	{
		return 6;
	}
	else
	{
		return 0;
	}
}
//it checksSuitability for printVehicleBySeat function in branch and company classes.
int Car::checkSuitability(int numberOfPeople)
{
	if (numberOfPeople > this->getSeats())
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//it calculates annual Cost for printAnnualCost function in branch and company classes. it has null variable because it is a virtual function, and to calculata cost in bus function, there will be 2 input.
float Car::annualCost(float kilometer,int nullVar)
{
	return kilometer * 10.0;
}
//this function prints the car vehicles
void Car::printVehicle()
{
	cout << "Vehicle ID: " << this->getId() << ", Brand: " << this->getBrand() << ", Model: " << this->getModel() << ", Plate no: " << this->getPlateNo();
	if (this->type == 1)
	{
		cout << ", Type: Sedan " << endl;
	}
	else if (this->type == 2)
	{
		cout << ", Type: Hatchback" << endl;
	}
	else if (this->type == 3)
	{
		cout << ", Type: Limousine" << endl;
	}
	else
	{
		cout << ", Type: None" << endl;
	}
}
//this is useful function to check a vehicle is car or bus. I used it in several functions. 
int Car::getType()
{
	return 1;
}
