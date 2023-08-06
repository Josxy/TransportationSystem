#include "Branch.h"
//defaul no-argument constructor.
Branch::Branch()
{
	this->Bid = -1;
	this->cityName = new char[27];
	strcpy(this->cityName, "Undefined");
	this->numberOfVehicles = 0;
	for (int i = 0; i < 30; i++)
	{
		this->vehicles[i] = new Vehicle();
	}
}
//constructor for specific input
Branch::Branch(int id, const char* cName)
{
	this->Bid = id;
	this->cityName = new char[27];
	strcpy(this->cityName, cName);
	this->numberOfVehicles = 0;
	for (int i = 0; i < 30; i++)
	{
		this->vehicles[i] = new Vehicle();
	}
}
//destructor
Branch::~Branch()
{
	delete[] cityName;
	delete[] vehicles;
}
//setter for id
void Branch::setID(int id)
{
	this->Bid = id;
}
//setter for cityname
void Branch::setCityName(const char* cName)
{
	this->cityName = new char[27];
	strcpy(this->cityName, cName);
}
//setter for number of vehicles
void Branch::setNumberOfVehicles(int vehicleNum)
{
	this->numberOfVehicles = vehicleNum;
}
//setter for the vehicle, according to input. if the type is 0, it will create a bus, else it will create a car.
void Branch::setVehicles( int vid, const char* brand, const char* model, const char* plateNo,int type,int busSeat)
{
	if (type == 0)
	{
		this->vehicles[numberOfVehicles] = new Bus(vid, brand, model, plateNo, busSeat);
	}
	else
	{
		this->vehicles[numberOfVehicles] = new Car(vid, brand, model, plateNo, type);
	}
}
//getter for id
int Branch::getID()const
{
	return this->Bid;
}
//getter for city name
char* Branch::getCityName()const
{
	return this->cityName;
}
//getter for number of vehicles
int Branch::getNumberOfVehicles()const
{
	return this->numberOfVehicles;
}
//getter for vehicle for a specific index.
Vehicle* Branch::getVehicles(int index)const
{
	return this->vehicles[index];
}
//this function add a vehicle to branch. it simply uses the setVehicles function and increase the number of vehicles.
void Branch::addVehicle()
{
	int vehicleID,type,busSeats = 0;
	char vehicleBrand[27], vehicleModel[27], vehiclePN[27];
	cout << "What kind of vehicle would You like to add?\nPossible options: (0) Bus, (1) Sedan, (2) Hatchback, (3) Limousine\nYour Choise: ";
	cin >> type;
	cout << "Please enter the ID of the vehicle: ";
	cin >> vehicleID;
	cout << "Please enter the brand of the vehicle: ";
	cin >> vehicleBrand;
	cout << "Please enter the model of the vehicle: ";
	cin >> vehicleModel;
	cout << "Please enter the plate number of the vehicle: ";
	cin >> vehiclePN;
	if (type == 0)
	{
		cout << "Please enter the number of seats on the Bus: ";
		cin >> busSeats;
	}
	this->setVehicles(vehicleID, vehicleBrand, vehicleModel, vehiclePN, type, busSeats);
	this->numberOfVehicles++;
}
//this function prints the information about branch
void Branch::printBranch()const
{
	cout << "\nCity Name Of the Branch: " << this->cityName << " Number of Vehicles: " << this->numberOfVehicles << endl;
}
//this function prints the vehicles of branches.
void Branch::printVehicles()
{
	cout << "\nVehicles at Branch with ID: " << this->Bid << endl;
	for (int i = 0; i < this->numberOfVehicles; i++)
	{
		this->vehicles[i]->printVehicle();
	}
}
//this function first checks for the type which is given by input, then it prints vehicles with the same type.
void Branch::printVehicleByType(int type)
{
	for (int i = 0; i < this->numberOfVehicles; i++)
	{
		if (type == this->vehicles[i]->getType())
		{
			this->vehicles[i]->printVehicle();
		}
	}
}
//this function prints the type statistics.
void Branch::printTypeStatistics()
{
	int carCounter = 0, busCounter = 0;
	for (int i = 0; i < this->numberOfVehicles; i++)
	{
		if (this->vehicles[i]->getType() == 1)
		{
			carCounter++;
		}
		else if (this->vehicles[i]->getType() == 0)
		{
			busCounter++;
		}
	}
	cout << "\t" << busCounter << " bus(es)\n\t" << carCounter << " car(s)" << endl;;
}
//this function prints the vehicles that can carry the number of people that are given by input.
void Branch::printVehicleBySeat(int seat, int id)
{
	for (int i = 0; i < this->numberOfVehicles; i++)
	{
		if (this->vehicles[i]->checkSuitability(seat) == 1)
		{
			cout << "Vehicle at Branch with ID: " << id << endl;
			this->vehicles[i]->printVehicle();
		}
	}
}
//this function prints the annual cost of the vehicles.
float Branch::printAnnualCost()
{
	float totalCost = 0;
	for (int i = 0; i < this->numberOfVehicles; i++)
	{
		if (this->vehicles[i]->getType() == 0)
		{
			int mCost,service;
			cout << "\nEnter the maintenance cost: ";
			cin >> mCost;
			cout << "Enter the number of times bus has been serviced: ";
			cin >> service;
			totalCost += this->vehicles[i]->annualCost(mCost,service);
		}
		else if (this->vehicles[i]->getType() == 1)
		{
			float km;
			cout << "Vehicle " << (i + 1) << "\nPlease enter the kilometers driven: ";
			cin >> km;
			totalCost+=this->vehicles[i]->annualCost(km,0);
		}
	}
	return totalCost;
}
//this function checks if there is a bus in the list of vehicles
int Branch::isThereBus()
{
	int ThereIs = 1;
	for (int i = 0; i < this->numberOfVehicles; i++)
	{
		if (this->vehicles[i]->getType() == 0)
			ThereIs = 0;
	}
	return ThereIs;
}
//this function checks if there is a car in the list of vehicles
int Branch::isThereCar()
{
	int ThereIs = 0;
	for (int i = 0; i < this->numberOfVehicles; i++)
	{
		if (this->vehicles[i]->getType() == 1)
			ThereIs = 1;
	}
	return ThereIs;
}