#include "Bus.h"
//defaul no-argument constructor.
Bus::Bus():Vehicle()
{
	this->numberOfSeats = 0;
}
//constructor for specific input
Bus::Bus(int id, const char* brandNew, const char* modelNew, const char* plateNoNew, int seatsNew):Vehicle(id, brandNew, modelNew, plateNoNew)
{
	this->numberOfSeats = seatsNew;
}
//destructor
Bus::~Bus()
{

}
//it checksSuitability for printVehicleBySeat function in branch and company classes.
int Bus::checkSuitability(int numberOfPeople)
{
	if (numberOfPeople > this->numberOfSeats)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//it calculates annual Cost for printAnnualCost function in branch and company classes.
float Bus::annualCost(float mCost, int numberOfService)
{
	return mCost * numberOfService;
}
//this function prints the car vehicles
void Bus::printVehicle()
{
	cout << "Vehicle ID: " << this->getId() << ", Brand: " << this->getBrand() << ", Model: " << this->getModel() << ", Plate no: " << this->getPlateNo() << ", Car Type : Bus, Number of Seats : " << this->numberOfSeats << endl;
}
//this is useful function to check a vehicle is car or bus. I used it in several functions. 
int Bus::getType()
{
	return 0;
}