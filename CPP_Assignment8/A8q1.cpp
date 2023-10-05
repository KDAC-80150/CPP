#include <iostream>

using namespace std;

class Distance
{
private:
    int feet;
    int inches;

public:
    // Parameterless constructor
    Distance() : feet(1), inches(1)
    {
    }
    // Paramaterized Constructor
    Distance(int feet, int inches)
    {
        this->feet = feet;
        this->inches = inches;
    }

    void display()
    {
        cout << "Feet:" << this->feet << ",inches:" << this->inches << endl;
    }

    //Arithmetic + operator overloaded
    Distance operator+(Distance d1)
    {
        Distance result;
        result.feet = d1.feet + this->feet;
        result.inches = this->inches + d1.inches;
        return result;
    }

    //post incerement operator overloaded
    void operator++(int)
    {
        this->feet++;
    }
    friend bool operator==(Distance,Distance);
    friend void operator--(Distance &d1,int);
    friend void operator<<(ostream &out,Distance &d);
    friend void operator>>(istream &in,Distance &d);
};

//Overloading insertion operator
void operator<<(ostream &out,Distance &d)
{
    out<< "Feet :"<<d.feet<<",inches:"<<d.inches<<endl;
}

//Overloading extraction operator
void operator>>(istream &in,Distance &d)
{
    cout<<"Enter feet:";
    in>>d.feet;
    cout<<"Enter inches:";
    in>>d.inches;
}

//Post decrement opearator overloaded
void operator--(Distance &d1,int)
{
    d1.feet--;
}

//Assignment(==) operator overloade
bool operator==(Distance d1, Distance d2)
{
    if(d1.feet== d2.feet && d1.inches==d2.inches)
        return true;
    return false;
}

int main()
{
    Distance d1(2, 4);
    Distance d2(2, 4);
     Distance d3 = d1 + d2;
    d1.display();
    d2.display();
    d3.display();
    if(d1==d2)
        cout<<"d1 is equal to d2"<<endl;
    else 
        cout<<"d1 is not equal to d2"<<endl;
    d1++;
    d1++;
    d1++;
    d1.display();
    d1--;
    d1.display();
    d1--;
    d1.display();

    cin>>d1;
    cout<<d1;
}


