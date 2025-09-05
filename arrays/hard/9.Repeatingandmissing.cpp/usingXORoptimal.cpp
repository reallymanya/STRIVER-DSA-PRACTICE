#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    int n = a.size();

    //Step 1: Find XOR of all elements:
    int xr = 0;
    for(int i = 0; i<n;i++){
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

     //Step 2: Find the differentiating bit number:
    int bit = 0;
    while(1){
        if((xr & (1<<bit)) != 0){
            break;
        }
        bit++;
        
    }

    int zero = 0;
    int one = 0;
    for(int i = 0; i<n;i++){
        if((a[i] & (1 << bit)) != 0){
            //part of 1 group:
            one = one ^ a[i];
        } else {
             //part of 0 group:
            zero = zero ^ a[i];
        }
    }

    for(int i = 1; i<=n;i++){
        if((i & (1 << bit)) != 0){
             //part of 1 group:
            one = one ^ i;
        } else {
             //part of 0 group:
            zero = zero ^ i;
        }
    }

    // Last step: Identify the numbers:
    int cnt = 0;
    for(int i = 0; i<n;i++){
        if(a[i]  == zero){
        cnt++;
        }
    }
        if(cnt == 2){
            return {zero,one};
        }else{
            return {one,zero};
        }
    
}


int main(){
     vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}