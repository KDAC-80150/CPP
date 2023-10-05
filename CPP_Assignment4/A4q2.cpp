#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *stackArray;

public:
    // Default constructor
    Stack()
    {
        size = 5; // Default size is 5
        stackArray = new int[size];
        top = -1;
    }

    // Parameterized constructor
    Stack(int stackSize)
    {
        size = stackSize;
        stackArray = new int[size];
        top = -1;
    }

    ~Stack()
    {
        delete[] stackArray;
    }

    void push(int item)
    {
        if (!isFull())
        {
            stackArray[++top] = item;
        }
        else
        {
            cout << "Stack is full. Cannot push element." << endl;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            top--;
        }
        else
        {
            cout << "Stack is empty. Cannot pop element." << endl;
        }
    }

    int peek() const
    {
        if (!isEmpty())
        {
            return stackArray[top];
        }
        throw runtime_error("Stack is empty. Cannot peek.");
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    bool isFull() const
    {
        return top == size - 1;
    }

    void print() const
    {
        if (!isEmpty())
        {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++)
            {
                cout << stackArray[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Stack is empty." << endl;
        }
    }
};

int main()
{
    // Create a stack of integers with a size of 3
    Stack intStack(3);

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    cout << "Top element: " << intStack.peek() << endl;
    intStack.print();

    intStack.pop();
    cout << "After popping one element:" << endl;
    intStack.print();

    return 0;
}
