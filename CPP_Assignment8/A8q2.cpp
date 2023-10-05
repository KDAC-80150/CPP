#include <iostream>

using namespace std;

// Stack implementation using dynamic array
class Stack
{
private:
    int size, top;
    int *sPtr;

public:
    // Default constructor size=5,top=0
    Stack() : size(5), top(-1)
    {
        this->sPtr = new int[size];
    }
    // paramaterized Constructor
    Stack(int size)
    {
        this->sPtr = new int[size];
        this->size = size;
        this->top = -1;
    }

     // Copy Constructor
    Stack(Stack& other)
    {
        this->size = other.size;
        this->top = other.top;
        this->sPtr = new int[size];
        for (int i = 0; i <= top; i++)
        {
            this->sPtr[i] = other.sPtr[i];
        }
    }

    // Overloading assignment operator (=)
    Stack& operator=(Stack& other)
    {
        if (this == &other)
            return *this;

        delete[] this->sPtr;

        this->size = other.size;
        this->top = other.top;
        this->sPtr = new int[size];
        for (int i = 0; i <= top; i++)
        {
            this->sPtr[i] = other.sPtr[i];
        }

        return *this;
    }

    // Function to check for empty or not
    bool isEmpty()
    {
        if (this->top == -1)
            return true;
        return false;
    }

    // Function to check for stack full or not
    bool isFull()
    {
        if (this->top == (this->size - 1))
            return true;
        return false;
    }

    void push(int val)
    {
        // check if stack is full
        if (isFull() == 1)
            cout << "Stack is Full!" << endl;
        // if not then push the element in the array and increment the top by 1
        else
        {
            this->top++;
            this->sPtr[top] = val;
        }
    }

    // to remove the element from the Stack
    void pop()
    {
        // check is stack is empty
        if (isEmpty() == 1)
            cout << "Stack is Empty!" << endl;
        // Else pop the element
        else
        {
            cout << "Element poped=" << sPtr[top] << endl;
            sPtr[top] = 0;
            top--;
        }
    }

    // to get the top element from the Stack
    void peek()
    {
        if(isEmpty()==1)
            cout<<"Stack is Empty!";
        else
            cout << "Top element is:" << sPtr[top] << endl;
    }

    // Function to print the Stack
    void print()
    {
        int val = top;
        cout << "--Stack--" << endl;
        while (val >= 0)
        {
            cout << sPtr[val] << endl;
            val--;
        }
    }

    ~Stack()
    {
        delete[] sPtr;
    }
};

int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    Stack s2;
    s2=s1;
    s2.print();
    s2.push(4);
    s2.push(5);
    s2.print();
    s2.push(6);
    s1.push(4);
    s1.print();
    s2=s1;
    s2.print();
    Stack s3=s2;
    s3.peek();
}


