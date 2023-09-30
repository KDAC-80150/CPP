// Q2. Write a menu driven program for Date in a CPP language using structure and also using class.
// Date is having data members day, month, year. Implement the following functions.
// void initDate();
// void printDateOnConsole();
// void acceptDateFromConsole();
// bool isLeapYear();

#include<iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
    bool status;

public:

    void initDate()
    {
        this->day = 15;
        this->month = 8;
        this->year = 2020;
        cout<<"Date Initialized\n\n";
    }

    void printDate( )
    {
        cout<<"DATE : "<<this->day<<"/"<<this->month<<"/"<<this->year;
    }

    void acceptDate( )
    {
        cout<<"Please enter Day of the Date :\n";
        cin>>this->day;
        cout<<"Please enter Day of the Date :\n";
        cin>>this->month;
        cout<<"Please enter Day of the Date :\n";
        cin>>this->year;
    }

    bool isLeapYear( )
    {
        bool status;
        if (year % 100 == 0 )
        {
            if (year % 400 == 0 )
                {
                    status=1;
                }
                else 
                {
                    status= 0;
                }
        }
        else    
        {
            if (this->year % 4 == 0)
            {
                status = 1;
            }
            else
            {
                status = 0;
            }
        }
        return status;
        }
        
};

int main()
{

        struct Date d;
        int choice,year;
        bool status;
        d.initDate();

    do {
        cout<< "\n\nMenu:\n";
        cout<< "1. Initiate Date\n";
        cout<< "2. Display Date\n";
        cout<< "3. Accept Date\n";
        cout<< "4. Is leap\n";
        cout<< "5. Exit\n";
        cout<< "Enter your choice: \n\n";
        scanf( "%d",&choice);

        switch (choice) 
        {
            case 1: 
            {
                d.initDate();
                break;
            }
            case 2: 
            {
                d.printDate();
                break;
            }

            case 3: 
            {
                d.acceptDate();
                break;
            }

            case 4:
            {
                if(d.isLeapYear())
                {
                    cout<<" This is a leap year"<<endl;
                }
                else
                {
                    cout<<"This is not a leap year"<<endl;
                }
                break;
            }

            case 5: 
            break;
    
    
            
            default:
                cout<<"Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);
}