#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
    int size;
    int top;
    T *arr;

public:
    Stack() : size(5), top(0)
    {
        arr = new T[size];
    }

    void push(T element)
    {
        if (isFull())
            cout << "Stack is full" << endl;
        else
        {
            arr[top] = element;
            top++;
        }
    }

    bool isFull()
    {
        if (top == size)
            return true;
        return false;
    }

    void pop()
    {
        if (isEmpty())
            cout << "Stack is empty!!!" << endl;
        else
        {
            // arr[top]=0;
            --top;
        }
    }

    bool isEmpty()
    {
        if (top == 0)
            return true;
        return false;
    }

    T peek()
    {
        return arr[top - 1];
    }

    void displayStack()
    {
        int trav = top - 1;
        while (trav >= 0)
        {
            cout << arr[trav] << endl;
            trav--;
        }
    }
    ~Stack()
    {
        delete[] arr;
    }
};

class Box
{
private:
    int length;
    int breadth;
    int height;

public:
    Box() : length(1), breadth(1), height(1)
    {
    }
    Box(int length, int breadth, int height)
    {
        this->breadth = breadth;
        this->length = length;
        this->height = height;
    }
    void calculateVolume()
    {
        cout << "Volume:" << this->length * this->breadth * this->height << endl;
    }
};

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.displayStack();

    Stack<double> s1;
    s1.push(1.2);
    s1.push(2.3);
    s1.push(3.4);
    s1.push(4.5);
    s1.push(5.6);
    s1.displayStack();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    cout << "After poping" << endl;
    s1.displayStack();

    Stack<Box> b;
    b.push(Box(2, 2, 2));
    b.push(Box(3, 3, 3));
    b.push(Box(4, 4, 4));
    b.push(Box(5, 5, 5));
    b.push(Box(6, 6, 6));

    b.peek().calculateVolume();
    b.pop();
    b.peek().calculateVolume();
    b.pop();
    b.peek().calculateVolume();
    b.pop();
    b.peek().calculateVolume();
    b.pop();
    b.peek().calculateVolume();
    b.pop();
    b.peek().calculateVolume();
    b.pop();
}