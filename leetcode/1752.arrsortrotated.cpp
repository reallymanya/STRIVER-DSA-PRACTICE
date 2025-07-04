#include <iostream>
using namespace std;

bool check(vector<int> &nums){
    int n = nums.size();
    int count = 0;
    for(int i = 0; i<n;i++){
            if(nums[i] > nums[(i+1)%n]){
                count++;
            }
        }
        return count<=1;
    }

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    if (check(nums)) {
        cout << "Array is sorted and rotated." << endl;
    } else {
        cout << "Array is not sorted and rotated." << endl;
    }
    return 0;
}
