#include <iostream>
using namespace std;

class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() {}

    void push(int x) { s1.push(x); }

    int pop() {
        if (s2.empty()) {
            while (s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }

    int peek() {
        if (s2.empty()) {
            while (s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
       return s1.empty() && s2.empty();
    }

    int size() {
    return (s1.size() + s2.size()); 
  }

};

int main() {
  MyQueue q;
  q.push(3);
  q.push(4);
  cout << "The element poped is " << q.pop() << endl;
  q.push(5);
  cout << "The top of the queue is " << q.peek() << endl;
  cout << "The size of the queue is " << q.size() << endl;

}