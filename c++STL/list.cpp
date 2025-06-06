#include <iostream>
#include <list>
using namespace std;

void lists(){
    list<int> l;
    l.push_back(2);
    l.emplace_back(4);

    l.push_front(5);
    l.emplace_front(6);

    //rest fn same as vector
    //begin,end,clear,rend,clear,insert,size,swap

    for(auto it : l){
        cout << it << " ";
    }
cout << endl;
l.erase(l.begin());
    for(auto it : l){
        cout << it << " ";
    }


}

int main(){
    lists();
    return 0;
}