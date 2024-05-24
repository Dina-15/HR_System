#include "SalariedEmployee.h"
#include<string.h>
using namespace std;

SalariedEmployee::SalariedEmployee()
{
    salary=0;

}

SalariedEmployee::~SalariedEmployee()
{
    //dtor
}
void SalariedEmployee::ReadInput()
{
    Employee::ReadInput();
    cout<<"\t*********************************\n\nWork Details :\n===============\n";
    cout<<"Enter Salary : ";
    cin>>salary;
}

double SalariedEmployee::getSalary()
{
    return salary;
}
string SalariedEmployee::getDetails()
{
    return Employee::getDetails()+
           "\nSalary : " +
           to_string(salary);
}
