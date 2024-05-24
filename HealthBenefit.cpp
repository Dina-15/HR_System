#include "HealthBenefit.h"
#include <string.h>

HealthBenefit::HealthBenefit()
{

}
HealthBenefit::~HealthBenefit()
{
    //dtor
}
void HealthBenefit::setInfo()
{
      cout<<"Enter Health Benefit Details : " ;
      cin>>info;
      cin.ignore();
      cout<<"Enter Coverage : ";
      cin>>coverage;
      Benefit::setInfo();
}
double HealthBenefit::calculateBenefit()
{
return (Benefit::calculateBenefit()*20)/100;
}
string HealthBenefit::getDetails()
{
return  "Health Benefit Information : " + info +"\nCoverage : " + coverage+Benefit::getDetails() ;
}
