#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(3);
    dq.emplace_front(4);
for(auto it : dq){
        cout << it << " ";
    }
cout << endl;

    dq.pop_back();
    dq.pop_front();

    for(auto it : dq){
        cout << it << " ";
    }
cout << endl;

dq.push_back(5);
cout << dq.front()<< endl;
cout << dq.back()<< endl;
}