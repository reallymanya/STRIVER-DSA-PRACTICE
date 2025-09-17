#include <iostream>
#include <vector>
using namespace std;


int lowerBound(vector<int>&nums, int n, int x){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high){
        int mid  = (low + high)/2;
       if(nums[mid] >= x){
        ans = mid;
        high = mid -1;
       }else{
        low = mid + 1;
       }
    }
    return ans;
}

int upperBound(vector<int>&nums, int n, int x){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high){
        int mid  = (low + high)/2;
       if(nums[mid] > x){
        ans = mid;
        high = mid -1;
       }else{
        low = mid + 1;
       }
    }
    return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
      int n = nums.size();
      int lb = lowerBound(nums,n,target);
      if(lb == n || nums[lb] != target)
      return {-1,-1};

      return {lb, upperBound(nums,n,target) - 1};
    }
int main() {
  vector<int> arr = {1,2,3,3,3,4,5,6};
    int key = 3;

vector<int> ans = searchRange(arr, key);

cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}