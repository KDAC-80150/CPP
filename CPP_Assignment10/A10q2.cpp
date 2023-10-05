#include <iostream>
#include <vector>
using namespace std;

enum EAccount_type
{
    SAVING,
    CURRENT,
    DMAT,
};

enum ESubmenu
{
    BACK,
    DEPOSIT,
    WITHDRAW,
    CHECK_BALANCE,
};

enum EMainmenu
{
    EXIT,
    ACCEPT_USER,
    DISPLAY_USER,
    ENTER_SUB_MENU
};

// class to handle insufficient funds in account
class Insufficient_fundsException
{
private:
    int accid;
    double curr_balance;
    double withdraw_amount;

public:
    Insufficient_fundsException(int accid, double curr_balance, double withdraw_amount)
    {
        this->accid = accid;
        this->curr_balance = curr_balance;
        this->withdraw_amount = withdraw_amount;
    }

    void display()
    {
        cout << "--------------------------------------" << endl;
        cout << "INSUFFICIENT FUNDS EXCEPTION" << endl;
        cout << "Account id:" << this->accid << endl;
        cout << "Amount available:" << this->curr_balance << endl;
        cout << "Cannot withdraw amount:" << withdraw_amount << endl;
        cout << "--------------------------------------" << endl;
    }
};

class Account
{
private:
    int id;
    double balance;
    EAccount_type account_type;

public:
    // Parameterless constructor
    Account() : id(0), balance(0.0), account_type()
    {
    }
    // paramaterized constructor
    Account(int id, int account_type)
    {
        this->id = id;
        this->account_type = (EAccount_type)account_type;
    }

    void accept()
    {
        int choice;
        try
        {
            cout << "Enter id:";
            cin >> this->id;
            if (isdigit(id) == 0)
                throw 1;
        }
        catch (int)
        {
            cout << "Enter valid numeric id" << endl;
        }

        try
        {
            cout << "Select Accoun type 1.SAVING 2.CURRENT 3.DMAT" << endl;
            cin >> choice;
            if (choice < 1 && choice > 3)
                throw 1;
        }
        catch (int)
        {
            cout << "Enter valid numeric id" << endl;
        }

        // Switch case to set account type according to user
        switch (choice)
        {
        case 1:
            setAccountType(SAVING);
            break;
        case 2:
            setAccountType(CURRENT);
            break;
        case 3:
            setAccountType(DMAT);
            break;
        }
    }

    // Display function
    void display()
    {
        cout << "ID:" << this->id << endl;
        cout << "Balance:" << this->balance << endl;
        cout << "Account type:" << getAccountType() << endl;
    }

    // set Account
    void setAccountType(EAccount_type type)
    {
        this->account_type = type;
    }

    // Get accounttype
    string getAccountType()
    {
        switch (account_type)
        {
        case SAVING:
            return "Saving Account";
        case CURRENT:
            return "Current Account";
        case DMAT:
            return "DMAT Account";
        default:
            return "Unknown Account Type";
        }
    }

    // getters and setters for Id
    void setId(int id) { this->id = id; }
    int getId() { return this->id; }

    // getters for balance
    double getBalance() { return this->balance; }

    // deposit function
    void deposit(double amount)
    {
        this->balance += amount;
    }

    // withdraw function
    void withdraw(double amount)
    {
        if (amount > balance)
            throw Insufficient_fundsException(this->id, balance, amount);
        this->balance -= amount;
    }
};

EMainmenu mainMenu()
{
    int choice;
    cout << "---Welcome to ATM---" << endl;
    cout << "0.EXIT" << endl;
    cout << "1.Enter user detials" << endl;
    cout << "2.Display All users" << endl;
    cout << "3.Enter Submenu" << endl;
    cout << "Enter above choice!" << endl;
    cout << "---------------------" << endl;
    cin >> choice;
    cout << "---------------------" << endl;
    return EMainmenu(choice);
}

ESubmenu subMenu()
{
    int choice;
    cout << "---------------------" << endl;
    cout << "0.BACK" << endl;
    cout << "1.DEPOSIT" << endl;
    cout << "2.WITHDRAW" << endl;
    cout << "3.CHECK BALANCE" << endl;
    cout << "Enter above choice!" << endl;
    cout << "---------------------" << endl;
    cin >> choice;
    cout << "---------------------" << endl;
    return ESubmenu(choice);
}

int main()
{
    ESubmenu eChoice;
    EMainmenu eMChoice;
    int accId;
    double amount = 0;
    vector<Account *> accountvector;
    // menu to enter user details
    while ((eMChoice = mainMenu()) != EXIT)
    {
        switch (eMChoice)
        {
        case ACCEPT_USER:
        {
            int id, acc_type;
            try
            {
                cout << "Enter id:";
                cin >> id;
                cout << "Select Accoun type 1.SAVING 2.CURRENT 3.DMAT" << endl;
                cin >> acc_type;
                if (acc_type < 1 || acc_type > 3)
                    throw "Enter valid choice from above";
                accountvector.push_back(new Account(id, acc_type));
            }
            catch (char const *error)
            {
                cout << "Error:" << error << endl;
            }
        }
        break;
        case DISPLAY_USER:
        {
            int index = accountvector.size();
            for (int i = 0; i < index; i++)
            {
                cout << "**********************" << endl;
                accountvector.at(i)->display();
                cout << "**********************" << endl;
            }
        }
        break;
        // Submenu case
        case ENTER_SUB_MENU:
        {
            /*Menu driven code for deposit,withdraw,check balance*/
            while ((eChoice = subMenu()) != BACK)
            {
                switch (eChoice)
                {
                case DEPOSIT:
                    cout << "Enter Account Id :";
                    cin >> accId;
                    for (int i = 0; i < accountvector.size(); i++)
                    {
                        if (accountvector.at(i)->getId() == accId)
                        {
                            cout << "Enter amount to deposit =";
                            cin >> amount;
                            accountvector.at(i)->deposit(amount);
                            cout << "Updated Amount:" << accountvector.at(i)->getBalance() << endl;
                        }
                    }
                    break;
                case WITHDRAW:
                    try
                    {
                        cout << "Enter Account Id :";
                        cin >> accId;
                        for (int i = 0; i < accountvector.size(); i++)
                        {
                            if (accountvector.at(i)->getId() == accId)
                            {
                                cout << "Enter amount to withdraw=";
                                cin >> amount;
                                accountvector.at(i)->withdraw(amount);
                                cout << "Updated Amount:" << accountvector.at(i)->getBalance() << endl;
                            }
                        }
                    }
                    catch (Insufficient_fundsException e)
                    {
                        e.display();
                    }
                    break;
                case CHECK_BALANCE:
                    cout << "Enter Account Id :";
                    cin >> accId;
                    for (int i = 0; i < accountvector.size(); i++)
                    {
                        if (accountvector.at(i)->getId() == accId)
                        {
                            cout << "Balance :" << accountvector.at(i)->getBalance() << endl;
                        }
                    }
                    break;
                default:
                    cout << "Enter valid choice!!" << endl;
                    break;
                }
            }
        }
        break;
        default:
            cout << "Enter valid choice!!!" << endl;
            break;
        }
    }
    // releasing memory
    for (int i = 0; i < accountvector.size(); i++)
    {
        delete accountvector.at(i);
    }
    cout << "Thank you for using!" << endl;
}
