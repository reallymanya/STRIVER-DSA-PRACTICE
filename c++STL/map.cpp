#include "bits/stdc++.h"
using namespace std;

void explainMap(){
    map<int, int> mp;
    map<int, pair<int, int>> mpp;
    map<pair<int,int>, int> mp1;

    mp[1] = 2;
    mp.emplace(3,4);
    mp.insert({2,5});

    for(auto it : mp)
{
    cout << it.first << " " << it.second << endl;
}  
cout << endl;
  mp1[{3,4}] = 10;

  cout << mp[1]<<endl;

  auto it = mp.find(2);
    cout << it->first << " " << it->second << endl;

    auto it1 = mp.find(6); // points to end if not found

    auto it2 = mp.lower_bound(3); // points to first element >= 2
  cout << it2->first << " "<< it2->second << endl;

  auto it3 = mp.upper_bound(2); // points to first element > 2
  cout << it3->first << " "<< it3->second << endl;

}
int main(){
    explainMap();
    return 0;
}