//next_permutation : find next lexicographically greater permutation

#include <iostream>
#include <vector>
using namespace std;

vector<int> nextPermutation(vector<int>& nums) {
int index = -1;
int size = nums.size();
for(int i = size-2; i>=0;i--){
    if(nums[i] < nums[i+1]){
        index = i;
        break;
    }
}

if(index == -1){
    reverse(nums.begin(), nums.end());
    return nums;
}
for(int i = size-1; i>index;i--){
    if(nums[i] > nums[index]){
        swap(nums[i],nums[index]);
        break;
    }
}
reverse(nums.begin()+index+1, nums.end());
return nums;
 }



int main(){
    vector<int> nums = {2,1,5,4,3,0,0};
    vector<int> ans = nextPermutation(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
}