#include <iostream>
using namespace std;

//this is a brute force approach
//optimal in leetcode 283


vector<int> movezeroes(vector<int>& nums, int n){
    vector<int> temp;
    for(int i = 0; i<n;i++){
        if(nums[i] != 0){
            temp.push_back(nums[i]);
        } 
    }

   for(int i =0; i<temp.size();i++){
    nums[i] = temp[i];
    
   }
   int size = temp.size();

   for(int i = size; i<n;i++){
    nums[i] = 0;
   }
   
   return nums;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    nums = movezeroes(nums, n);

    cout << "Array after moving all 0s to the end: ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

