#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target) {
  
    int low = 0;
    int high = nums.size() - 1;
    while(low <=high){
        int mid = (low+high)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = search(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    return 0;
}