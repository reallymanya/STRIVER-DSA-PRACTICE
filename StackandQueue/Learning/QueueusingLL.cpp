#include <iostream>
using namespace std;

class QueueNode
{
public:
    int data;
    QueueNode *next;

    QueueNode(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

// Removed global start and end pointers

class Queue
{
private:
    QueueNode *start = nullptr;
    QueueNode *end = nullptr;

public:
    int size = 0;
    bool Empty();
    void Enqueue(int value); // insert at rear end
    void Dequeue();          // delete from front
    int Peek();

    int Size();
};

bool Queue ::Empty()
{
    return start == nullptr;
}
void Queue ::Enqueue(int x)
{
    QueueNode *temp = new QueueNode(x);

    if (start == nullptr)
    {
        start = end = temp;
    }
    else
    {
        end->next = temp;
        end = temp;
    }
    size++;
}

void Queue ::Dequeue()
{
    if (start == nullptr)
        cout << "Queue is Empty" << endl;

    else
    {
        QueueNode *Temp = start;
        start = start->next;
        delete Temp;
        size--;
        if (start == nullptr)
            end = nullptr;
    }
}

int Queue ::Peek()
{
    if (start == nullptr)
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    else
        return start->data;
}

int Queue ::Size()
{
    return size;
}

int main()

{
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Dequeue();
    cout << "The size of the Queue is " << Q.size << endl;
    cout << "The Peek element of the Queue is " << Q.Peek() << endl;
    return 0;
}
