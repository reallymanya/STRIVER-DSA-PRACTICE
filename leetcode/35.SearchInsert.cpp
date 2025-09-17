#include <iostream>
#include <vector>
using namespace std;

 int searchInsert(vector<int>& nums, int target) {
    int n = nums.size(); 
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1; 
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    int ind = searchInsert(arr, x);
    cout << "The index is: " << ind << "\n";
    return 0;
}
