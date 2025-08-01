#include <iostream>
#include <vector>
using namespace std;

//leetcode sol {-2} = -2
 int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, maxi = INT_MIN;
    for(int i = 0; i<n;i++){
        sum += nums[i];

        if(sum > maxi){
            maxi = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    return maxi;
    }

//for edge case with empty arr and  when all nrgative, ans should be 0 
long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long sum = 0, maxi = INT_MIN;
    for(int i = 0; i<n;i++){
        sum += arr[i];

        if(sum > maxi){
            maxi = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    if(maxi < 0){
        maxi = 0;
    }
    return maxi;
}

int main(){
    vector<int> a = {-2,-3,4,-1,-2,1,5,3};
    cout << maxSubArray(a);
cout << endl;

    vector<int> b = {-2,-3,-3};
    int n = 3;
    cout << maxSubArray(b);
    cout << endl;
    cout << maxSubarraySum(b,n);
}