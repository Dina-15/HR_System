#include "ManagerEmployee.h"
#include<string.h>
using namespace std;

ManagerEmployee::ManagerEmployee()
{
    bonus=0;
}
void ManagerEmployee::ReadInput()
{
    SalariedEmployee::ReadInput();
    cout<<"Add Bonus : ";
    cin>>bonus;
    int ch;
    double bon;
    cout<< "Add more bonus ? (1.Yes / 2. No) : ";
    cin>>ch;
    if(ch==1)
    {
        cout<<"Enter Bonus : ";
        cin>>bon;
        addBonus(bon);
    }
}

ManagerEmployee::~ManagerEmployee()
{
    //dtor
}

void ManagerEmployee::addBonus(double moreBonus)
{
    bonus+=moreBonus;
}
double ManagerEmployee::getSalary()
{
    return salary+bonus;
}
string ManagerEmployee::getDetails()
{

    return SalariedEmployee::getDetails()+
           "\nBonus : " + to_string(bonus) +
           "\nSalary after Bonus : " +
           to_string(getSalary());
}
