#include <iostream>
using namespace std;

class TollBooth
{
private:
    unsigned int totalCars;
    double totalCash;

public:
    TollBooth()
    {
        this->totalCars = 0;
        this->totalCash = 0.0;
    }

    void payingCar()
    {
        totalCars++;
        totalCash += 0.50;
    }

    void nopayCar()
    {
        totalCars++;
    }

    void printOnConsole() const
    {
        cout << "**************************" << endl;
        cout << "Total Cars Passed: " << totalCars << endl;
        cout << "Total Cash Collected: $" << totalCash << endl;
        cout << "Paying Cars: " << (totalCars - totalCash / 0.50) << endl;
        cout << "Non-Paying Cars: " << (totalCash / 0.50) << endl;
        cout << "**************************" << endl;
    }
};

int menu()
{
    int choice;
    cout << "\nMenu:\n";
    cout << "1. Car Paid Toll\n";
    cout << "2. Car Didn't Pay Toll\n";
    cout << "3. Display Totals\n";
    cout << "4. Exit\n";
    cout << "Enter Your Choice: ";
    cin >> choice;
    return choice;
}

int main()
{
    TollBooth booth;

    int choice;
    while ((choice = menu()) != 4)
    {
        switch (choice)
        {
        case 1:
            booth.payingCar();
            cout << "Car paid the toll." << endl;
            break;
        case 2:
            booth.nopayCar();
            cout << "Car didn't pay the toll." << endl;
            break;
        case 3:
            booth.printOnConsole();
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }

    cout << "Thank you for using the tollbooth program." << endl;
    return 0;
}
