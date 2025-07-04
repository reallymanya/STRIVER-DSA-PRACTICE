/* Given a non-empty array of integers nums, every element appears
twice except for one. Find that single one.*/

/*You must implement a solution with a linear 
runtime complexity and use only constant extra space.*/

//rest kind of solutions in arrays->easy->

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        for(int i = 0; i<n;i++){
            xorr = xorr ^ nums[i];
        }
        return xorr;
    }


int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Single number: " << singleNumber(nums) << endl;
    return 0;
}
