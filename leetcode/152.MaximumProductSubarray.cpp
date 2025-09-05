#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) {
         int n = nums.size(); 

    int pre = 1, suff = 1;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= nums[i];
        suff *= nums[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
    }
    
int main(){
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProduct(nums);
    return 0;
}