#include "bits/stdc++.h"
using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(8);
    pq.push(5);
    pq.push(10);
    pq.push(9);
    pq.push(20);

    cout << pq.top() << endl;

    pq.pop();

    cout << pq.top() << endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> mpq;
   mpq.push(8);
    mpq.push(5);
    mpq.push(10);
    mpq.push(9);
    mpq.push(20);

    cout << mpq.top() << endl;

    mpq.pop();

    cout << mpq.top() << endl;

    //size,swap,empty,clear same as before
}