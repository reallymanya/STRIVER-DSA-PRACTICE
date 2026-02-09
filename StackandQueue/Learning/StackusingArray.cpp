#include <iostream>
using namespace std;

class Stack
{
    int size;
    int *arr;
    int top;

public:
    Stack()
    {
        top = -1;
        size = 10;
        arr = new int[size];
    }

    void push(int x)
    {
        if (top == size - 1)
        {
            cout << "arr full";
            return;
        }
        top++;
        arr[top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "empty ";
            return -1;
        }
        int x = arr[top];
        top--;
        return x;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "Stack is empty! No top element." << endl;
            return -1;
        }
        return arr[top];
    }

    int Size()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }
};

int main()
{
    Stack s;
    s.push(6);
    s.push(3);
    s.push(7);
    cout << "Top of stack is before deleting any element " << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;

    return 0;
}