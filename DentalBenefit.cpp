#include "DentalBenefit.h"
#include <iostream>
using namespace std;
#include <string.h>

DentalBenefit::DentalBenefit()
{

}
DentalBenefit::~DentalBenefit()
{
                //dtor
}
void DentalBenefit::setInfo()
{
      cout<<"Enter Dental Benefit Details : " ;
      cin>>info;
      cin.ignore();
      Benefit::setInfo();
}
double DentalBenefit::calculateBenefit()
{
return (Benefit::calculateBenefit()*10)/100;
}
string DentalBenefit::getDetails()
{
return "\nDental Benefit Information : "+ info + Benefit::getDetails() ;
}
