#pragma once
#include "Vehicle.h"

class Car:virtual public Vehicle
{
private:
	enum carType { None, Sedan, Hatchback, Limousine };
	carType type;
public:
	Car();
	Car(int, const char*, const char*, const char*,int);
	~Car();
	int getSeats();
	int checkSuitability(int);
	float annualCost(float,int);
	void printVehicle();
	//additinioal function
	int getType();
};

