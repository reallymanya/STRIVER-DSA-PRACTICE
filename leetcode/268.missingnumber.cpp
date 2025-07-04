
#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int size = nums.size();
    int xor1 = 0;
    int xor2 = 0;
    for(int i = 0; i < size; i++) {
        xor2 = xor2 ^ nums[i];
        xor1 = xor1 ^ i;
    }
    xor1 = xor1 ^ size;
    return xor1 ^ xor2;
}

int main() {
   vector<int> nums = {3, 0, 1};
   cout << "Missing number: " << missingNumber(nums) <<endl;
    return 0;
}
