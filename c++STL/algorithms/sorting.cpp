#include "bits/stdc++.h"
using namespace std;

//SORTING 
void algo(){
    int arr[] =  {5, 2, 8, 1, 3};
    sort(arr,arr+5);
for(auto i : arr){
    cout << i << " ";
}
cout << endl;

vector<int> v = {7, 2, 8, 9, 4};
    sort(v.begin(), v.end());
for(auto i : v){
    cout << i << " ";       
}
cout << endl;


int a2[] = {2, 3, 9, 8};
sort(a2+2, a2+ 4);
for(auto i : a2){
    cout << i << " ";
}
cout << endl;

//SORTING IN DESCENDING

sort(arr, arr+5);
reverse(arr, arr+5);
sort(arr, arr+5, greater<int>());
for(auto i : arr){
    cout << i << " ";
}
cout << endl;

//custom sorting

pair<int, int> a[] = {{1,2}, {2,1}, {4,1}};
//sort it acc to second element
//if sec element is same then sort
//acc to first element but in dec order
    sort(a, a+3, [](pair<int, int> p1, pair<int, int> p2){
        if(p1.second < p2.second) return true;
        if(p1.second > p2.second) return false;
        if(p1.first > p2.first) return true;
        return false;
    });
for(auto i : a){
        cout << i.first << " " << i.second << " ";
    }

    //COUNTING SET BITS
    int num = 7;
    int cnt = __builtin_popcount(num); //counts number of set bits in binary representation

    long long num1 = 1000000000000;
    long long cnt1 = __builtin_popcountll(num1); //counts number of set bits in binary representation for long long

//PERMUTATIONS
string s = "123";
do{
    cout << s << endl;
}while(next_permutation(s.begin(), s.end()));

//MIN AND MAX 
int maxi = *max_element(arr, arr+5); //finds max element in array
int mini = *min_element(arr, arr+5); //finds min element in array
cout << "Max: " << maxi << ", Min: " << mini << endl;

}
int main(){
    algo();
    return 0;
}