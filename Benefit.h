#include <string.h>
#include <iostream>
using namespace std;
#ifndef BENEFIT_H
#define BENEFIT_H

class Benefit
{
public:
      Benefit();
    virtual ~Benefit();
    virtual void setInfo();
    virtual double calculateBenefit();
    virtual string getDetails();
protected:
string palnType;
double amount;
private:
};

#endif // BENEFIT_H
