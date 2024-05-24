#include <string.h>
#include <iostream>
using namespace std;
#ifndef DEPARTMENT_H
#define DEPARTMENT_H
class Department
{
public:
    Department();
    virtual ~Department();
    void Print();
    void set_newDepart();
    int getdepartID();
    string getdepartName();

protected:
private:
int departID;
string departName;
};

#endif // DEPARTMENT_H
