#include "Benefit.h"
#include <iostream>
#include <string.h>

using namespace std;

Benefit::Benefit()
{
amount=0;
}
Benefit::~Benefit()
{
    //dtor
}
void Benefit::setInfo()
{
  cout<<"Enter plan type : ";
  cin>>palnType;
  cout<<"Enter amount : ";
  cin>>amount;
}
double Benefit::calculateBenefit()
{
return amount;
}
string Benefit::getDetails()
{
return "\nPlan Type : "+ palnType + "\nAmount : "+ to_string(amount);
}
