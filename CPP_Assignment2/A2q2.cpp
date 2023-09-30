#include <iostream>
using namespace std;

class address
{
private:
    string building;
    string street;
    string city;
    int pin;

public:
    address()
    {
        this->street = "street";
        this->city = "city";
        this->building = "building";
        this->pin = 000000;
    }

    address(string building, string street, string city, int pin)
    {
        this->building = building;
        this->street = street;
        this->city = city;
        this->pin = pin;
    }

    string get_building()
    {
        return building;
    }
    string get_street()
    {
        return street;
    }
    string get_city()
    {
        return city;
    }
    int get_pin()
    {
        return pin;
    }
    void set_building()
    {
        this->building = building;
    }
    void set_street()
    {
        this->street = street;
    }
    void set_city()
    {
        this->city = city;
    }
    void set_pin()
    {
        this->pin = pin;
    }
    void accept()
    {
        cout << "Enter the building" << endl;
        cin >> this->building;
        cout << "Enter the Street" << endl;
        cin >> this->street;
        cout << "Enter the city" << endl;
        cin >> this->city;
        cout << "Enter the pin" << endl;
        cin >> this->pin;
    }
    void display()
    {
        cout << "Building = " << this->building << endl;
        cout << "Street = " << this->street << endl;
        cout << "City = " << this->city << endl;
        cout << "Pin = " << this->pin << endl;
    }
};

int main()
{
    address addr;
    addr.accept();
    addr.display();
    addr.get_building();
    addr.get_city();
    addr.get_pin();
    addr.set_pin();
    addr.display();

    address a1("abc", "def", "pqr", 003456);
    address a2("q", "w", "e", 456);

    a1.display();
    a2.display();
    return 0;
}