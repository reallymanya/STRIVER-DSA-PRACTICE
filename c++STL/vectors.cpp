#include "bits/stdc++.h"
using namespace std;

void explainvector(){
    vector <int> v;
    v.push_back(1);
    v.emplace_back(2);
    v.push_back(3);
    v.push_back(4);

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    vector<pair<int,int>> vp;
    vp.push_back({1,2});
    vp.emplace_back(3,4); //automatically creates a pair

    vector<int> vv (5,100);
   vector <int> v1(vv);

   //iteration
   vector<int>::iterator it = v.begin();
   it = it+2;
   cout << *(it)<<endl;

   vector<int>::iterator it1 = v.end(); //points to the element after the last element
   vector<int>::reverse_iterator it2 = v.rend(); //before first position
   
   vector<int>::reverse_iterator it3 = v.rbegin(); //points to the last element
   it3++;
   cout << *(it3) << endl; // in reverse 

   cout << v[0] << " " << v.at(0) << endl;
    cout << v.front() << " " << v.back() << endl; //first and last element

    //printing 
    //iterator
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    // auto
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    //for each
    for(auto it : v){
        cout << it << " ";
    }
cout << endl;

}

void furhter(){
    //erase vectors
    vector <int> v = {3,4,5,6,7,8,9};
    v.erase(v.begin() + 1, v.begin() + 5);
    for(auto it : v){
        cout << it << " ";
    }
cout << endl;
    //insertion
vector <int> v1(2,100);
v1.insert(v1.begin(),300);
v1.insert(v1.begin()+1,5);
v1.insert(v1.begin()+1,2,10);
 for(auto it : v1){
        cout << it << " ";
    }
cout << endl;

//copy

vector<int> copy(2,50);
v1.insert(v1.begin(), copy.begin(), copy.end());
for(auto it : v1){
        cout << it << " ";
    }
cout << endl;


//size
cout << v1.size()<<endl;

//pop_back
v1.pop_back();

//swap two vectors

v1.swap(v);
for(auto it : v1){
        cout << it << " ";
    }
cout << endl;

//clear  clears entire vector

v1.clear();

cout << v1.empty() << endl; //returns 1 if empty, 0 otherwise

}

int main(){
    explainvector();
    furhter();

}