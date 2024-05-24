#include "Department.h"
Department::Department()
{

}
Department::~Department()
{
}
void Department::set_newDepart()
{
    cout<<"Enter Department Name : ";
    cin>>departName;
    cout<<"Enter Department ID : ";
    cin>>departID;
}
void Department::Print()
{
    cout<<"Depart Name : "<<departName
        <<"\nDepart ID : "<<departID<<endl;
}
string Department::getdepartName()
{
return departName;
}
int Department::getdepartID()
{
    return departID;
}
