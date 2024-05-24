#include<string.h>
#include"SalariedEmployee.h"
#ifndef MANAGEREMPLOYEE_H
#define MANAGEREMPLOYEE_H

class ManagerEmployee : public SalariedEmployee
{
public:
    ManagerEmployee();
    virtual ~ManagerEmployee();
    void ReadInput();
    void addBonus(double moreBonus);
    double getSalary();
    string getDetails();
protected:

private:
double bonus;
};

#endif // MANAGEREMPLOYEE_H
