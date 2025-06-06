#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(1);
    q.emplace(2);
    q.push(3);
    q.push(4);

    q.back() += 5;

    cout << q.back() << endl;
    cout << q.front() << endl;
    q.pop();

    cout << q.front() << endl;


// To remove the last element from the queue
queue <int> temp;
while (q.size() > 1){
    temp.push(q.front());
    q.pop();
}
q.pop();

q = temp;
while(!q.empty()){
    cout << q.front() << " ";
    q.pop();

}
}