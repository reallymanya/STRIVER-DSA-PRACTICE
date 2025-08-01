#include <iostream>
#include <vector>
using namespace std;


int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int preSum, cnt = 0;
        for(int i = 0; i<nums.size();i++){
            preSum += nums[i];
            int remove = preSum - k;
            cnt += mpp[remove];
            mpp[preSum] += 1;
        }
        return cnt;
    }

int main(){
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = subarraySum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}