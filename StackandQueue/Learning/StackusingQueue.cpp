#include <iostream>
using namespace std;

class MyStack
{
    queue<int> q;

public:
    MyStack() {}

    void push(int x)
    {
        int size = q.size();
        q.push(x);

        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int n = q.front();
        q.pop();
        return n;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }
};

int main()
{
    MyStack s;
    s.push(3);
    s.push(2);
    s.push(4);
    s.push(1);
    cout << "Top of the stack: " << s.top() << endl;
    cout << "The deleted element is: " << s.pop() << endl;
    cout << "Top of the stack after removing element: " << s.top() << endl;
}