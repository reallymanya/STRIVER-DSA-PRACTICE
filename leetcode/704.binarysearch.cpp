#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(vector<int>& nums, int target) {
     sort(nums.begin(),nums.end());  
    
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid] < target)
            low = mid + 1;
        
        else
            high = mid - 1;
    }
    return -1;
    }


int main() {
    int n, target;          
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);

    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }       
    cout << "Enter the target element to search: ";
    cin >> target;  
    int result = search(nums, target);
    if(result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}