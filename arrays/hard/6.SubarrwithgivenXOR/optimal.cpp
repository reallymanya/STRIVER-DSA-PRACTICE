#include <bits/stdc++.h>
using namespace std;

//tc = O(nlogn)
//sc = O(1)

int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int n = a.size();
    int cnt = 0;
    int xr = 0;
    map<int,int> mpp;
    mpp[xr]++;

    for(int i = 0; i<n;i++){
        xr = xr ^ a[i];

        int x = xr ^ b;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

int main(){
     vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithSumK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}