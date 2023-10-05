#include <iostream>
using namespace std;
// composition: employee has a date, person has a date
// aggregation: person is a employee
class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        // cout<<"inside dctor"<<endl;
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }

    Date(int d, int m, int y)
    {
        // cout<<"inside dctor"<<endl;
        this->day = d;
        this->month = m;
        this->year = y;
    }

    void acceptDate()
    {
        cout << "Enter Date as DD/MM/YYYY:";
        cin >> this->day >> this->month >> this->year;
    }

    void displayDate()
    {
        cout << "Date:" << this->day << "/" << this->month << "/" << this->year << endl;
    }

    int getDay()
    {
        return this->day;
    }

    // int getDay()
    // {
    //     int d;
    //     d= this->day;
    //     cout<<d<<endl;
    // }

    int getMonth()
    {
        return this->month;
    }

    int getYear()
    {
        return this->year;
    }

    void setDay(int day)
    {
        this->day = day;
    }

    void setMonth(int month)
    {
        this->month = month;
    }

    void setYear(int year)
    {
        this->year = year;
    }
};

class Person
{
private:
    string name;
    string addr;
    // Date dob;

public:
    Date dob;

    Person()
    {
        // cout<<"inside pctor"<<endl;
        this->name = "";
        this->addr = "";
    }

    Person(string name, string addr, int day, int month, int year) : dob(day, month, year)
    {
        // cout<<"inside pctor"<<endl;
        this->name = name;
        this->addr = addr;
    }

    void acceptPerson()
    {
        cout << "Enter the name:";
        cin >> this->name;
        cout << "Enter the address:";
        cin >> this->addr;
        cout << "Enter the Date of Birth:";
        dob.acceptDate();
    }

    void displayPerson()
    {
        cout << "Name:" << this->name << endl;
        cout << "Address:" << this->addr << endl;
        cout << "Birth ";
        dob.displayDate();
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setAddress(string addr)
    {
        this->addr = addr;
    }

    void setDOB(Date dob)
    {
        this->dob = dob;
    }

    string getName()
    {
        return this->name;
    }

    string getAddress()
    {
        return this->name;
    }

    Date getDOB()
    {
        return this->dob;
    }
};

class Employee
{
private:
    int empid;
    double sal;
    string dept;
    // Date doj;

public:
    Date doj;
    Employee()
    {
        // cout<<"inside ector"<<endl;
        this->empid = 1;
        this->sal = 1000;
        this->dept = "Testing";
    }

    Employee(int empid, double sal, string dept, int day, int month, int year) : doj(day, month, year)
    {
        // cout<<"inside ector"<<endl;
        this->empid = empid;
        this->sal = sal;
        this->dept = dept;
    }

    void acceptEmployee()
    {
        cout << "Enter the empid:";
        cin >> this->empid;
        cout << "Enter the salary:";
        cin >> this->sal;
        cout << "Enter the department name:";
        cin >> this->dept;
        cout << "Enter the Date of joining:";
        doj.acceptDate();
    }

    void displayEmployee()
    {
        cout << "Employee ID:" << this->empid << endl;
        cout << "Salary:" << this->sal << endl;
        cout << "Department:" << this->dept << endl;
        cout << "Joining ";
        doj.displayDate();
    }

    Date getDOJ()
    {
        return this->doj;
    }

    int getEmpID()
    {
        return this->empid;
    }

    double getSalary()
    {
        return this->sal;
    }

    string getDepartment()
    {
        return this->dept;
    }

    void setEmpID(int empid)
    {
        this->empid = empid;
    }

    void setSalary(double sal)
    {
        this->sal = sal;
    }

    void setDepartment(string dept)
    {
        this->dept = dept;
    }

    void setDOJ(Date doj)
    {
        this->doj = doj;
    }
};

int main()
{

    // Date d1;
    //  d1.acceptDate();
    //  d1.displayDate();
    //  Date d2(2,11,1996);
    //  d2.displayDate();

    // Person p1;
    // p1.acceptPerson();
    // p1.displayPerson();
    // p2.displayPerson();
    Person p2;
    Date db = p2.getDOB();
    db.displayDate();

    int d = p2.dob.getDay();
    cout << d << endl;
    // p2.setDOB(12,12,2012);
    // p2.getDOB();

    // Employee e1;
    Employee e2;
    // e1.acceptEmployee();
    // e1.displayEmployee();
    e2.displayEmployee();
    // dj.displayDate();

    return 0;
}