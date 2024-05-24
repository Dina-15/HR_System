#include <string.h>
#include <iostream>
#include"Employee.h"
using namespace std;
#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

class CommissionEmployee : public Employee
{
public:
    CommissionEmployee();
    virtual ~CommissionEmployee();
    void ReadInput();
    string getDetails();
    double getSalary();
protected:

private:
double target , rate;
};

#endif // COMMISSIONEMPLOYEE_H
