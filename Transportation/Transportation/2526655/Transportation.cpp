#include <iostream>
#include "Company.h"
using namespace std;

int main()
{
    Company* c1;
    c1 = new Company("Apple");

    int selecter = 0;
    cout << "Welcome to Quick Transports" << endl;
    while (selecter != 9)
    {
        cout << "Options:\n1. Add a new branch to the company." << endl;
        cout << "2. Add a new vehicle(car or bus) to a branch." << endl;
        cout << "3. Print all the branches along with their cities and the number of vehicles." << endl;
        cout << "4. Print the details stored as member variables for the vehicles in each branch." << endl;
        cout << "5. Print the details stored as member variables for the vehicles in each branch whose type is a given type." << endl;
        cout << "6. Print the number of each type of vehicle in each branch." << endl;
        cout << "7. Print the details stored as member variables for the vehicles that can carry a given number of people in each branch." << endl;
        cout << "8. Calculate the total annual cost for the company." << endl;
        cout << "9. Exit" << endl;
        cout << "Your selection: ";
        cin >> selecter;
        if (selecter == 1)
        {
            c1->addBranch();
        }
        else if (selecter == 2)
        {
            c1->newVehicle();
        }
        else if (selecter == 3)
        {
            c1->printBranches();
        }
        else if (selecter == 4)
        {
            c1->printVehicles();
        }
        else if (selecter == 5)
        {
            int type;
            cout << "Please select the type of the vehicles, You want to see: (0) Bus, (1) Car: ";
            cin >> type;
            c1->printVehicleByType(type);
        }
        else if (selecter == 6)
        {
            c1->printTypeStatistics();
        }
        else if (selecter == 7)
        {
            int seat;
            cout << "Please enter the number of passengers vehicle should be able to carry: ";
            cin >> seat;
            c1->printVehicleBySeat(seat);
        }
        else if (selecter == 8)
        {
            c1->printAnnualCost();
        }
    }
    cout << "Good Bye!" << endl;
}
