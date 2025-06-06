#include "bits/stdc++.h"
using namespace std;

void explainpairs(){
    pair <int, int> p1 = {2,3};
    cout << p1.first << " " << p1.second << endl;

    pair <int, pair<int, int>> p2 = {1, {2,3}};
    cout << p2.second.first << " " << p2.second.second << endl;

    pair <int, int> arr[] = {{1,2}, {3,4}, {5,6}};
    for(int i = 0; i<3;i++){
        cout << arr[i].first << " " << arr[i].second << endl;
    }
    cout << arr[1].second << endl;
}

int main(){
    explainpairs();
}