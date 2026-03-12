#include <iostream>
using namespace std;


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0,zeroes = 0, maxlen = 0;

        while(r < nums.size()){
            if(nums[r] == 0)
                zeroes++;
            
            while(zeroes > k){
                if(nums[l] == 0) zeroes--;
                l++;
            }

            maxlen = max(maxlen,r - l + 1);
            r++;
        }
        return maxlen;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    // Output the result
    cout << sol.longestOnes(nums, k) << endl;
    return 0;
}