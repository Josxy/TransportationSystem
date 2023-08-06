#pragma once
#include "Branch.h"

class Company
{
private:
	char* CompanyName;
	int numberOfBranches;
	Branch *branches[10];
public:
	Company();
	Company(const char*);
	~Company();
	void setCompanyName(const char*);
	void setNumberOfBranches(int);
	void setbranches(int,const char*);
	char* getCompanyName()const;
	int getBranchNumber()const;
	Branch* getBranches(int)const;
	void addBranch();
	void printBranches()const;
	void printVehicles()const;
	void printVehicleByType(int);
	void printTypeStatistics();
	void printVehicleBySeat(int);
	void printAnnualCost();
	//my additinioal functions
	void newVehicle();
	int isIn(int);
	int whichIndex(int);
};

