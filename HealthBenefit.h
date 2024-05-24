#include <string.h>
#include"Benefit.h"
using namespace std;
#ifndef HEALTHBENEFIT_H
#define HEALTHBENEFIT_H

class HealthBenefit : public Benefit
{
public:
    HealthBenefit();
    virtual ~HealthBenefit();
    void setInfo();
    double calculateBenefit();
    string getDetails();
protected:

private:
string info,coverage;
};

#endif // HEALTHBENEFIT_H
