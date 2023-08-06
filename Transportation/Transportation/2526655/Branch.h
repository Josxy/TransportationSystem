#pragma once
#include "Car.h"
#include "Bus.h"

class Branch
{
private:
	int Bid;
	char* cityName;
	int numberOfVehicles;
	Vehicle *vehicles[30];
public:
	Branch();
	Branch(int, const char*);
	~Branch();
	void setID(int);
	void setCityName(const char*);
	void setNumberOfVehicles(int);
	void setVehicles(int, const char*, const char*, const char*,int,int);
	int getID()const;
	char* getCityName()const;
	int getNumberOfVehicles()const;
	Vehicle* getVehicles(int)const;
	void addVehicle();
	void printBranch()const;
	void printVehicles();
	void printVehicleByType(int);
	void printTypeStatistics();
	void printVehicleBySeat(int, int);
	float printAnnualCost();
	int isThereBus();
	int isThereCar();
};
 
