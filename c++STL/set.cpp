#include <set>
#include <iostream>
using namespace std;


int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(3);

    for(auto it : s){
        cout << it << " ";
    }
    cout << endl;
    auto itr = s.find(3);
    cout << *itr << endl;

    auto it = s.find(6);
    if(it == s.end()){
        cout << "Element not found" << endl;
    } else {
        cout << *it << endl;
    }

    s.erase(itr); //erase by iterator
    s.erase(2); //erase by value
    for(auto it : s){
        cout << it << " ";
    }
    cout << endl;

    cout << s.count(2)<<endl;

    s.insert(8);
    s.insert(7);

    for(auto it : s){
        cout << it << " ";
    }
    cout << endl;

    auto it1 = s.find(4);
    auto it2 = s.find(8);
    s.erase(it1, it2);
    for(auto it : s){
        cout << it << " ";
    }
    cout << endl;

    s.insert(2);
    s.insert(4);

    for(auto it : s){
        cout << it << " ";
    }
    cout << endl;

   auto iter =   s.lower_bound(2);
   cout  << *iter << endl; // returns the first element that is not less than 3

   auto iter1 = s.upper_bound(4);
    cout << *iter1 << endl; // returns the first element that is greater than 3
}