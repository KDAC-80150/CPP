// Q3. Write a menu driven program for Student in CPP language. Create a class student with data
// members roll no, name and marks. Implement the following functions
// void initStudent();
// void printStudentOnConsole();
// void acceptStudentFromConsole();

#include<iostream>
using namespace std;
class student
{
    int roll;
    string name;
    int marks;
public:
    void initStudent()
    {
        roll = 0;
        name = "STUDENT";
        marks = 00;
        cout<<"Data Initialized\n\n"; 
    }
    void printStudent()
    {
        cout<<"\nRoll no of Student :\n"<<roll;
        cout<<"\nName of Student :\n"<<name;
        cout<<"\nMarks of Student :\n"<<marks;
    }
    void acceptStudent()
    {
        cout<<"Enter Roll no of Student :\n";
        cin>>roll;
        cout<<"Enter Name of Student :\n";
        cin>>name;
        cout<<"Enter Marks of Student :\n";
        cin>>marks;
    }
};

int main()
{
    student s;
    int choice;

    do
    {
        cout<< "\n\nMenu:\n";
        cout<< "1. Initiate data\n";
        cout<< "2. Display Student Data\n";
        cout<< "3. Accept Student Data\n";
        cout<< "4. Exit\n";
        cout<< "Enter your choice: \n\n";
        scanf( "%d",&choice);

        switch (choice)
        {
        case 1:
        {
            s.initStudent();
            break;
        }
        case 2:
        {
            s.printStudent();
            break;
        }
        case 3:
        {
            s.acceptStudent();
            break;
        }
        case 4:
        {
            return 0;
            break;
        }
        default:
            cout<<"Invalid choice. Please try again.\n";
            break;
        }
    } while (choice!= 5 );
    

}