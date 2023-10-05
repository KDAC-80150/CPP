#include <iostream>
using namespace std;

class Products
{
private:
    int id;
    string title;
    float price;
    string type;

public:
    Products()
    {
        this->id = 0;
        this->title = "";
        this->price = 0;
        this->type = "";
    }

    Products(int id, string title, float price)
    {
        this->id = id;
        this->title = title;
        this->price = price;
    }

    void display()
    {
        cout << "Products type:" << this->type << endl;
    }

    virtual void accept()
    {
        cout << "id:";
        cin >> this->id;
        cout << "Enter title:";
        cin >> this->title;
        cout << "Enter price";
        cin >> this->price;
    }

    int get_id()
    {
        return this->id;
    }

    string get_title()
    {
        return this->title;
    }

    float get_price()
    {
        return this->price;
    }

    void set_type(string s)
    {
        this->type = s;
    }

    friend float calculate_bill(Products *arr[3]);
};

class Books : public Products
{
private:
    string author;

public:
    Books()
    {
        this->set_type("B");
        this->author = "";
    }

    Books(string author, string type)
    {
        this->author = author;
    }

    void accept()
    {
        cout << "Enter Book ";
        Products::accept();
        cout << "Enter Author name:";
        cin >> this->author;
    }
};

class Tape : public Products
{
private:
    string artist;

public:
    Tape()
    {
        this->set_type("T");
        this->artist = "";
    }

    Tape(string artist, string type)
    {
        this->artist = artist;
    }

    void accept()
    {

        cout << "Enter Tape ";
        Products::accept();
        cout << "Enter Artist name:";
        cin >> this->artist;
    }
};

int menu()
{
    int choice;
    cout << "---------------------------------------" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Buy a Book" << endl;
    cout << "2. Buy a Tape" << endl;
    cout << "3. View Purchased products:" << endl;
    cout << "4. View computed bill(inc discount):" << endl;
    cin >> choice;
    cout << "---------------------------------------" << endl;
    return choice;
}

float calculate_bill(Products *arr[3])
{
    float computed_bill = 0;
    for (int i = 0; i < 3; i++)
    {
        if ((arr[i]->type) == "B")
        {
            // float p;
            // p=arr[i]->price;
            computed_bill += arr[i]->price * 0.9;
        }

        if ((arr[i]->type) == "T")
        {
            // float p1;
            // p1=arr[i]->price;
            computed_bill += 0.95 * arr[i]->price;
        }
    }
    return computed_bill;
}

int main()
{
    int choice;
    Products *arr[3];
    int index = 0;
    do
    {
        switch (choice)
        {
        case 1:
            if (index < 3)
            {
                arr[index] = new Books();
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "Maximum products purchased already!" << endl;
            }
            break;

        case 2:
            if (index < 3)
            {
                arr[index] = new Tape();
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "Maximum products purchased already!" << endl;
            }
            break;

            // case 3:

            //     break;

        case 4:
            float bill;
            bill = calculate_bill(arr);
            cout << bill << endl;
            break;

        default:
            break;
        }
    } while ((choice = menu()) != 0);

    for (int i = 0; i < index; i++)
    {
        delete arr[i];
    }

    return 0;
}