#include<iostream>
using namespace std;

class employee
{
    private:
        int id;
        float sal;
        string dsg;

    public:
        employee()
        {
            this->id=00;
            this->sal=00;
            
        }

        employee(int id, float sal)
        {
            this->id=id;
            this->sal=sal;
        }

        virtual void accept() //late binding
        {
            cout<<"Enter Employee Details: "<<endl;
            cout<<"Enter employee id: ";
            cin>>this->id;
            cout<<"\nEnter salary: ";
            cin>>this->sal;

        }

        virtual void display()
        {
            cout<<"ID: "<<this->id;
            cout<<"Salary: "<<this->sal;
        }

        int get_id()
        {
            return this->id;
        }

        float get_sal()
        {
            return this->id;
        }

        string get_dsg()
        {
            return this->dsg;
        }

        void set_dsg(string s)
        {
            this->dsg=s;
        }

        void set_id(int i)
        {
            this->id=i;
        }

        void set_sal(float s)
        {
            this->sal=s;
        }

};


class manager:virtual public employee
{
    private:
    float bonus;

    public:
    manager():employee()
    {
        this->bonus=0;
        //set_dsg("Manager");
    }

    manager(int id, float sal,float bonus):employee(id, sal)
    {
        this->bonus=bonus;
        //set_dsg("Manager");
    }

    float get_bonus()
    {
        return this->bonus;
    }

    void set_bonus(float s)
    {
        this->bonus=s;
    }

    virtual void accept()
    {
        
        employee::accept();
        cout<<"\nEnter bonus: ";
        cin>>this->bonus;
    }

    virtual void display()
    {
        
        employee::display();
        cout<<"Bonus: "<<this->bonus<<endl;
    }

    protected:

    void accept_manager()
    {
        cout<<"Enter bonus ";
        cin>>this->bonus;
    }

    void display_manager()
    {
        cout<<"Bonus"<<this->bonus<<endl;
    }

};

class salesman:virtual public employee
{
    private:
    float comm;

    public:
    salesman():employee()
    {
        this->comm=0;
        //set_dsg("Salesman");
    }

    salesman(int id, float sal, float comm):employee(id, sal)
    {
        this->comm=comm;
        //set_dsg("Salesman");
    }

    salesman(float comm)
    {
        this->comm=comm;
    }


    float get_comm()
    {
        return this->comm;
    }

    void set_comm(float s)
    {
        this->comm=s;
    }

    virtual void accept()
    {
        
        employee::accept();
        cout<<"Enter Commision: ";
        cin>>this->comm;
    }

    virtual void display()
    {
        
        employee::display();
        cout<<"Commission: "<<this->comm<<endl;
    }

    protected:

    void accept_salesman()
    {
        cout<<"Enter commission for salesman: ";
        cin>>this->comm;
    }

    void display_salesman()
    {
        cout<<this->comm<<endl;
    }    

};

class sales_manager: public manager,public salesman
{
    public:
    sales_manager():manager(),employee() //
    {
        //set_dsg("Salesmanager");
    }

    sales_manager(int id, float sal, float bonus, float comm):manager(id, sal, bonus),salesman(comm)
    {
         //set_dsg("Salesmanager");  
    }

    void accept()
    {
        
        employee::accept();
        manager::accept_manager(); 
        salesman::accept_salesman();
    }

    void display()
    {
        
        employee::display();
        manager::display_manager();
        salesman::display_salesman();

    }
};

void count_dsg(employee *arr[],int index)
{
    int count_m=0;
    int count_s=0;
    int count_sm=0;

    for(int i=0;i<index;i++)
    {
        // if (arr[i]->get_dsg=="Manager")
        // {
        //     count_m++;
        // }

        // else if(arr[i]->get_dsg=="Salesman")
        // {
        //     count_s++;
        // }

        // else (arr[i]->get_dsg=="Salesmanager")
        // {
        //     count_sm++;
        // }

        if (typeid(*arr[i])==typeid(manager))
        {
            count_m++;
        }

        else if (typeid(*arr[i])==typeid(salesman))
        {
            count_s++;
        }

        else //last option i.e.(typeid(*arr[i])==typeid(sales_manager))
        {
            count_sm++;
        }
    
    }
    cout<<"Number of Employees: "<<index<<endl;
    cout<<"Number of managers: "<<count_m<<endl;
    cout<<"Number of salesmen: "<<count_s<<endl;
    cout<<"Number of salesmanagers: "<<count_sm<<endl;


}

void display_dsg(employee *arr[],int index)
{
            for (int i=0; i<index;i++)
            {
                if (typeid(*arr[i])==typeid(manager))
                {
                    cout<<"arr["<<i<<"] = Manager"<<endl;
                }
            }

            for (int i=0; i<index;i++)
            {
                 if (typeid(*arr[i])==typeid(salesman))
                
                {
                    cout<<"arr["<<i<<"] = Salesman"<<endl;
                }
            }
        

            for (int i=0; i<index;i++)
            {
                if (typeid(*arr[i])==typeid(sales_manager)) 
                
                {
                    cout<<"arr["<<i<<"] = Salesmanager"<<endl;
                }
            }
}


int menu()
{
    int choice;
    cout<<"----------------------------------------"<<endl;
    cout<<"Enter your choice: "<<endl;
    cout<<"0. EXIT "<<endl;
    cout<<"1. Accept Manager "<<endl;
    cout<<"2. Accept salesman "<<endl;
    cout<<"3. Accept salesmanager "<<endl;
    cout<<"4. Display respective designation"<<endl;
    cout<<"5. Display count of all employees with respective designation"<<endl;
    cin>>choice;
    cout<<"----------------------------------------"<<endl;
    return choice;
}

int main()
{
    int choice;
    employee *arr[6];
    int index=0;
    do
    {
        switch (choice)
        {
        case 1:
            if (index<6)
            {
            arr[index]= new manager();
            arr[index]->accept();
            arr[index]->display();
            index++;
            }
            else
            {
                cout<<"Array is full!!"<<endl;
            }
            break;

        case 2:
            if (index<6)
            {
            arr[index]= new salesman();
            arr[index]->accept();
            arr[index]->display();
            index++;
            }
            else
            {
                cout<<"Array is full!!"<<endl;
            }
            break;

        case 3:
            if (index<6)
            {
            arr[index]= new sales_manager();
            arr[index]->accept();
            arr[index]->display();
            index++;
            }
            else
            {
                cout<<"Array is full!!"<<endl;
            }
            break;

        case 4:
            // for (int i=0; i<index;i++)
            // {
            //     cout<<"Designation="<<". "<<arr[i]->get_dsg()<<endl;
            // }
            display_dsg(arr,6);
            break;

        case 5:
            count_dsg(arr,6);
            break;
        
        
        default:
            cout<<"Enter valid choice!"<<endl;
            break;
        }
    } while ((choice=menu())!=0);

    for (int i=0; i<index;i++)
    {
        delete arr[i];
    }
    


    return 0;
}