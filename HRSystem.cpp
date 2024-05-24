#include "HRSystem.h"
#include <iostream>
#include <stdlib.h>  // cls , pause
using namespace std;

HRSystem::HRSystem(int e_size=25)
{
    m_size =e_size;
    EmployeeList = new Employee*[m_size];
    e_counter=0;
}
HRSystem::~HRSystem()
{
    for(int i=0 ; i<e_counter; ++i)
    {
        delete EmployeeList[i];
    }
    delete [] EmployeeList;
}
void HRSystem::calcTotalPayroll()
{
    cout<<"EMPLOYEE TOTAL PAYROLL ....\n-------------------------\n";
    double Total_pay=0.0;
    for(int i=0; i<e_counter; ++i)
    {
        Total_pay += EmployeeList[i]->getSalary() + EmployeeList[i]->calculatePay() ;
    }
    cout<<"\n\t->Total pay : "<<Total_pay<<"   For ( "<< e_counter
    <<" ) Employee \n\t->Average Salary : "
    <<Total_pay/e_counter<<endl;
    system("pause");
}
void HRSystem::addEmployee(Department *newDepart)
{
    system("cls");
    system("Color 04");
    int ch;
    cout<<"Employee type :\n1.Hourly Employee\n2.Salaried Employee\n3.Manager Employee\n4.Commission Employee\n";
    cout<<"Enter Your Selection : ";
    cin>>ch;
    bool valid=true;
    switch(ch)
    {
    case 1:
    {
        system("cls");
        EmployeeList[e_counter++] = new HourlyEmployee();
    }
    break;
    case 2:
    {
        system("cls");
        EmployeeList[e_counter++] = new SalariedEmployee();
    }
    break;
    case 3:
    {
        system("cls");
        EmployeeList[e_counter++] = new ManagerEmployee();
    }
    break;
    case 4:
    {
        system("cls");
        EmployeeList[e_counter++] = new CommissionEmployee();
    }
    break;
    default:
        valid=false;
        cout<<"\nInvalid Selection !";
    }
    if(valid)
    {
        EmployeeList[e_counter-1]->ReadInput();
        Employee *ptr = EmployeeList[e_counter-1];
        ptr->setDepartment(newDepart);
        system("pause");
    }

}
void HRSystem::SearchDepart(Department *newDepart)
{
    system ("cls");
    if(e_counter>0)
    {
        double Depart_Total_pay=0.0;
        int d_counter=0;
        for(int i=0 ; i<e_counter; ++i)
        {
            if(EmployeeList[i]->getDepart(newDepart))
            {
                cout<<EmployeeList[i]->getDetails();
                EmployeeList[i]->getBenefitList();
                cout<<"-----------------------------------";
                Depart_Total_pay += EmployeeList[i]->getSalary() + EmployeeList[i]->calculatePay() ;
                d_counter++;
            }
        }
        cout<<"\n\t-> Total pay : "<<Depart_Total_pay
            <<"   For ( "<< d_counter
            <<" ) Employee in This Department !\n\t-> Average Salary of this Department is : "
            <<Depart_Total_pay/d_counter<<endl;
    }
    else
        cout<<"There are no Employees in this Department !\n";
}
void HRSystem::delDepart(Department* newDepart)
{
    bool deleted=false;
    for(int i=0 ; i<e_counter; ++i)
    {
        if(EmployeeList[i]->getDepart(newDepart))
        {
            //delete from array
            if(i==e_counter-1)//last element
                e_counter--;
            else
            {
                //replace deleted with last Employee
                EmployeeList[i]=EmployeeList[e_counter-1];
                e_counter--;
            }
            deleted=true;
            break;
        }
    }
    if(deleted)
    {
        cout<<"Department Deleted Successfully !\n";
    }
    else
        cout<<"There are no Employees in this Department !\n";
}
void HRSystem::editEmployee(int id)
{
    if(e_counter==0)
    {
        cout<<"No Employee Exist !\n";
        return;
    }
    bool edited=false;
    for(int i=0; i<e_counter; i++)
    {
        if( EmployeeList[i]->getId()==id)
        {
            EmployeeList[i]->ReadInput();

            edited=true;
            break;
        }
    }
    if(edited)
    {
        cout<<"Employee Edited Successfully !\n";
    }
    else
        cout<<"This Employee is not Exist ,Try again !\n";
    system("pause");
}
void HRSystem::delEmployee(int id)
{
    if(e_counter==0)
    {
        cout<<"No Employee Exist !\n";
        return;
    }
    bool deleted=false;
    for(int i=0; i<e_counter; i++)
    {
        if( EmployeeList[i]->getId()==id)
        {
            //delete from array
            if(i==e_counter-1)//last element
                e_counter--;
            else
            {
                //replace deleted with last Employee
                EmployeeList[i]=EmployeeList[e_counter-1];
                e_counter--;
            }
            deleted=true;
            break;

        }
    }
    if(deleted)
    {
        cout<<"Employee Deleted Successfully !\n";
    }
    else
        cout<<"This Employee is not Exist ,Try again !\n";
    system("pause");

}
void HRSystem::findEmployee(string key)
{
    if(e_counter==0)
    {
        cout<<"No Employee Exist !\n";
        return;
    }
    bool found;
    for(int i=0; i<e_counter; i++)
    {
        if( EmployeeList[i]->getName(key))
        {
            cout<<EmployeeList[i]->getDetails();
            EmployeeList[i]->getBenefitList();
            found=true;
            break;
        }
        else if(EmployeeList[i]->getJobtitle(key))
         {
            cout<<EmployeeList[i]->getDetails();
            EmployeeList[i]->getBenefitList();
            found=true;
            break;
        }

    }
    if(found)
        cout<<"FOUND !";
    else
        cout<<"Not Found !";
    system("pause");

}
void HRSystem::showAll()
{
    system("Color 07");
    if(e_counter==0)
    {
        cout<<"No Employee Exist !\n";
        return;
    }
    for(int i=0; i<e_counter; ++i)
    {
        cout<<EmployeeList[i]->getDetails();
        EmployeeList[i]->getBenefitList();
        cout<<"\n===================================================\n";
    }
    system("pause");
}

