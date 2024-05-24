#include <string.h>
#include <iostream>
#include"Benefit.h"
using namespace std;
#ifndef DENTALBENEFIT_H
#define DENTALBENEFIT_H
class DentalBenefit : public Benefit
{
public:
    DentalBenefit();
    virtual ~DentalBenefit();
    double calculateBenefit();
    void setInfo();
    string getDetails();
protected:

private:
    string info;
};

#endif // DENTALBENEFIT_H
