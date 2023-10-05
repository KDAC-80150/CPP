#include <iostream>
using namespace std;

class student
{
private:
    string name;
    string gender;
    int rollno;
    float marks[3];
    float percent;

public:
    void accept()
    {
        cout << "Enter the name:" << endl;
        cin >> this->name;
        cout << "Enter the gender:" << endl;
        cin >> this->gender;
        cout << "Enter the rollno:" << endl;
        cin >> this->rollno;
        cout << "Enter the marks of three subjects: " << endl;
        cin >> marks[0] >> marks[1] >> marks[2];
    }

    void print()
    {
        cout << "**********************************" << endl;
        cout << "Name : " << this->name << endl;
        cout << "Gender : " << this->gender << endl;
        cout << "Rollno : " << this->rollno << endl;
        cout << "Marks sub1 : " << this->marks[0] << endl;
        cout << "Marks sub2 : " << this->marks[1] << endl;
        cout << "Marks sub3 : " << this->marks[2] << endl;
        calpercent();
        cout << "Percentage : " << this->percent << endl;
    }

    void calpercent()
    {
        this->percent = (marks[0] + marks[1] + marks[2]) / 3;
    }
    friend int search(student **arr, int number, int rollno);
    friend void sort(student **arr, int number);
};

int search(student **arr, int number, int rollno)
{
    int x, y;
    for (int i = 0; i < x; i++)
    {
        if (rollno == arr[i]->rollno)
        {
            return i;
            arr[i]->print();
        }
        else
        {
            return -1;
        }
    }
}

void sort(student **arr, int number)
{
    int sel_pos, pos;
    student *temp;
    for (sel_pos = 0; sel_pos < number - 1; sel_pos++)
    {
        for (pos = sel_pos + 1; pos < number; pos++)
        {
            if (arr[sel_pos]->rollno > arr[pos]->rollno)
            {
                temp = arr[sel_pos];
                arr[sel_pos] = arr[pos];
                arr[pos] = temp;
            }
        }
    }
}

int main()
{
    int x;
    cout << "Enter the no of students!" << endl;
    cin >> x;
    student **arr = new student *[x];

    for (int i = 0; i < x; i++)
    {
        arr[i] = new student;
        arr[i]->accept();
    }

    for (int i = 0; i < x; i++)
    {
        arr[i]->print();
    }

    sort(arr, x);

    for (int i = 0; i < x; i++)
    {
        arr[i]->print();
    }

    return 0;
}
