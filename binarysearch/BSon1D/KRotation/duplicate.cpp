#include <iostream>
#include <vector>
#include <climits>
using namespace std;

  int findKRotationdup(vector<int>& nums) {
         int low = 0, high = nums.size() - 1;
        int mini = INT_MAX;
        int index = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            
            if(nums[mid] < mini){
             mini = nums[mid];
             index = mid;
            }
            
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low = low + 1;
                high = high - 1;
                continue;
            }

            if (nums[low] <= nums[mid]) {
               if (nums[low] < mini) {
                index = low;
                mini = nums[low];
            }
                low = mid + 1;
            } 
            
            else {
                if (nums[mid] < mini) {
                index = mid;
                mini = nums[mid];
            }

                high = mid - 1;
            }
        }
        return index;
    }

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 0,0,1, 2, 3};
    int ans = findKRotationdup(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
}