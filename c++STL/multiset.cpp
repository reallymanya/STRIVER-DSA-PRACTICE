#include "bits/stdc++.h"
using namespace std;

void test_multiset(){
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);

   // ms.erase(1); //removes all 1's

    for(auto it : ms){
        cout << it << " ";
    }
    cout << endl;

    ms.erase(ms.find(1)); //removes one instance of 1
   ms.erase(ms.find(1), next(ms.find(1), 2));
   for(auto it : ms){
        cout << it << " ";
    }
    cout << endl;
}
int main(){
    test_multiset();
    return 0;
}