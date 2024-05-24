#include"Employee.h"
#include"SalariedEmployee.h"
#include"HourlyEmployee.h"
#include"CommissionEmployee.h"
#include"ManagerEmployee.h"
#include "Department.h"
#ifndef HRSYSTEM_H
#define HRSYSTEM_H
class HRSystem
{
public:
    HRSystem(int e_size);
    virtual ~HRSystem();
    void calcTotalPayroll();
    void addEmployee(Department *newDepart);
    void editEmployee(int id);
    void delEmployee(int id);
    void findEmployee(string key);
    void showAll();
    void SearchDepart(Department *newDepart);
    void delDepart(Department* newDepart);
protected:

private:
   int m_size;
   int e_counter,d_count;
  Employee** EmployeeList;
  Department* m_departs;
};

#endif // HRSYSTEM_H
