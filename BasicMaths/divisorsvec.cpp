#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void printdivisors(int n){
    vector <int> ls;
    //other way of sqrt(n)
    // i*i <= n
    // 6 * 6 <= 36
    // 7 * 7 !<= 36

    //tc = O(sqrt n)
    for(int i = 1; i<=sqrt(n); i++){
        if(n%i == 0){
            ls.push_back(i);

        if(i != (n/i)){
            ls.push_back(n/i);
        }
    }
}
//O(n of factors * log(n of factors))
sort(ls.begin(),ls.end());
for(auto it : ls){
    cout << it << " ";
}
}
int main(){
    int n;
    cin >> n;
    printdivisors(n);
}

