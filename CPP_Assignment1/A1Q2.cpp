// Q2. Write a menu driven program for Date in a CPP language using structure and also using class.
// Date is having data members day, month, year. Implement the following functions.
// void initDate();
// void printDateOnConsole();
// void acceptDateFromConsole();
// bool isLeapYear();

#include<iostream>
using namespace std;

struct date
{
    int day;
    int month;
    int year;
    bool leap;
};

class Date
{

    int day = 06;
    int month = 07;
    int year = 2000;

public:

    void initDate()
    {
        day = 15;
        month = 8;
        year = 2020;
        cout<<"Date Initialized\n\n";
    }

    void printDate( )
    {
        cout<<"DATE : "<<day<<"/"<<month<<"/"<<year;
    }

    void acceptDate( )
    {
        cout<<"Please enter Day of the Date :\n";
        cin>>day;
        cout<<"Please enter Day of the Date :\n";
        cin>>month;
        cout<<"Please enter Day of the Date :\n";
        cin>>year;
    }

    bool isLeapYear( )
    {
        if (year % 4 !=0 )
        {
        cout<<"%d is not a leap Year\n",year;
        }
        else
        {
            cout<<"%d is a leap Year\n",year;  
        }
        return 1;
    }
};

int main()
{

        Date d;
        int choice;
        //int initDate();

    do {
        cout<< "\nMenu:\n";
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
                d.isLeapYear();
            }

            case 5: 
            {
            return 0;
            }
            
            default:
                cout<<"Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);
}