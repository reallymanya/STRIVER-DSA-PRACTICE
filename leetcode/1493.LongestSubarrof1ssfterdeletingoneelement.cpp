#include <iostream>
#include <vector>
using namespace std;

int longestSubarray(vector<int>& nums) {
        int prev_cnt = 0, curr_cnt = 0, res = 0;

        for (int num : nums) {
            if (num == 1) {
                curr_cnt++;
            } else {
                prev_cnt = curr_cnt;
                curr_cnt = 0;
            }
            res = max(res, prev_cnt + curr_cnt);
        }
        
        if (res == nums.size()) return res - 1;
        return res;
    }

int main(){
    vector<int> arr = {0,1,1,1,0,1,1,0,1};
    cout << longestSubarray(arr);
}