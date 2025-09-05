#include <bits/stdc++.h>
using namespace std;

 vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
    // S - SN = x - y;
    //S2 - S2N 
        long long SN = (n*(n+1)) / 2;
        long long S2N = (n * (n+1) * (2*n+1)) / 6;
        long long S = 0, S2 = 0;
        for(int i = 0; i<n;i++){
            S += nums[i];
            S2 += (long long)nums[i] * (long long)nums[i];
        }
        long long val1 = S - SN; // x - y
        long long val2 = S2 - S2N;
        val2 = val2/val1; // x+y
        long long x = (val1 + val2) / 2;
        long long y = x - val1;
        return {(int)x, (int)y};
    }
    
int main(){
     vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findErrorNums(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}