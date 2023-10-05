#include<iostream>
using namespace std;

class Date 
{
    private:
    int day;
    int month;
    int year;

    public:

    Date()
    {
        this->day=0;
        this->month=0;
        this->year=0;
    }

    Date(int d, int m, int y)
    {
        this->day=d;
        this->month=m;
        this->year=y;
    }

    void display()
    {
        cout<<"Date:"<<this->day<<"/"<<this->month<<"/"<<this->year<<endl;
    }
    
    void accept()
    {
        cout<<"Enter Date as dd/mm/yyyy:";
        cin>>this->day>>this->month>>this->year;
    }

    bool is_leap_year()
    {
        if((this->year%100)==0)
        {
            if ((this->year%400)==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if ((this->year%4)==0)
                {
                    return true;
                }
            else
                {
                    return false;
                }
                    
    }

    void isLeapYear()
    {
        if (is_leap_year())
        {
            cout<<"It's a leap year!"<<endl;
        }
        else
        {
            cout<<"It's not a leap year!"<<endl;
        }
    }

    int get_day()
    {
        return this->day;
    }

    int get_month()
    {
        return this->month;
    }

    int get_year()
    {
        return this->year;
    }

    void set_day(int d)
    {
        this->day=d;
    }
    
    void set_month(int m)
    {
        this->month=m;
    }

    void set_year(int y)
    {
        this->year=y;
    }

};

class Person
{
    private:
    string name;
    string addr;
    //Date dob;


    public:
    Date dob;


    Person()
    {
        this->name="";
        this->addr="";
    }

    Person(string name,string addr,int day, int month, int year):dob(day,month,year)
    {
        this->name=name;
        this->addr=addr;

    }

    void accept() //so that for emp obj; derived accept would be prioritised
    {
        cout<<"Enter the Details as: ";
        cout<<"Enter name: ";
        cin>>this->name;
        cout<<"Enter Address: ";
        cin>>this->addr;
        cout<<"For Date of birth:";
        this->dob.accept();
    }

    void display()
    {
        cout<<"Name: "<<this->name<<endl;
        cout<<"Address: "<<this->addr<<endl;
        cout<<"Birth ";
        this->dob.display();
    }

    string get_name()
    {
        return this->name;
    }

    string get_address()
    {
        return this->addr;
    }

    Date get_DateOfBirth()
    {
        return this->dob;
    }

    void set_name(string n)
    {
        this->name=n;
    }

    void set_address(string a)
    {
        this->addr=a;
    }

    void set_DateOfBirth(Date d)
    {
        this->dob=d;
    }

};

class Employee: public Person
{
    private:
    int id;
    float sal;
    string dept;
    // Date doj;

    public:
    Date doj;

    Employee()
    {
        this->id=0;
        this->sal=0;
        this->dept="";
    }
    
    Employee(int id,float sal,string dept,int day, int month, int year):doj(day,month,year)
    {
        this->id=id;
        this->sal=sal;
        this->dept=dept;
    }

    Employee(string name,string addr,int id,float sal,string dept, int day, int month, int year, int day1, int month1, int year1) : doj(day1, month1, year1), Person(name,addr,day, month, year)
    {
        this->id=id;
        this->sal=sal;
        this->dept=dept;
    }

    void accept()
    {
        cout<<"Enter Personal details of Employee: ";
        Person::accept();
        cout<<"Enter the Employee id:";
        cin>>this->id;
        cout<<"Enter the salary:";
        cin>>this->sal;
        cout<<"Enter the Department Name:";
        cin>>this->dept;
        cout<<"For Joining date:";
        this->doj.accept();
    }

    void display()
    {
        cout<<"Personal details of Employee: "<<endl;
        Person::display();
        cout<<"Employee id: "<<this->id<<endl;
        cout<<"Salary: "<<this->id<<endl;
        cout<<"Department name: "<<this->dept<<endl;
        cout<<"Joining ";
        this->doj.display();
    }

    
};

 int main()
 {
    Date d1;
    // d1.accept();
    // d1.display();
    // d1.isLeapYear();
    //cout<<d1.get_year()<<endl;
    //cout<<"------------------------------"<<endl;
    //Date d(21,9,1999);
    // d.is_leap_year();
    // d.set_day(30);
    // d.display();

    //Person p;
    // p.accept();
    // p.display();
    // p.get_DateOfBirth();
    // cout<<p.dob.get_day()<<endl;
    // p.dob.set_year(2000);
    // p.display();
    // cout<<"------------------------------"<<endl;
    //Person p1("Mugdha","Aurangabad",28,10,1999);
    // p1.display();
    // p1.get_DateOfBirth();
    // cout<<p1.dob.get_day()<<endl;
    // p1.dob.set_year(2000);
    // p1.display();


    Employee e;
    e.accept();
    e.display();

    // Employee e1("Mugdha","Aurangabad",1001,20000,"Analytics",28,10,1999,30,10,2022);
    // e1.display();

    

    
    return 0;
 }

 