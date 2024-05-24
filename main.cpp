#include <iostream>
#include <stdlib.h>  // cls
#include <unistd.h>  // sleep
#include "HRSystem.h"
#include "Employee.h"
#include "Department.h"
using namespace std;

void printline(string s,bool line=true)
{
    cout<<s<<(line?"\n":"\t");
}

HRSystem hrsystem(100);

unsigned int depart_size=10;
unsigned int depart_count=0;
Department *Departs = new Department[depart_size];
void handle_department()
{
    int c=1;
    system("cls");
    system("Color 06");
    printline("\t  ## Handle Departments : ");
    printline("\t  ************************");
    printline("\t[1] Add New Department");
    printline("\t[2] Search for A Department");
    printline("\t[3] Delete A Department");
    printline("\t[0] Return to Main Menu");
    printline("Enter Selection : ",false);
    cin>>c;
    switch(c)
    {
    case 1:
        system("cls");
        printline("Add New Department ...");
        if(depart_count<=depart_size)
        {
            Departs[depart_count++].set_newDepart();
        }
        else
            printline("No More room for new department ! ");
        break;
    case 2:
    {
        system("cls");
        if(depart_count>0)
        {
            printline("\n\tPlease, Select A department to Search..");
            for(unsigned i=0 ; i<depart_count ; ++i)
            {
                cout<<i+1<<". "<<Departs[i].getdepartName()<<endl;
            }
            unsigned ch;
            cin>>ch;
            for( unsigned j=0 ; j<depart_count ; ++j)
            {
                if(ch==(j+1))
                {
                    Department *newDepart = Departs;
                    hrsystem.SearchDepart(newDepart+j);
                }
            }
        }
        else
            cout<<"\nThere are no Departments to search !\n";
        system("pause");
    }
    break;
    case 3:
    {
        system("cls");
        if(depart_count>0)
        {
            printline("\n\tPlease, Select A department to delete..");
            for(unsigned i=0 ; i<depart_count ; ++i)
            {
                cout<<i+1<<". "<<Departs[i].getdepartName()<<endl;
            }
            unsigned ch;
            cin>>ch;
            for( unsigned j=0 ; j<depart_count ; ++j)
            {
                if(ch==(j+1))
                {
                    Department *newDepart = Departs;
                    hrsystem.delDepart(newDepart+j);
                }
            }
        }
        else
            cout<<"\nThere are no Departments to Delete !\n";
        system("pause");
    }
    break;
    case 0:
        return;
    default:
        system("cls");
        printline("Invalid Selection, Try again !");

    }
}

void handle_Employee()
{

    int c=1;
    system("Color 02");
    printline("\t  ## HANDLE EMPLOYEES : ");
    printline("\t  *******************");
    printline("\t[1] Add New Employee");
    printline("\t[2] Edit An Employee");
    printline("\t[3] Delete An Employee");
    printline("\t[4] Search for An Employee");
    printline("\t[5] Print All Employees");
    printline("\t[6] Calculate Total Payroll");
    printline("\t[0] Return to Main Menu");
    printline("Enter Selection : ",false);
    cin>>c;
    switch(c)
    {
    case 1:
    {
        printline("\n\tPlease, Select A department first ..");
        for(unsigned i=0 ; i<depart_count ; ++i)
        {
            cout<<i+1<<". "<<Departs[i].getdepartName()<<endl;
        }
        unsigned ch;
        cin>>ch;
        for( unsigned j=0 ; j<depart_count ; ++j)
        {
            if(ch==(j+1))
            {
                Department *newDepart = Departs;
                hrsystem.addEmployee(newDepart+j);
            }
        }
    }
    break;
    case 2:
    {
        system("cls");
        int id;
        printline("Edit an Employee..");
        printline("Enter Id to Edit : ",false);
        cin>>id;
        hrsystem.editEmployee(id);
    }
    break;
    case 3:
    {
        system("cls");
        int id;
        printline("Delete an Employee..");
        printline("Enter Id to Delete : ",false);
        cin>>id;
        hrsystem.delEmployee(id);
    }
    break;
    case 4:
    {
        system("cls");
        string key;
        printline("Search for an Employee..");
        printline("Enter key(name / job Title) to Search : ",false);
        cin>>key;
        hrsystem.findEmployee(key);
    }
    break;
    case 5:
        system("cls");
        printline("Print All Employees ...");
        hrsystem.showAll();
        break;
    case 6:
        system("cls");
        hrsystem.calcTotalPayroll();
    case 0:
        return;
    default:
        system("cls");
        printline("Invalid Selection, Try again !");

    }
}
int main()
{
    system("Color B0");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t"
        <<" ===================================\n"
        <<"\t\t\t\t| WELCOME TO HR MANAGEMENT SYSTEM \03  |\n"
        <<"\t\t\t\t ===================================";
    sleep(1);
    int c=1;
    while(c!=0)
    {
        system("Color 03");
        system("cls");
        printline("\t Main Menu ");
        printline ("\t------------");
        printline("[1] HANDLE DEPARTMENTS");
        printline("[2] HANDLE EMPLOYEES");
        printline("[0] EXIT");
        printline("ENTER SELECTION",false);
        cin>>c;
        switch(c)
        {
        case 1:
            system("cls");
            handle_department();
            break;
        case 2:
            system("cls");
            handle_Employee();
            break;
        case 0:
            system("cls");
            printline("\n\tThanks \03");
            break;
        default:
            system("cls");
            printline("Invalid Selection, Try again !");
        }

    }
    return 0;
}
