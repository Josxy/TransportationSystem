#pragma once
#include "Vehicle.h"

class Bus:virtual public Vehicle
{
private:
	int numberOfSeats;
public:
	Bus();
	Bus(int, const char*, const char*, const char*, int);
	~Bus();
	int checkSuitability(int);
	float annualCost(float, int);
	void printVehicle();
	//additinioal function
	int getType();
};
