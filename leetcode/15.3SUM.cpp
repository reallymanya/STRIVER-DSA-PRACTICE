#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
         vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && nums[i] == nums[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    return ans;
    }
    
int main(){
     vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(arr);

    cout << "Triplets that sum to 0 are:\n";
    for (auto &triplet : result) {
        cout << "[ ";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}