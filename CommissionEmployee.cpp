#include "CommissionEmployee.h"
#include <iostream>
#include<string.h>
using namespace std;
CommissionEmployee::CommissionEmployee()
{
    target=0;
    rate=0;
}

CommissionEmployee::~CommissionEmployee()
{
    //dtor
}
void CommissionEmployee::ReadInput()
{
    Employee::ReadInput();
    cout<<"\t*********************************\n\nWork Details :\n===============\n";
    cout<<"Enter Target : ";
    cin>>target;
    cout<<"Enter Rate : ";
    cin>>rate;
}
double CommissionEmployee::getSalary()
{
    return rate*target;
}
string CommissionEmployee::getDetails()
{
    return Employee::getDetails()+
           "\nRate : " + to_string(rate)+
           "\nTarget: "+
           to_string(target)+
           "\nSalary : "+
           to_string(getSalary());
}
