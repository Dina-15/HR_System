#include "HourlyEmployee.h"
#include<string.h>
using namespace std;

HourlyEmployee::HourlyEmployee()
{
    hoursWorked=0;
    rate=0;
}

HourlyEmployee::~HourlyEmployee()
{
    //dtor
}
void HourlyEmployee::ReadInput()
{
    Employee::ReadInput();
    cout<<"\t*********************************\n\nWork Details :\n===============\n";
    cout<<"Enter Hours Worked : ";
    cin>>hoursWorked;
    cout<<"Enter Rate : ";
    cin>>rate;
    int ch,h;
    cout<<"Add more Hours (1.Yes / 2.No) : ";
    cin>>ch;
    if(ch==1)
    {
        cout<<"Enter More Hours : ";
        cin>>h;
        addHours(h);
    }
}
void HourlyEmployee::addHours(int moreHours)
{
    hoursWorked+=moreHours;
}
double HourlyEmployee::getSalary()
{
    return rate*hoursWorked;
}
string HourlyEmployee::getDetails()
{
    return Employee::getDetails()+
           "\nRate : " + to_string(rate)+
           "\nHours Worked : "+
           to_string(hoursWorked)+
           "\nSalary : "+
           to_string(getSalary());
}
