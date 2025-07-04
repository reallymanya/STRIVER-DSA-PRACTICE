#include <iostream>
#include <vector>
#include <map>
using namespace std;

// when there is positive negative and zeroes

/*
https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_5713505?leftPanelTabValue=PROBLEM*/


int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    map<long long, int> mpp;
    long long sum = 0;
    int maxlen = 0;
    for(int i = 0; i<nums.size();i++){
        sum += nums[i];
        if(sum == k){
            maxlen = max(maxlen,i+1);
        }
        long long rem = sum - k;
        if(mpp.find(rem) != mpp.end()){
            int len = i - mpp[rem];
            maxlen = max(maxlen,len);
        }
        if(mpp.find(sum) == mpp.end())
        mpp[sum] = i;
    }
    return maxlen;
}

int main(){
    vector <int> num = {2,0,0,0,3};
    int k = 3;
    cout << getLongestSubarray(num,k);
}