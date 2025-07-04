#include <iostream>
#include <algorithm>
using namespace std;

 void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k%size;
       reverse(nums.begin(),nums.begin()+size-k);
       reverse(nums.begin()+size-k,nums.end());
       reverse(nums.begin(),nums.end());
    }

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3; // Number of positions
    rotate(nums, k);
    cout << "Array after rotation: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";                                                             
    }
    cout << endl;
    return 0;
}   