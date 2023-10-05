#include <iostream>
using namespace std;

class Time
{
private:
    int hr;
    int min;
    int sec;

public:
    Time()
    {
        this->hr = 0;
        this->min = 0;
        this->sec = 0;
    }

    Time(int h, int m, int s)
    {
        this->hr = h;
        this->min = m;
        this->sec = s;
    }

    int getHour()
    {
        return this->hr;
    }

    int getMinute()
    {
        return this->min;
    }

    int getSeconds()
    {
        return this->sec;
    }

    void acceptTime()
    {

        cout << "enter time Hr:Min:Sec=";
        cin >> this->hr >> this->min >> this->sec;
    }

    void printTime()
    {
        cout << "**************************************" << endl;
        cout << "Time:" << this->hr << ":" << this->min << ":" << this->sec << endl;
    }

    void setHour(int hr)
    {
        this->hr = hr;
    }

    void setMinute(int min)
    {
        this->min = min;
    }

    void setSeconds(int sec)
    {
        this->sec = sec;
    }
};

int main()
{
    // DMA
    Time **arr = new Time *[3]; // time type **arr storing address of time* array of pointers storing int type object's address

    for (int i = 0; i < 3; i++)
    {

        arr[i] = new Time;
    }

    for (int i = 0; i < 3; i++)
    {
        arr[i]->acceptTime(); // accepting values
    }

    for (int i = 0; i < 3; i++)
    {
        arr[i]->printTime(); // displaying values
    }
    cout << "**************************************" << endl;

    for (int i = 0; i < 3; i++)
    {

        delete arr[i]; // de-allocation
    }
    delete[] arr;
    return 0;
}