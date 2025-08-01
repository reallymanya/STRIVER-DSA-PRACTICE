#include <iostream>
#include <vector>
using namespace std;

    void recurPermute(int index, vector<int>& nums, vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);                         // place i-th element at the index
            recurPermute(index + 1, nums, ans);                // generate all permutations for next index
            swap(nums[index], nums[i]);                         // backtrack to restore original state
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }


    int main(){
        vector<int> nums = {1, 2, 3}; // Example input
        vector<vector<int>> result = permute(nums);

        for (const auto& perm : result) {
            for (int num : perm) {
                cout << num << " ";
            }
            cout << endl;
        }
        return 0;
    }