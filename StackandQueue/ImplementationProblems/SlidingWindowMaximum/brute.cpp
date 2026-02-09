#include <iostream>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

vector<int> rs;

for(int i = 0; i<nums.size() - k;i++){
    int maxi = nums[i];

    for(int j = i; j< i + k;j++){
        maxi = max(maxi,nums[j]);
    }

    rs.push_back(maxi);
}

return rs;
}

int main() {
   
    vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};
    int k = 3;

    vector<int> ans = maxSlidingWindow(arr, k);

    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}