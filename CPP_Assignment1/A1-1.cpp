// Write a menu driven program for Date in a C. Declare a structure Date having data members
// day, month, year. Implement the following functions.
// void initDate(struct Date* ptrDate);
// void printDateOnConsole(struct Date* ptrDate);
// void acceptDateFromConsole(struct Date* ptrDate);




#include<stdio.h>
// #include<iostream>

struct Date
{
    int day;
    int month;
    int year;
};

    void initDate(struct Date* ptrdate)
    {
        ptrdate->day = 06;
        ptrdate->month = 07;
        ptrdate->year = 2000;
    }

    void printDate(struct Date* ptrdate)
    {
        printf("DATE : %d/%d/%d",ptrdate->day,ptrdate->month,ptrdate->year);
    }

    void acceptDate(struct Date* ptrdate)
    {
        printf("Please enter Day of the Date :\n");
        scanf("%d",&ptrdate->day);
        printf("Please enter Day of the Date :\n");
        scanf("%d",&ptrdate->month);
        printf("Please enter Day of the Date :\n");
        scanf("%d",&ptrdate->year);
    }


int main()
{
        struct Date d;
        int choice;
    do {
        printf( "\nMenu:\n" );
        printf( "1. Initiate Date\n" );
        printf( "2. Display Date\n" );
        printf( "3. Accept Date\n" );
        printf( "4. Exit\n" );
        printf( "Enter your choice: \n");
        scanf( "%d",&choice);

        switch (choice) {
            case 1: {
                initDate(&d);
                break;
            }
            case 2: {
                printDate(&d);
                break;
            }
            case 3: {
                acceptDate(&d);
                break;
            }
            case 4: {
                
                return 0;
            }
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

}