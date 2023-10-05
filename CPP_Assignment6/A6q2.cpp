#include <iostream>
using namespace std;

class employee
{
private:
    int id;
    float sal;

public:
    employee()
    {
        this->id = 00;
        this->sal = 00;
    }

    employee(int id, float sal)
    {
        this->id = id;
        this->sal = sal;
    }

    void accept()
    {
        cout << "Enter Employee Details: " << endl;
        cout << "Enter employee id: ";
        cin >> this->id;
        cout << "\nEnter salary: ";
        cin >> this->sal;
    }

    void display()
    {
        cout << "ID: " << this->id << endl;
        cout << "Salary: " << this->sal << endl;
    }

    int get_id()
    {
        return this->id;
    }

    float get_sal()
    {
        return this->id;
    }

    void set_id(int i)
    {
        this->id = i;
    }

    void set_sal(float s)
    {
        this->sal = s;
    }
};

class manager : virtual public employee
{
private:
    float bonus;

public:
    manager() : employee()
    {
        this->bonus = 0;
    }

    manager(int id, float sal, float bonus) : employee(id, sal)
    {
        this->bonus = bonus;
    }

    float get_bonus()
    {
        return this->bonus;
    }

    void set_bonus(float s)
    {
        this->bonus = s;
    }

    void accept()
    {

        employee::accept();
        cout << "\nEnter bonus: ";
        cin >> this->bonus;
    }

    void display()
    {

        employee::display();
        cout << "Bonus: " << this->bonus << endl;
    }

protected:
    void accept_manager()
    {
        cout << "Enter bonus  ";
        cin >> this->bonus;
    }

    void display_manager()
    {
        cout << "Bonus: " << this->bonus << endl;
    }
};

class salesman : virtual public employee
{
private:
    float comm;

public:
    salesman() : employee()
    {
        this->comm = 0;
    }

    salesman(int id, float sal, float comm) : employee(id, sal)
    {
        this->comm = comm;
    }

    salesman(float comm) // copy constructor
    {
        this->comm = comm;
    }

    float get_comm()
    {
        return this->comm;
    }

    void set_comm(float s)
    {
        this->comm = s;
    }

    void accept()
    {

        employee::accept();
        cout << "Enter Commision: ";
        cin >> this->comm;
    }

    void display()
    {

        employee::display();
        cout << "Commission:" << this->comm << endl;
    }

protected:
    void accept_salesman()
    {
        cout << "Enter commission for salesman: ";
        cin >> this->comm;
    }

    void display_salesman()
    {
        cout << "Commission:" << this->comm << endl;
    }
};

class sales_manager : public manager, public salesman
{
public:
    sales_manager() : manager(), salesman() //
    {
    }

    sales_manager(int id, float sal, float bonus, float comm) : manager(id, sal, bonus), salesman(comm)
    {
    }

    void accept()
    {

        employee::accept();
        manager::accept_manager(); /* so that the accept function from
        employee wouldn't be called twice */
        salesman::accept_salesman();
    }

    void display()
    {

        employee::display();
        manager::display_manager();
        salesman::display_salesman();
    }
};

int main()
{
    // manager m;
    // m.accept();
    // m.display();
    // cout<<"----------------------------------------"<<endl;
    // manager mm(1001,20000,5000);
    // mm.display();
    // cout<<"----------------------------------------"<<endl;

    // salesman s(1002,30000,5000);
    // s.display();
    // cout<<"----------------------------------------"<<endl;

    sales_manager sm1;
    sm1.accept();
    sm1.display();
    cout << "----------------------------------------" << endl;

    sales_manager sm(2002, 50000, 7000, 5000);
    sm.display();
    return 0;
}