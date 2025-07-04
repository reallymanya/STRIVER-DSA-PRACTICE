#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;    

void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int j = -1;
        for(int i = 0; i<size;i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }
        
        if(j == -1){
            return;
        }

        for(int i = j+1;i<size;i++){
            if(nums[i] != 0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);                    

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }           

    moveZeroes(nums);       
    cout << "Array after moving all 0s to the end: ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }           
    cout << endl;
    return 0;
}