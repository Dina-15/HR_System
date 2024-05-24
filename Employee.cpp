#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee()
{
    m_depart=nullptr;
    benefitList= new Benefit*[25];
    benefit_size=0;
}

Employee::~Employee()
{
    for(int i=0; i<benefit_size; ++i)
    {
        delete benefitList[i];
    }
    delete [] benefitList;
}
void Employee::ReadInput()
{
    system("Color 09");
    cout<<"Name : ";
    cin>>name;
    cout<<"ID : ";
    cin>>id;
    cout<<"Phone : ";
    cin>>phone;
    cout<<"Email : ";
    cin>>email;
    cout<<"Job Title : ";
    cin>>jobTitle;
    cout<<"\n\t*********************************\n\n";
    int c,ch=-1;
    cout<<"Benefit Package :\n================\n";
    do
    {
        cout<<"1.Health Benefit \n2.Dental Benefit"
            <<"\nEnter Selection : ";
        cin>>c;
        cout<<"--------------------------\n";
        switch(c)
        {
        case 1:
        {
            benefitList[benefit_size++] = new HealthBenefit();
            benefitList[benefit_size-1]->setInfo();
        }
        break;
        case 2:
        {
            benefitList[benefit_size++] = new DentalBenefit();
            benefitList[benefit_size-1]->setInfo();
        }
        break;
        default:
            cout<<"\nInvalid Selection !";
        }
        cout<<"--------------------------\n";
        cout<<"Another Benefit ? (1. Yes , 2. No )  ";
        cin>>ch;
    }
    while(ch==1);
}
double Employee::calculatePay()
{
    double Total_benefit=0.0;
    for(int i=0; i<benefit_size; ++i)
    {
        Total_benefit += benefitList[i]->calculateBenefit();
    }
    return Total_benefit;
}
string Employee::getDetails()
{
    return "\nEmployee Information : "
           "\nName : " + name +
           "\nID : " + to_string(id) +
           "\nEmail : " + email+
           "\nJob Title : " + jobTitle +
           "\nPhone : " + phone +
           ((m_depart!=nullptr)?
            "\n->Department :  " + m_depart->getdepartName()
            : " ");
}
bool Employee::getJobtitle(string key)
{
    if(jobTitle.compare(key)==0)
                return true;
    else
                return false;
}
bool Employee::getName(string key)
{
    if(name.compare(key)==0)
                return true;
    else
                return false;
}
void Employee::getBenefitList()
{
    cout<<"\n================="
        <<"\n=>Benefit Package : "
        <<"\n=================\n";
    for(int i=0; i<benefit_size; i++)
    {
        cout<< benefitList[i]->getDetails() ;
        cout<<"\n================";
    }
}
void Employee::setDepartment(Department * newDepart)
{
    m_depart=newDepart;
}
bool Employee::getDepart(Department * newDepart)
{
    if(newDepart==m_depart)
        return true;
    else
        return false;
}
int Employee::getId()
{
    return id;
}
