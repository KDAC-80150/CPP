#include <iostream>

using namespace std;

//Function to calculate factorial return factorial of number
int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * (factorial(n - 1));
}

int main()
{
    int number;
    //take number from user and pass it to the factorial function as an arugument
    cout << "Enter number :";
    cin >> number;

    try
    {
        //check if number is equal to 0 or less than 0 throw an exception
        if (number <= 0)
        {
            throw 3;
        }
        //if not ,then calculate and print on screen
        cout << "Factorial number of " << number << " is" << factorial(number) << endl;
    }
    catch (int error)
    {
        cout << "Cannot find factorial for negative or 0!!!" << endl;
    }
}