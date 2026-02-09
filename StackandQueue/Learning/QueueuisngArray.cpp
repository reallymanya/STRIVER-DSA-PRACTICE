#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int start, end, currSize, maxSize;

public:
    Queue()
    {
        maxSize = 16;
        arr = new int[16];
        start = -1;
        end = -1;
        currSize = 0;
    }

    Queue(int maxSize)
    {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    void push(int x)
    {
        if (currSize == maxSize)
        {
            cout << "queue is full" << endl;
            return;
        }

        if (currSize == 0)
        {
            start = 0;
            end = 0;
            arr[end] = x;
            currSize += 1;
        }
        else
            end = (end + 1) % maxSize;
            arr[end] = x;
            currSize += 1;
    }

    int pop()
    {
        if (currSize == 0)
        {
            cout << "queue empty" << endl;
            return -1;
        }

        int popped = arr[start];

        if (currSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % maxSize;
            currSize--;
        }
        return popped;
    }

    int top()
    {
        if (currSize == 0)
        {
            cout << "queue empty";
            return -1;
        }

        return arr[start];
    }

    int size()
    {
        return currSize;
    }
};

int main()
{
    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout << "The peek of the queue before deleting any element " << q.top() << endl;
    cout << "The size of the queue before deletion " << q.size() << endl;
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element " << q.top() << endl;
    cout << "The size of the queue after deleting an element " << q.size() << endl;

    return 0;
}