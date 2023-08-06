#include "Vehicle.h"
//defaul no-argument constructor.
Vehicle::Vehicle()
{
	this->Vid = -1;
	this->brand = new char[27];
	this->model = new char[27];
	this->plateNo = new char[27];
	strcpy(this->brand, "Undefined");
	strcpy(this->model, "Undefined");
	strcpy(this->plateNo, "Undefined");
}
//constructor for specific input
Vehicle::Vehicle(int id, const char* brandNew, const char* modelNew, const char* plateNoNew)
{
	this->Vid = id;
	this->brand = new char[27];
	this->model = new char[27];
	this->plateNo = new char[27];
	strcpy(this->brand, brandNew);
	strcpy(this->model, modelNew);
	strcpy(this->plateNo, plateNoNew);
}
//destructor
Vehicle::~Vehicle()
{
	delete[] brand;
	delete[] model;
	delete[] plateNo;
}
//setter for id
void Vehicle::setId(int id)
{
	this->Vid = id;
}
//setter for brand
void Vehicle::setBrand(const char* brandNew)
{
	this->brand = new char[27];
	strcpy(this->brand, brandNew);
}
//setter for model
void Vehicle::setModel(const char* modelNew)
{
	this->model = new char[27];
	strcpy(this->model, modelNew);
}
//setter for plate no
void Vehicle::setPlateNo(const char* plateNoNew)
{
	this->plateNo = new char[27];
	strcpy(this->plateNo, plateNoNew);
}
//getter for id
int Vehicle::getId()const
{
	return this->Vid;
}
//getter for brand
char* Vehicle::getBrand()const
{
	return this->brand;
}
//getter for model
char* Vehicle::getModel()const
{
	return this->model;
}
//getter for plate no
char* Vehicle::getPlateNo()const
{
	return this->plateNo;
}
//this is a virtual function, which never uses directly but it is a must to use it in car and bus classes.
void Vehicle::printVehicle()
{
	cout << "Vehicle ID: " << this->getId() << "\nBrand: " << this->getBrand() << "\nModel: " << this->getModel() << "\nPlate no: " << this->getPlateNo();
}
//this is a virtual function, which never uses directly but it is a must to use it in car and bus classes.
int Vehicle::checkSuitability(int seat)
{
	return seat;
}
//this is a virtual function, which never uses directly but it is a must to use it in car and bus classes. 
int Vehicle::getType()
{
	return 2;
}
//this is a virtual function, which never uses directly but it is a must to use it in car and bus classes.
float Vehicle::annualCost(float f,int nullVar)
{
	return 0;
}