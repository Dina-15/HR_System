#include <string.h>
#include"Employee.h"
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

class HourlyEmployee : public Employee
{
public:
    HourlyEmployee();
    virtual ~HourlyEmployee();
    void ReadInput();
    void addHours(int moreHours);
    double getSalary();
    string getDetails();
protected:

private:
  double hoursWorked,rate;
};

#endif // HOURLYEMPLOYEE_H
