#include "Company.h"
//defaul no-argument constructor.
Company::Company()
{
	this->CompanyName = new char[27];
	strcpy(this->CompanyName, "Undefined");
	this->numberOfBranches = 0;
	for (int i = 0; i < 10; i++)
	{
		this->branches[i] = new Branch();
	}
}
//constructor for specific input
Company::Company(const char* companyName)
{
	this->CompanyName = new char[27];
	strcpy(this->CompanyName, companyName);
	this->numberOfBranches = 0;
	for (int i = 0; i < 10; i++)
	{
		this->branches[i] = new Branch();
	}
}
//destructor
Company::~Company()
{
	delete[] CompanyName;
	delete[] branches;
}
//setter for company name
void Company::setCompanyName(const char* cName)
{
	this->CompanyName = new char[27];
	strcpy(this->CompanyName, cName);
}
//setter for number of branches
void Company::setNumberOfBranches(int branchNum)
{
	this->numberOfBranches = branchNum;
}
//setter for a new branch to company
void Company::setbranches(int id,const char* name)
{
	this->branches[this->numberOfBranches] = new Branch(id,name);
}
//getter for a company name
char* Company::getCompanyName()const
{
	return this->CompanyName;
}
//getter for numberOfBranches
int Company::getBranchNumber()const
{
	return this->numberOfBranches;
}
//getter for a branch with the spesific index
Branch* Company::getBranches(int index)const
{
	return this->branches[index];
}
//this function is checks is there a branch with the given ID.
int Company::isIn(int ID)
{
	int isIn = 0;
	for (int i = 0; i < this->numberOfBranches; i++)
	{
		if (ID == this->branches[i]->getID())
		{
			isIn = 1;
		}
	}
	return isIn;
}
//this function finds the index of the branch with the given ID. I used it to add a new vehicle to company's branch correctly.
int Company::whichIndex(int ID)
{
	int index = 100;
	for (int i = 0; i < this->numberOfBranches; i++)
	{
		if (ID == this->branches[i]->getID())
		{
			index = i;
		}
	}
	return index;
}
//this is my addBranch function. it simply uses the setter for a branch function and increases the number of branches.
void Company::addBranch()
{
	char cityName[27];
	int id;
	cout << "Please enter branch's ID: ";
	cin >> id;
	cout << "Please enter the city, where branch is located : ";
	cin >> cityName;
	this->setbranches(id, cityName);
	this->numberOfBranches++;
}
//this function is kind a bridge through company to a vehicle. I use it to add a new vehicle to a company's branch.
void Company::newVehicle()
{
	int branchID;
	cout << "Please enter the ID of the Branch: ";
	cin >> branchID;
	if (this->isIn(branchID) == 0)
	{
		cout << "There is no branch with ID" << branchID << "at Quick Transport" << endl;
	}
	else
	{
		this->getBranches(this->whichIndex(branchID))->addVehicle();
	}
}
//this function prints the branches
void Company::printBranches()const
{
	cout << "\n---------BranchesOnly-------\n";
	for (int i = 0; i < this->numberOfBranches; i++)
	{
		this->branches[i]->printBranch();
	}
}
//this function print vehicles.
void Company::printVehicles()const
{
	cout << "\n---------VehiclesOnly-------\n";
	for (int i = 0; i < this->numberOfBranches; i++)
	{
		this->branches[i]->printVehicles();
	}
}
//this function prints the vehicles by the given type.
void Company::printVehicleByType(int type)
{

	for (int i = 0; i < this->numberOfBranches; i++)
	{
		if (type == 0)
		{
			if (this->branches[i]->isThereBus() == type)
			{
				cout << "Vehicle at Branch with ID: " << this->branches[i]->getID() << endl;
				this->getBranches(this->whichIndex(this->branches[i]->getID()))->printVehicleByType(type);
			}
		}
		if (type == 1)
		{
			if (this->branches[i]->isThereCar() == type)
			{
				cout << "Vehicle at Branch with ID: " << this->branches[i]->getID() << endl;
				this->getBranches(this->whichIndex(this->branches[i]->getID()))->printVehicleByType(type);
			}
		}
		
	}
}
//this function prints the statistics for the type.
void Company::printTypeStatistics()
{
	for (int i = 0; i < this->numberOfBranches; i++)
	{
		cout << "At Branch with ID: " << this->branches[i]->getID() << " there are: \n";
		this->getBranches(this->whichIndex(this->branches[i]->getID()))->printTypeStatistics();
	}
}
//this function prints the vehicles that can carry the number of people that are given by input.
void Company::printVehicleBySeat(int seat)
{
	for (int i = 0; i < this->numberOfBranches; i++)
	{
		this->getBranches(this->whichIndex(this->branches[i]->getID()))->printVehicleBySeat(seat,this->branches[i]->getID());
	}
}
//this function prints the annual cost of the vehicles.
void Company::printAnnualCost()
{
	int Cost = 0;
	for (int i = 0; i < this->numberOfBranches; i++)
	{
		cout << "Vehicles at Branch with ID " << this->branches[i]->getID() << ":";
		Cost = this->getBranches(this->whichIndex(this->branches[i]->getID()))->printAnnualCost();
		cout << "Total Annual Cost for Branch with ID: " << this->branches[i]->getID() << " is " << Cost << endl;
	}
}