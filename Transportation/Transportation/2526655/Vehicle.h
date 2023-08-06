#pragma once
#include <iostream>
#include <string.h>

using namespace std;
class Vehicle
{
private:
	int Vid;
	char* brand;
	char* model;
	char* plateNo;
public:
	Vehicle();
	Vehicle(int, const char*, const char*, const char*);
	~Vehicle();
	void setId(int);
	void setBrand(const char*);
	void setModel(const char*);
	void setPlateNo(const char*);
	int getId()const;
	char* getBrand()const;
	char* getModel()const;
	char* getPlateNo()const;
	//virtual functions, which are same for car and bus classes.
	virtual void printVehicle();
	virtual int getType();
	virtual int checkSuitability(int);
	virtual float annualCost(float,int);
};

