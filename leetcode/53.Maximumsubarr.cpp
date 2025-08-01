#include <iostream>
#include <vector>
using namespace std;

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

int main(){
    vector<int> a = {-2,-3,4,-1,-2,1,5,3};
    cout << maxSubArray(a);
}