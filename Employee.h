#include <string.h>
#include <iostream>
#include "Benefit.h"
#include "Department.h"
#include "HealthBenefit.h"
#include "DentalBenefit.h"
using namespace std;
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
public:
    Employee();
    virtual ~Employee();
    virtual string getDetails();
    virtual double getSalary()=0;
    double calculatePay();
    virtual void ReadInput();
    int getId();
    bool getJobtitle(string key);
    bool getName(string key);
    void getBenefitList();
    void setDepartment(Department * newDepart);
    bool getDepart(Department * newDepart);
protected:
string name,phone,email,jobTitle;
int id;
private:
int b_count,benefit_size;
Benefit** benefitList;
Department* m_depart;
};

#endif // EMPLOYEE_H
