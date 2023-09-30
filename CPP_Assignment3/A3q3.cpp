#include <iostream>
using namespace std;

class cylinder
{
private:
    double radius;
    double height;

public:
    cylinder()
    {
        radius = 1;
        height = 1;
    }

    cylinder(double radius, double height)
    {
        this->radius = radius;
        this->height = height;
    }

    void insert()
    {
        cout << "**********************************" << endl;
        cout << "Enter the Radius of the Cylinder = ";
        cin >> radius;
        cout << "Enter the Height of the Box = ";
        cin >> height;
        cout << "**********************************" << endl;
    }

    void display()
    {
        cout << "**********************************" << endl;
        cout << "Radius of the Box = " << this->radius << endl;
        cout << "Height of the Box = " << this->height << endl;
    }

    double calculate()
    {
        return 3.14 * this->radius * this->height;
    }
};

int main()
{
    int choice;
    double radius, height;
    cylinder b1(radius, height);
    do
    {
        cout << "**********************************" << endl;
        cout << "\nMenu:" << endl;
        cout << "1. Inset the values of the cylinder " << endl;
        cout << "2. Calculate the Volume " << endl;
        cout << "3. Display the data of the box " << endl;
        cout << "4. Exit from the menu " << endl;

        cout << "Enter the Choice " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            b1.insert();
            cout << "Box created." << endl;
            break;
        case 2:
            cout << "**********************************" << endl;
            cout << "Volume of the Box: " << b1.calculate() << " cubic units" << endl;
            break;
        case 3:
            b1.display();
            break;
        case 4:
            cout << "Exiting program" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again" << endl;
        }
    } while (choice != 4);

    return 0;
}