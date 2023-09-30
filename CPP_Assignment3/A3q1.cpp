#include <iostream>
using namespace std;

class box
{
private:
    double lenght;
    double width;
    double height;

public:
    box()
    {
        lenght = 1;
        width = 1;
        height = 1;
    }

    box(double lenght, double width, double height)
    {
        this->lenght = lenght;
        this->width = width;
        this->height = height;
    }

    void insert()
    {
        cout << "**********************************" << endl;
        cout << "Enter the Length of the Box = ";
        cin >> lenght;
        cout << "Enter the Width of the Box = ";
        cin >> width;
        cout << "Enter the Height of the Box = ";
        cin >> height;
        cout << "**********************************" << endl;
    }

    void display()
    {
        cout << "**********************************" << endl;
        cout << "Length of the Box = " << this->lenght << endl;
        cout << "Width of the Box = " << this->width << endl;
        cout << "Length of the Box = " << this->height << endl;
    }

    double calculate()
    {
        return this->lenght * this->width * this->height;
    }
};

int main()
{
    int choice;
    double lenght, width, height;
    box b1(lenght, width, height);
    do
    {
        cout << "**********************************" << endl;
        cout << "\nMenu:" << endl;
        cout << "1. Inset the values of the box " << endl;
        cout << "2. Calculate the Volume " << endl;
        cout << "3. Display the data of the box " << endl;
        cout << "4. Exit from the menu " << endl;

        cout << "Enter the Choice " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:

            // cout << "**********************************" << endl;
            // cout << "Enter the Length of the Box = ";
            // cin >> lenght;
            // cout << "Enter the Width of the Box = ";
            // cin >> width;
            // cout << "Enter the Height of the Box = ";
            // cin >> height;
            // cout << "**********************************" << endl;
            // box b1(lenght, width, height);
            
            b1.insert();
            cout << "Box created." << endl;
            break;
        case 2:
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