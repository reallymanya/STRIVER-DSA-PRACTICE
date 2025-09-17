#include <iostream>
#include <vector>
#include <climits>
using namespace std;

  int findMin(vector<int>& nums) {
         int low = 0, high = nums.size() - 1;
        int mini = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;

             mini = min(mini, nums[mid]);
             
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low = low + 1;
                high = high - 1;
                continue;
            }

            if (nums[low] <= nums[mid]) {
                mini = min(mini, nums[low]);
                low = mid + 1;
            } else {
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }


int main()
{
    vector<int> arr = {4, 5, 6, 7, 0,0,0, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}