#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> s;
    s.push(1);
    s.emplace(2);
    s.push(3);
    s.push(5);
    s.pop();
    cout << s.top()<<endl;
    cout << s.size()<<endl;
    cout << s.empty() << endl;

    stack<int> s1;
    s1.push(4);
    s1.emplace(5);
    s1.swap(s);
    
    //printing 
    while (!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
}