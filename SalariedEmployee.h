#include<string.h>
#include"Employee.h"
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

class SalariedEmployee : public Employee
{
public:
    SalariedEmployee();
    virtual ~SalariedEmployee();
     void ReadInput();
     virtual double getSalary();
     virtual string getDetails();
protected:
double salary;
private:
};

#endif // SALARIEDEMPLOYEE_H
